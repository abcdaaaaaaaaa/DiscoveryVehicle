import csv

data_list = []
data_number = 1

while True:
    print(f"Data {data_number}:")
    usvhr = input("usV/hr: ")

    data_entry = {
        'usV/hr': usvhr,
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('GeigerCounter.csv', 'w', newline='') as file:
    fieldnames = ['usV/hr']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    writer.writeheader()
    
    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
