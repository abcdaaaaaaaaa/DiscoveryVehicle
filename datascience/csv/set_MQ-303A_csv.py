import csv

data_list = []
data_number = 1

while True:
    print(f"Data {data_number}:")
    data = input("Data: ")
    isobuthane = input("Isobuthane: ")
    hydrogen = input("Hydrogen: ")
    ethanol = input("Ethanol: ")

    data_entry = {
        'Data': data,
        'Isobuthane': isobuthane,
        'Hydrogen': hydrogen,
        'Ethanol': ethanol
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('MQ-303A.csv', 'w', newline='') as file:
    fieldnames = ['Data', 'Isobuthane', 'Hydrogen', 'Ethanol']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    writer.writeheader()
    
    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
