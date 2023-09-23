import csv

data_list = []

while True:
    usvhr = input("usV/hr: ")

    data_entry = {
        'usV/hr': usvhr,
    }

    data_list.append(data_entry)

    choice = input("Do you want to (A)dd data or (W)rite data to a new file? (A/W): ")
    
    if choice.lower() == 'a':
        mode = 'a'
    elif choice.lower() == 'w':
        mode = 'w'
    else:
        print("Invalid choice. Please enter 'A' or 'W'.")
        continue

    with open('GeigerCounter.csv', mode, newline='') as file:
        fieldnames = ['usV/hr']
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        
        if mode == 'w':
            writer.writeheader()
        
        for data_entry in data_list:
            writer.writerow(data_entry)

    print("Data has been successfully written to the CSV file")

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break
