import csv

data_list = []
data_number = 1

while True:
    print(f"Data {data_number}:")
    data = input("Data: ")
    h2 = input("H2: ")
    lpg = input("LPG: ")
    ch4 = input("CH4: ")
    co = input("CO: ")
    alcohol = input("Alcohol: ")
    propane = input("Propane: ")

    data_entry = {
        'Data': data,
        'H2': h2,
        'LPG': lpg,
        'CH4': ch4,
        'CO': co,
        'Alcohol': alcohol,
        'Propane': propane
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('MQ-6.csv', 'w', newline='') as file:
    fieldnames = ['Data', 'H2', 'LPG', 'CH4', 'CO', 'Alcohol', 'Propane']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    writer.writeheader()
    
    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
