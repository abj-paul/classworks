import sys
from file_operations import list_files, search_file, copy_file, delete_file

def main():
    print("File Management System")
    print("1. List Files\n2. Search File\n3. Copy File\n4. Delete File")
    choice = input("Enter your choice: ")

    if choice == '1':
        directory = input("Enter the directory: ")
        list_files(directory)
    elif choice == '2':
        filename = input("Enter the file name: ")
        directory = input("Enter the directory: ")
        search_file(directory, filename)
    elif choice == '3':
        source = input("Enter the source file path: ")
        destination = input("Enter the destination directory: ")
        copy_file(source, destination)
    elif choice == '4':
        filepath = input("Enter the file path to delete: ")
        delete_file(filepath)
    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()

