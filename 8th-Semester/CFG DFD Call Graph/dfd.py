import os
import ast
from graphviz import Digraph

def parse_python_files_with_data(directory):
    """
    Parse Python files to extract functions, their parameters, return values,
    and interactions with files or logs.
    """
    functions = {}
    data_stores = set()

    for filename in os.listdir(directory):
        if filename.endswith(".py"):
            filepath = os.path.join(directory, filename)
            with open(filepath, "r") as file:
                try:
                    tree = ast.parse(file.read())
                    for node in ast.walk(tree):
                        if isinstance(node, ast.FunctionDef):
                            func_name = node.name
                            # Collect function parameters
                            params = [arg.arg for arg in node.args.args]
                            # Collect called functions and variables
                            calls = []
                            variables = []
                            for n in ast.walk(node):
                                if isinstance(n, ast.Call) and hasattr(n.func, "id"):
                                    calls.append(n.func.id)
                                if isinstance(n, ast.Name):
                                    variables.append(n.id)
                            # Identify file or log interactions
                            if any(v in ["open", "write", "read"] for v in variables):
                                data_stores.add("file_system")
                            if any("log" in v.lower() for v in variables):
                                data_stores.add("log")
                            functions[func_name] = {"params": params, "calls": calls}
                except SyntaxError as e:
                    print(f"Syntax error in file {filename}: {e}")

    return functions, data_stores

def generate_dfd_with_variables(functions, data_stores):
    """
    Generate a DFD incorporating variables and data stores.
    """
    dfd = Digraph("DFD", format="png")

    # Add external entity
    dfd.node("user", "User", shape="rectangle", style="filled", color="lightblue")

    # Add processes (functions)
    for func in functions:
        dfd.node(func, func.replace("_", " ").title(), shape="ellipse", style="filled", color="yellow")

    # Add data stores
    for store in data_stores:
        dfd.node(store, store.replace("_", " ").title(), shape="cylinder", style="filled", color="lightgreen")

    # Add data flows
    for func, details in functions.items():
        for param in details["params"]:
            dfd.edge("user", func, label=param)
        for call in details["calls"]:
            if call in functions:
                dfd.edge(func, call, label="Call")
        if "log" in data_stores:
            dfd.edge(func, "log", label="Log Entry")
        if "file_system" in data_stores:
            dfd.edge(func, "file_system", label="File Interaction")

    return dfd

# Directory containing the Python files
directory = "./sample-project"  # Replace with the path to your directory

# Parse Python files and generate DFD
functions, data_stores = parse_python_files_with_data(directory)
dfd = generate_dfd_with_variables(functions, data_stores)

# Save and render the DFD
dfd.render("data_flow_diagram_with_variables", view=True)
