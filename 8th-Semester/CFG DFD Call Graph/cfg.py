import os
from pycfg import PyCfg

# Define the directory you want to scan for Python files
directory_path = 'sample-project/'

# Check if directory exists
if not os.path.exists(directory_path):
    print(f"Directory {directory_path} does not exist.")
    exit(1)

# List all Python files in the directory
python_files = [f for f in os.listdir(directory_path) if f.endswith('.py')]

# Ensure there are Python files in the directory
if not python_files:
    print(f"No Python files found in {directory_path}.")
    exit(1)

# Process each Python file
for py_file in python_files:
    file_path = os.path.join(directory_path, py_file)
    
    # Generate the control flow graph for the current Python file
    cfg = PyCfg(file_path)
    
    # Render the CFG and save it as a PNG file
    output_png = f"{file_path}_cfg.png"
    cfg.render(output_png)  # Save as PNG
    
    print(f"Control Flow Graph for {py_file} has been saved as {output_png}.")
