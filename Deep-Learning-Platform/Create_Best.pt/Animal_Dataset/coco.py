import os
import re

# Path to the data folder
data_choice = input("Enter 'train' or 'val' to process the corresponding data folder: ")

# Check if the user input is valid
if data_choice.lower() == 'train':
    data_folder_path = r'C:\Users\user\Downloads\data\train'
elif data_choice.lower() == 'val':
    data_folder_path = r'C:\Users\user\Downloads\data\val'
else:
    print("Invalid input! Please enter 'train' or 'val'.")
    
# Traverse through all class folders
for class_folder in os.listdir(data_folder_path):
    class_folder_path = os.path.join(data_folder_path, class_folder)
    # Find the path of the label folder inside each class folder
    label_folder_path = os.path.join(class_folder_path, 'labels')
    # If the label folder exists
    if os.path.exists(label_folder_path):
        # Traverse through all files in the label folder
        for file_name in os.listdir(label_folder_path):
            file_path = os.path.join(label_folder_path, file_name)
            # Read the content of the file
            with open(file_path, 'r') as file:
                content = file.read().splitlines()
            # Replace the class name with its index number
            with open(file_path, 'w') as file:
                for line in content:
                    line_parts = line.split()
                    # Replace the class name with its index number
                    line_parts[0] = str(os.listdir(data_folder_path).index(class_folder))
                    # Write the line to the file
                    file.write(' '.join(line_parts) + '\n')

print("COCO process is completed!")
