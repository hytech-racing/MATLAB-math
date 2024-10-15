import os
import zipfile
import shutil
def unzip_and_organize(zip_path):
   # Set the output directory to the current directory
   output_dir = os.getcwd() + '/HyTech_sim'
   # Create output directories for headers and source files
   include_dir = os.path.join(output_dir, 'include')
   src_dir = os.path.join(output_dir, 'src')
   os.makedirs(include_dir, exist_ok=True)
   os.makedirs(src_dir, exist_ok=True)
   # Unzip the file
   
   # Move .h and .cpp files
   for root, dirs, files in os.walk(output_dir):
       for file in files:
           if file.endswith('.h'):
               shutil.move(os.path.join(root, file), include_dir)
           elif file.endswith('.cpp'):
               shutil.move(os.path.join(root, file), src_dir)
   # Optional: Clean up extracted folders (if needed)
   for root, dirs, files in os.walk(output_dir, topdown=False):
       for file in files:
           os.remove(os.path.join(root, file))
       for dir in dirs:
           os.rmdir(os.path.join(root, dir))
if __name__ == "__main__":
   zip_file_path = os.getcwd() + '/Tire_Model_Codegen.zip'  # Change this to your zip file path
   unzip_and_organize(zip_file_path)