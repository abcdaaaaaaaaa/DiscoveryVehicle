from flask import Flask, render_template, request, redirect, url_for, flash, send_file
from werkzeug.utils import secure_filename
import os
import subprocess
import zipfile
import shutil

app = Flask(__name__)

UPLOAD_FOLDER = 'data/images/'
ZIP_FOLDER = 'data/zipfile/'
RESULT_FOLDER = 'runs/detect/exp/'
CLEAN_RESULT_FOLDER = 'runs/detect/'

if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

def clean_folders(*folders):
    for folder_path in folders:
        for root, dirs, files in os.walk(folder_path):
            for file in files:
                file_path = os.path.join(root, file)
                os.remove(file_path)
            for folder in dirs:
                dir_path = os.path.join(root, folder)
                shutil.rmtree(dir_path)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload_file():
    if request.method == 'POST':
        zip_name = request.form.get('zip_name')

        uploaded_files = request.files.getlist('file[]')
        filenames = []
        for file in uploaded_files:
            if file:
                filename = secure_filename(file.filename)
                file.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
                filenames.append(filename)

        subprocess.run(["python", "detect.py"])

        zip_path = ZIP_FOLDER + zip_name + '.zip'
        with zipfile.ZipFile(zip_path, 'w') as zipf:
            for root, dirs, files in os.walk(RESULT_FOLDER):
                for file in files:
                    file_path = os.path.join(root, file)
                    zipf.write(file_path, os.path.relpath(file_path, RESULT_FOLDER))

        return redirect(url_for('download_file', zip_name=zip_name))

@app.route('/download/<zip_name>', methods=['GET'])
def download_file(zip_name):
    zip_path = ZIP_FOLDER + zip_name + '.zip'
    return send_file(zip_path, as_attachment=True)

@app.route('/clean')
def perform_clean():
    try:
        clean_folders(UPLOAD_FOLDER, ZIP_FOLDER, CLEAN_RESULT_FOLDER)
    except Exception as e:
        print(f"Clean Error: {e}")
    
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
