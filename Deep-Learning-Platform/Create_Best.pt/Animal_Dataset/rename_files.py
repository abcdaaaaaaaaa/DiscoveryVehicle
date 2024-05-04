import os

def rename_files(folder_path, start_index=1):
    # Take the folder name as the prefix
    prefix = os.path.basename(folder_path)
    
    # Get the list of files in the specified folder
    files = os.listdir(folder_path)
    
    # Start index
    index = start_index
    
    # Iterate over each file and perform the renaming operation
    for file in files:
        # Construct the file path
        old_path = os.path.join(folder_path, file)
        
        # Check if it's a file
        if os.path.isfile(old_path) and file != 'rename_files.py':
            # Get the file extension
            _, extension = os.path.splitext(file)
            
            # Determine the prefix for the folder name
            if folder_path.endswith("labels"):
                prefix = os.path.basename(os.path.dirname(folder_path))
            
            # Create the new file name
            new_name = f"{prefix}{index}{extension}"
            
            # Create the new file path
            new_path = os.path.join(folder_path, new_name)
            
            # Rename the file
            os.rename(old_path, new_path)
            
            # Increment the index
            index += 1

# Get the current directory where the code is running
current_directory = os.getcwd()

# Specify the folder path and optionally the start index
folder_path = current_directory
start_index = 1

# Rename the files for images
rename_files(folder_path, start_index)

# Rename the files for the Label folder
rename_files(os.path.join(folder_path, "labels"), start_index)
