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

write_mode = input("Do you want to (A)dd data or (W)rite data to a new file? (A/W): ")

if write_mode.lower() == 'a':
    mode = 'a'
elif write_mode.lower() == 'w':
    mode = 'w'
else:
    print("Invalid choice. Using 'A' (add) mode by default.")
    mode = 'a'

with open('GeigerCounter.csv', mode, newline='') as file:
    fieldnames = ['usV/hr']
    writer = csv.DictWriter(file, fieldnames=fieldnames)

    if mode == 'w':
        writer.writeheader()

    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
