import os

def empty_file_names(folder_path):
    empty_files = []
    for file in os.listdir(folder_path):
        file_path = os.path.join(folder_path, file)
        if os.path.isfile(file_path) and os.path.getsize(file_path) == 0:
            empty_files.append(file)
    return empty_files

folder_path = os.path.dirname(os.path.abspath(__file__))
empty_file_list = empty_file_names(folder_path)
print("Empty files in the current directory:")
for file in empty_file_list:
    print(file)
