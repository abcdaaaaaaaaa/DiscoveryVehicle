import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
import plotly.graph_objects as go
from plotly.subplots import make_subplots
from datetime import datetime

df = pd.read_excel("Radioactive_Datas.xlsx")

times = df['Time'].to_numpy()
usvhr_values = df['Usv/hr'].to_numpy()
avg_values = df['Avg CPM'].to_numpy()
sdCPM_values = df['sdCPM'].to_numpy()
cpm_count_values = df['CPM Count'].to_numpy()

data_dict = {
    "Usv/hr": usvhr_values,
    "Avg": avg_values,
    "sdCPM": sdCPM_values,
    "CPM Count": cpm_count_values
}

now = datetime.now()
formatted = now.strftime("%Y-%m-%d %H:%M:%S")

print("")
print("")
print(formatted)
print("")
print("")

with open("DataReport.txt", "a") as f:
    f.write("\n")
    f.write("\n")
    f.write(formatted)
    f.write("\n")
    f.write("\n")
    f.write("\n")

with open("EstimationReport.txt", "a") as f:
    f.write("\n")
    f.write("\n")
    f.write(formatted)
    f.write("\n")
    f.write("\n")
    f.write("\n")
    
def exponential_decay_regression(t, y):
    mask = y > 0
    t_masked = t[mask].reshape(-1, 1)
    y_masked = y[mask]
    log_y = np.log(y_masked)
    model = LinearRegression()
    model.fit(t_masked, log_y)
    lambda_ = -model.coef_[0]
    ln_N0 = model.intercept_
    N0 = np.exp(ln_N0)
    def decay_func(time): return N0 * np.exp(-lambda_ * time)
    y_pred_log = model.predict(t_masked)
    ss_res = np.sum((log_y - y_pred_log) ** 2)
    ss_tot = np.sum((log_y - np.mean(log_y)) ** 2)
    r2 = 1 - ss_res / ss_tot
    return decay_func, r2

results_single = {}
for label, data in data_dict.items():
    decay_f, r2 = exponential_decay_regression(times, data)
    results_single[label] = (decay_f, r2)

y_multi = avg_values
mask = y_multi > 0
log_y_multi = np.log(y_multi[mask])
X_multi = np.vstack([
    times[mask],
    np.log(usvhr_values[mask]),
    np.log(sdCPM_values[mask]),
    np.log(cpm_count_values[mask])
]).T
multi_model = LinearRegression()
multi_model.fit(X_multi, log_y_multi)

def multi_decay(t, usvhr, sdCPM, cpm_count):
    X = np.array([t, np.log(usvhr), np.log(sdCPM), np.log(cpm_count)]).reshape(1, -1)
    return np.exp(multi_model.predict(X)[0])

t_fine = np.linspace(min(times), max(times), 200)

colors = {
    "Usv/hr": "#636EFA",
    "Avg": "#EF553B",
    "sdCPM": "#00CC96",
    "CPM Count": "#AB63FA",
    "Multi": "#FFA15A"
}

fig_2d = make_subplots(
    rows=2, cols=2,
    subplot_titles=["Usv/hr", "Avg", "sdCPM", "CPM Count"],
    vertical_spacing=0.15,
    horizontal_spacing=0.1
)

for i, (label, (decay_f, r2)) in enumerate(results_single.items(), start=1):
    row = 1 if i <= 2 else 2
    col = i if i <= 2 else i - 2
    fig_2d.add_trace(go.Scatter(
        x=times, y=data_dict[label], mode='markers', marker=dict(color=colors[label]),
        name=f"{label} Measurements", showlegend=(i==1)
    ), row=row, col=col)
    fig_2d.add_trace(go.Scatter(
        x=t_fine, y=decay_f(t_fine), mode='lines', line=dict(color=colors[label]),
        name=f"{label} Exponential Model", showlegend=False
    ), row=row, col=col)
    fig_2d.add_annotation(
        text=f"R² = {r2:.4f}", xref="x domain", yref="y domain", x=0.95, y=0.95,
        showarrow=False, row=row, col=col, font=dict(size=12, color=colors[label])
    )

avg_usvhr = np.mean(usvhr_values)
avg_sdCPM = np.mean(sdCPM_values)
avg_cpm_count = np.mean(cpm_count_values)
multi_pred = [multi_decay(t, avg_usvhr, avg_sdCPM, avg_cpm_count) for t in t_fine]

fig_2d.add_trace(go.Scatter(
    x=t_fine, y=multi_pred, mode='lines', line=dict(color=colors["Multi"], dash='dash'),
    name="Multivariate Model (Avg)", showlegend=True
), row=2, col=1)

fig_2d.update_layout(
    title=dict(text="Multidimensional Radioactive Decay Estimation"),
    template="plotly_dark",
    legend=dict(x=0.8, y=0.95)
)
fig_2d.update_xaxes(title_text="Time (w)", row=1, col=1)
fig_2d.update_xaxes(title_text="Time (w)", row=1, col=2)
fig_2d.update_xaxes(title_text="Time (w)", row=2, col=1)
fig_2d.update_xaxes(title_text="Time (w)", row=2, col=2)
fig_2d.update_yaxes(title_text="Usv/hr", row=1, col=1)
fig_2d.update_yaxes(title_text="Avg (CPM)", row=1, col=2)
fig_2d.update_yaxes(title_text="sdCPM", row=2, col=1)
fig_2d.update_yaxes(title_text="CPM Count", row=2, col=2)
fig_2d.write_html("2D_RadioactiveScience.html")

decay_usvhr, r2_usvhr = results_single["Usv/hr"]
decay_avg, r2_avg = results_single["Avg"]
decay_sdCPM, r2_sdCPM = results_single["sdCPM"]
decay_cpm, r2_cpm = results_single["CPM Count"]

future_times = np.linspace(min(times), max(times) * 2, 400)
predicted_avg = decay_avg(future_times)
predicted_cpm = decay_cpm(future_times)
predicted_sdCPM = decay_sdCPM(future_times)
predicted_usvhr = decay_usvhr(future_times)
marker_size = np.interp(sdCPM_values, (min(sdCPM_values), max(sdCPM_values)), (4, 15))

fig_3d = go.Figure()
fig_3d.add_trace(go.Scatter3d(
    x=times, y=cpm_count_values, z=avg_values, mode='markers',
    marker=dict(size=marker_size, color=usvhr_values, colorscale='Jet', colorbar=dict(title='Usv/hr', thickness=15)),
    hovertemplate="Time: %{x}<br>CPM Count: %{y}<br>Avg CPM: %{z}<br>sdCPM: %{marker.size:.2f}<br>Usv/hr: %{marker.color:.4f}",
    name='Real Datas'
))
fig_3d.add_trace(go.Scatter3d(
    x=future_times, y=predicted_cpm, z=predicted_avg, mode='lines',
    line=dict(color=predicted_usvhr, colorscale='Jet', width=5),
    hovertemplate="Time: %{x}<br>CPM Count: %{y:.2f}<br>Avg CPM: %{z:.2f}<br>Usv/hr: %{line.color:.4f}",
    name='Estimation Curves'
))
fig_3d.update_layout(
    title="Multidimensional Radioactive Decay Estimation",
    scene=dict(camera=dict(eye=dict(x=1.6, y=1.6, z=0.8)), xaxis_title='X: Time (w)', yaxis_title='Y: CPM Count', zaxis_title='Z: Avg CPM'),
    template='plotly_dark', margin=dict(t=50, b=50, l=50, r=50),
    legend=dict(x=0.01, y=0.95, bgcolor='rgba(0,0,0,0.5)', bordercolor='white', borderwidth=1, font=dict(size=12)),
    annotations=[dict(
        text=(f" R² Usv/hr = {r2_usvhr:.4f} <br> R² Avg = {r2_avg:.4f} <br> R² sdCPM = {r2_sdCPM:.4f} <br> R² CPM Count = {r2_cpm:.4f} "),
        showarrow=False, xref='paper', yref='paper', x=0.01, y=0.80, align='left',
        font=dict(size=12), bordercolor='white', borderwidth=1, bgcolor='black'
    )]
)
fig_3d.write_html("3D_RadioactiveScience.html", include_plotlyjs='cdn', full_html=True, auto_open=False)

fig_multi_y = go.Figure()
t_fine = np.linspace(min(times), max(times), 200)
fig_multi_y.add_trace(go.Scatter(x=times, y=usvhr_values, mode='markers', name='Usv/hr Measurements', yaxis='y1'))
fig_multi_y.add_trace(go.Scatter(x=t_fine, y=decay_usvhr(t_fine), mode='lines', name='Usv/hr Model', yaxis='y1'))
fig_multi_y.add_trace(go.Scatter(x=times, y=avg_values, mode='markers', name='Avg Measurements', yaxis='y2'))
fig_multi_y.add_trace(go.Scatter(x=t_fine, y=decay_avg(t_fine), mode='lines', name='Avg Model', yaxis='y2'))
fig_multi_y.add_trace(go.Scatter(x=times, y=sdCPM_values, mode='markers', name='sdCPM Measurements', yaxis='y3'))
fig_multi_y.add_trace(go.Scatter(x=t_fine, y=decay_sdCPM(t_fine), mode='lines', name='sdCPM Model', yaxis='y3'))
fig_multi_y.add_trace(go.Scatter(x=times, y=cpm_count_values, mode='markers', name='CPM Count Measurements', yaxis='y4'))
fig_multi_y.add_trace(go.Scatter(x=t_fine, y=decay_cpm(t_fine), mode='lines', name='CPM Count Model', yaxis='y4'))

fig_multi_y.update_layout(
    title=dict(text="Multidimensional Radioactive Decay Estimation"),
    xaxis=dict(title='Time (w)'),
    yaxis=dict(title='Usv/hr', titlefont=dict(color='#1f77b4'), tickfont=dict(color='#1f77b4'), anchor='x', side='left', position=0.0),
    yaxis2=dict(title='Avg (CPM)', titlefont=dict(color='#ff7f0e'), tickfont=dict(color='#ff7f0e'), anchor='free', overlaying='y', side='right', position=1.0),
    yaxis3=dict(title='sdCPM', titlefont=dict(color='#2ca02c'), tickfont=dict(color='#2ca02c'), anchor='free', overlaying='y', side='left', position=0.15),
    yaxis4=dict(title='CPM Count', titlefont=dict(color='#d62728'), tickfont=dict(color='#d62728'), anchor='free', overlaying='y', side='right', position=0.85),
    legend=dict(x=0.5, y=1.1, orientation='h'), margin=dict(t=100, b=60, l=60, r=60), template='plotly_dark', autosize=True
)
fig_multi_y.add_annotation(text=f"R²={r2_usvhr:.4f}", xref="paper", yref="y domain", x=0.05, y=0.95, showarrow=False, font=dict(color='#1f77b4'))
fig_multi_y.add_annotation(text=f"R²={r2_avg:.4f}", xref="paper", yref="y domain", x=0.95, y=0.95, showarrow=False, font=dict(color='#ff7f0e'))
fig_multi_y.add_annotation(text=f"R²={r2_sdCPM:.4f}", xref="paper", yref="y domain", x=0.05, y=0.55, showarrow=False, font=dict(color='#2ca02c'))
fig_multi_y.add_annotation(text=f"R²={r2_cpm:.4f}", xref="paper", yref="y domain", x=0.95, y=0.55, showarrow=False, font=dict(color='#d62728'))
fig_multi_y.write_html("Multi_RadioactiveScience.html")

print(f"R²_Usv/hr={r2_usvhr:.4f} | R²_Avg (CPM)={r2_avg:.4f} | R²_sdCPM={r2_sdCPM:.4f} | R²_CPM Count={r2_cpm:.4f}\n")

for idx, t in enumerate(times):
    data = [
        ["Usv/hr", f"{usvhr_values[idx]:.4f}"],
        ["Avg (CPM)", f"{avg_values[idx]:.4f}"],
        ["sdCPM", f"{sdCPM_values[idx]:.4f}"],
        ["CPM Count", f"{cpm_count_values[idx]:.4f}"]
    ]
    df_table = pd.DataFrame(data, columns=[f"t={t:.4f}", "DecayValues"])
    print(df_table.to_string(index=False))
    print("")
    with open("DataReport.txt", "a") as f:
        f.write(df_table.to_string(index=False))
        f.write("\n")
        f.write("\n")

with open("DataReport.txt", "r+") as f:
    lines = f.readlines()
    f.seek(0)
    f.writelines(lines[:-1])
    f.truncate()

print("")
print(f"R²_Usv/hr={r2_usvhr:.4f} | R²_Avg (CPM)={r2_avg:.4f} | R²_sdCPM={r2_sdCPM:.4f} | R²_CPM Count={r2_cpm:.4f}\n")

for t in t_fine:
    data = [
        ["Usv/hr", f"{decay_usvhr(t):.4f}"],
        ["Avg (CPM)", f"{decay_avg(t):.4f}"],
        ["sdCPM", f"{decay_sdCPM(t):.4f}"],
        ["CPM Count", f"{decay_cpm(t):.4f}"]
    ]
    df_table = pd.DataFrame(data, columns=[f"t={t:.4f}", "DecayValues"])
    print(df_table.to_string(index=False))
    print("")
    with open("EstimationReport.txt", "a") as f:
        f.write(df_table.to_string(index=False))
        f.write("\n")
        f.write("\n")

with open("EstimationReport.txt", "r+") as f:
    lines = f.readlines()
    f.seek(0)
    f.writelines(lines[:-1])
    f.truncate()
