import os
import zipfile
import shutil

def clear_directory(directory):
    """Remove all files and directories in the specified directory."""
    if os.path.exists(directory):
        for root, _, files in os.walk(directory):
            for file in files:
                os.remove(os.path.join(root, file))
            for dir in os.listdir(root):
                shutil.rmtree(os.path.join(root, dir), ignore_errors=True)

def unzip_and_organize(zip_path):
    # Set the output directory to the current directory
    output_dir = os.getcwd()

    # Create output directories for headers and source files
    include_dir = os.path.join(output_dir, 'include')
    src_dir = os.path.join(output_dir, 'src')
    os.makedirs(include_dir, exist_ok=True)
    os.makedirs(src_dir, exist_ok=True)

    # Clear existing contents in include and src folders
    clear_directory(include_dir)
    clear_directory(src_dir)

    # Unzip the file
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        temp_extract_dir = os.path.join(output_dir, 'temp')
        os.makedirs(temp_extract_dir, exist_ok=True)
        zip_ref.extractall(temp_extract_dir)

    # Move .h and .cpp files to respective folders, checking for existing files
    for root, _, files in os.walk(temp_extract_dir):
        for file in files:
            source = os.path.join(root, file)
            if file.endswith('.h'):
                destination = os.path.join(include_dir, file)
            elif file.endswith('.cpp'):
                destination = os.path.join(src_dir, file)
            else:
                continue  # Skip files that are not .h or .cpp

            if os.path.exists(destination):
                print(f"File '{file}' already exists in '{os.path.dirname(destination)}'.")
                continue
            shutil.move(source, destination)

    # Clean up temporary extraction folder
    shutil.rmtree(temp_extract_dir)

if __name__ == "__main__":
    zip_file_path = os.path.join(os.getcwd(), 'Tire_Model_Codegen.zip')  # Update this if needed
    unzip_and_organize(zip_file_path)
