function red(data) {return('rgba(255, 26, 104,' + ' ' + String(data) + ')');}
function blue(data) {return('rgba(54, 162, 235,' + ' ' + String(data) + ')');}
function green(data) {return('rgba(75, 192, 192,' + ' ' + String(data) + ')');}
function lightpurple(data) {return('rgba(153, 102, 255,' + ' ' + String(data) + ')');}
function bluepurple(data) {return('rgba(0, 0, 255,' + ' ' + String(data) + ')');}
function earth(color){return([red(color), blue(color), green(color), lightpurple(color), bluepurple(color)])}

function hello(dot) {
  return {
    type: dot,
    data: {
      labels: ['CO2', 'TheoCO2', 'CH4', 'C2H5OH', 'CO'],
      datasets: [{
        label: 'MG811',
        backgroundColor: earth(0.2),
        data: [toplam4, toplam3, toplam5, toplam6, toplam7],
        borderColor: earth(1),
        borderWidth: 1
      }]
    },
    options: {
      indexAxis: 'y',
      scales: {
        y: {
          ticks: {
            beginAtZero: true
          }
        }
      }
    }
  };
}