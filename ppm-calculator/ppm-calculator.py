from math import log10

def valueA(y, y0, x, x0):
    return round(log10(y/y0) / log10(x/x0), 4)

def valueB(y, AverageY, x, x0):
    return round(log10(AverageY) - valueA(y, y0, x, x0) * log10(x/2), 4)

def print_gas_table(gas_data):
    print("Gas    | a       | b")
    for gas, (a, b) in gas_data.items():
        print(f"{gas.ljust(7)}| {str(a).ljust(8)}| {str(b).ljust(7)}")

MQ_Model = input("please define your MQ model like MQ-303A: ")

gas_data = {}  

while True:
    Gas = input("name of the gas like LPG (type 'stop' to exit): ")

    if Gas == 'stop':
        break

    y0 = float(input(f"define first reference point of the graph for {Gas} (y0 value): "))
    y = float(input(f"define final reference point of the graph for {Gas}  (y value): "))
    x = float(input(f"define max ppm concentrate point of the graph for {Gas} (x value): "))
    x0 = float(input(f"define min ppm concentrate for {Gas} (x0 value): "))
    AverageY = float(input(f"define your y value at medium ppm concentration for {Gas} (AverageY value): "))

    a = valueA(y, y0, x, x0)
    b = valueB(y, AverageY, x, x0)

    gas_data[Gas] = (a, b)

    print("Continue with another gas (yes/no)?")
    user_input = input()
    if user_input.lower() != 'yes':
        break

print("Your MQ Model is " + str(MQ_Model))
print_gas_table(gas_data)
