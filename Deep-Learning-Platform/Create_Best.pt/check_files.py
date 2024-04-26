import os

def fix_labels_in_folder(folder_path):
    for filename in os.listdir(folder_path):
        if filename.endswith('.txt'):
            file_path = os.path.join(folder_path, filename)
            with open(file_path, 'r+') as file:
                lines = file.readlines()
                file.seek(0)
                for line in lines:
                    # Check if the line contains any non-numeric characters other than dot
                    if any(c.isalpha() or c in "!@#$%^&*()_-+=[]{}|;:,<>?/'\"" for c in line.strip()):
                        print(filename)  # Print the filename if non-numeric characters other than dot are found
                    file.write(line)
                file.truncate()

# Fix all .txt files in the folder where this script is located
current_folder = os.path.dirname(os.path.abspath(__file__))
fix_labels_in_folder(current_folder)
