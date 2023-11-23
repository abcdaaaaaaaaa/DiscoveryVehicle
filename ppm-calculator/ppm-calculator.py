from math import log10

def valueA(y, y0, x, x0):
    return round(log10(y/y0) / log10(x/x0), 4)

def valueB(y, AverageY, x, x0):
    return round(log10(AverageY) - valueA(y, y0, x, x0) * log10(x/2), 4)

def print_gas_table(gas_data):
    print("Gas    | a       | b")
    for gas, (a, b) in gas_data.items():
        print(f"{gas.ljust(7)}| {str(a).ljust(8)}| {str(b).ljust(7)}")

MQ_Model = input("Please define your MQ model like MQ-303A: ")

# Sorgulama için 'con' değişkeni
con = input("Does your sensor detect the same concentration range for all gases? (yes/no): ")

# x ve x0 değerlerini bir defa al
if con.lower() == 'yes':
    x = float(input(f"Define max ppm concentrate point of the graph for {MQ_Model} (x value): "))
    x0 = float(input(f"Define min ppm concentrate for {MQ_Model} (x0 value): "))

gas_data = {}

while True:
    Gas = input("Name of the gas like LPG (type 'stop' to exit): ")

    if Gas == 'stop':
        break

    if con.lower() == 'no':
        x = float(input(f"Define max ppm concentrate point of the graph for {Gas} (x value): "))
        x0 = float(input(f"Define min ppm concentrate for {Gas} (x0 value): "))

    y0 = float(input(f"Define first reference point of the graph for {Gas} (y0 value): "))
    y = float(input(f"Define final reference point of the graph for {Gas}  (y value): "))
    AverageY = float(input(f"Define your y value at medium ppm concentration for {Gas} (AverageY value): "))

    a = valueA(y, y0, x, x0)
    b = valueB(y, AverageY, x, x0)

    gas_data[Gas] = (a, b)

    print("Continue with another gas (yes/no)?")
    user_input = input()
    if user_input.lower() != 'yes':
        break

print("Your MQ Model is " + str(MQ_Model))
print_gas_table(gas_data)
