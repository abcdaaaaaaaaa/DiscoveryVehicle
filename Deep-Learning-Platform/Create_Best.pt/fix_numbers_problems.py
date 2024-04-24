import os

def fix_labels_in_folder(folder_path):
    for filename in os.listdir(folder_path):
        if filename.endswith('.txt'):
            file_path = os.path.join(folder_path, filename)
            with open(file_path, 'r+') as file:
                lines = file.readlines()
                file.seek(0)
                for line in lines:
                    # Round the label values
                    parts = line.strip().split()
                    rounded_parts = [str(round(float(part) / 1024, 6)) if '.' in part and not part.isdigit() else part for part in parts]
                    new_line = ' '.join(rounded_parts) + '\n'
                    file.write(new_line)
                file.truncate()

# Fix all .txt files in the folder where this script is located
current_folder = os.path.dirname(os.path.abspath(__file__))
fix_labels_in_folder(current_folder)
