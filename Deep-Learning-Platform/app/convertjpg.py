import os
import pydicom
from PIL import Image
import numpy as np

folder = 'data/images/'

def dicom_to_jpg(dicom_file, jpg_file):
    # Read the DICOM file
    dcm_data = pydicom.dcmread(dicom_file)
    
    # Get the pixel data and normalize it
    pixel_array = dcm_data.pixel_array
    image = (np.maximum(pixel_array, 0) / pixel_array.max()) * 255.0
    image = np.uint8(image)
    
    # Create an image using Pillow
    image_pil = Image.fromarray(image)
    image_pil.save(jpg_file)

def resize_image(image_path, min_size=640):
    # Open the image
    image_pil = Image.open(image_path)
    
    # Resize the image, maintaining aspect ratio
    original_size = image_pil.size
    ratio = float(min_size) / min(original_size)
    new_size = tuple([int(x * ratio) for x in original_size])
    image_pil = image_pil.resize(new_size, Image.Resampling.LANCZOS)
    
    # Save the resized image
    image_pil.save(image_path)
    print(f"{image_path} resized to {new_size}")

def process_images(input_folder, output_folder, min_size=640):
    # List all files in the input directory
    for filename in os.listdir(input_folder):
        file_path = os.path.join(input_folder, filename)
        # Process DICOM files
        if filename.endswith('.dcm'):
            # Get the file name and extension
            file_name, file_extension = os.path.splitext(filename)
            
            # Create the output path for the jpg file
            jpg_file = os.path.join(output_folder, file_name + '.jpg')
            
            # Convert the DICOM file to jpg and save it
            dicom_to_jpg(file_path, jpg_file)
            print(f"{filename} converted from dcm to jpg")
            
            # Resize the resulting jpg
            resize_image(jpg_file, min_size)
        elif filename.endswith('.jpg') or filename.endswith('.jpeg') or filename.endswith('.png'):
            # Resize existing jpg/jpeg/png images
            resize_image(file_path, min_size)

def delete_dcm_files(folder):
    # List all files in the directory
    for filename in os.listdir(folder):
        # Delete only files with the .dcm extension
        if filename.endswith('.dcm'):
            file_path = os.path.join(folder, filename)
            try:
                os.remove(file_path)
                print(f"{filename} deleted")
            except Exception as e:
                print(f"Error deleting {filename}: {e}")

process_images(folder, folder)
delete_dcm_files(folder)
