import os
import shutil
from utils import log

def list_files(directory):
    try:
        files = os.listdir(directory)
        for file in files:
            print(file)
        log("Listed files in directory: " + directory)
    except Exception as e:
        log("Error listing files: " + str(e))

def search_file(directory, filename):
    try:
        for root, _, files in os.walk(directory):
            if filename in files:
                print(f"File found: {os.path.join(root, filename)}")
                log(f"File {filename} found in {directory}")
                return
        print("File not found")
        log(f"File {filename} not found in {directory}")
    except Exception as e:
        log("Error searching for file: " + str(e))

def copy_file(source, destination):
    try:
        shutil.copy(source, destination)
        print("File copied successfully")
        log(f"File {source} copied to {destination}")
    except Exception as e:
        log("Error copying file: " + str(e))

def delete_file(filepath):
    try:
        os.remove(filepath)
        print("File deleted successfully")
        log(f"File {filepath} deleted")
    except Exception as e:
        log("Error deleting file: " + str(e))

