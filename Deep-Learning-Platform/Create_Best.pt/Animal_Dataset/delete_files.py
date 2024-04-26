import os

def delete_files_with_names(folder_path, filenames):
    for filename in filenames:
        file_path = os.path.join(folder_path, filename)
        if os.path.isfile(file_path):
            os.remove(file_path)

files_to_delete = []

current_folder = os.path.dirname(os.path.abspath(__file__))
delete_files_with_names(current_folder, files_to_delete)
