import os
import ast
import networkx as nx
import matplotlib.pyplot as plt


# --- CFG Generation ---
def generate_cfg(file_path, output_path="cfg.png"):
    """
    Generate Control Flow Graph (CFG) from a Python file and save as PNG.
    """
    try:
        with open(file_path, "r") as source:
            tree = ast.parse(source.read())
        
        cfg = nx.DiGraph()

        class CFGNodeVisitor(ast.NodeVisitor):
            def __init__(self):
                self.current_node = None

            def generic_visit(self, node):
                if isinstance(node, ast.stmt):
                    cfg.add_node(id(node), label=type(node).__name__)
                    if self.current_node:
                        cfg.add_edge(self.current_node, id(node))
                    self.current_node = id(node)
                super().generic_visit(node)

        visitor = CFGNodeVisitor()
        visitor.visit(tree)

        # Draw and save CFG
        pos = nx.spring_layout(cfg)
        nx.draw(cfg, pos, with_labels=True, node_color="lightblue", node_size=1500, font_size=8)
        labels = nx.get_node_attributes(cfg, "label")
        nx.draw_networkx_labels(cfg, pos, labels)
        plt.savefig(output_path)
        plt.close()
        print(f"CFG saved to {output_path}")

    except Exception as e:
        print(f"Error generating CFG: {e}")


# --- Call Graph Generation ---
def generate_call_graph(entry_file, output_path="callgraph.png"):
    """
    Generate Call Graph using static analysis and save as PNG.
    """
    try:
        call_graph = nx.DiGraph()

        class CallGraphVisitor(ast.NodeVisitor):
            def __init__(self):
                self.current_function = None

            def visit_FunctionDef(self, node):
                self.current_function = node.name
                call_graph.add_node(node.name, label="Function")
                self.generic_visit(node)
                self.current_function = None

            def visit_Call(self, node):
                if self.current_function and isinstance(node.func, ast.Name):
                    call_graph.add_edge(self.current_function, node.func.id)
                self.generic_visit(node)

        with open(entry_file, "r") as source:
            tree = ast.parse(source.read())
            visitor = CallGraphVisitor()
            visitor.visit(tree)

        # Draw and save Call Graph
        pos = nx.spring_layout(call_graph)
        nx.draw(call_graph, pos, with_labels=True, node_color="lightgreen", node_size=1500, font_size=8)
        plt.savefig(output_path)
        plt.close()
        print(f"Call graph saved to {output_path}")

    except Exception as e:
        print(f"Error generating Call Graph: {e}")


# --- DFD Generation ---
def generate_dfd(processes, data_stores, external_entities, output_path="dfd.png"):
    """
    Generate a Data Flow Diagram (DFD) and save as PNG using Matplotlib.
    """
    try:
        dfd = nx.DiGraph()

        # Add external entities
        for entity in external_entities:
            dfd.add_node(entity, shape="rectangle", color="lightblue")

        # Add data stores
        for store in data_stores:
            dfd.add_node(store, shape="cylinder", color="lightgreen")

        # Add processes and connections
        for process, connections in processes.items():
            dfd.add_node(process, shape="ellipse", color="yellow")
            for target in connections:
                dfd.add_edge(process, target)

        # Draw and save DFD
        pos = nx.spring_layout(dfd)
        nx.draw(dfd, pos, with_labels=True, node_color="lightyellow", node_size=1500, font_size=8)
        plt.savefig(output_path)
        plt.close()
        print(f"DFD saved to {output_path}")

    except Exception as e:
        print(f"Error generating DFD: {e}")


# --- Main Function ---
def main():
    project_files = ["main.py", "file_operations.py", "utils.py"]  # Specify your project files
    output_dir = "analysis_output"
    os.makedirs(output_dir, exist_ok=True)

    # Generate CFG for each file
    for file in project_files:
        output_path = os.path.join(output_dir, f"cfg_{file.split('.')[0]}.png")
        generate_cfg(file, output_path)

    # Generate Call Graph
    generate_call_graph("main.py", os.path.join(output_dir, "callgraph.png"))

    # Generate DFD
    processes = {
        "main": ["list_files", "search_file", "copy_file", "delete_file"],
        "list_files": ["log"],
        "search_file": ["log"],
        "copy_file": ["log"],
        "delete_file": ["log"],
    }
    data_stores = ["log.txt"]
    external_entities = ["user"]
    generate_dfd(processes, data_stores, external_entities, os.path.join(output_dir, "dfd.png"))

    print(f"Analysis complete. Results saved in '{output_dir}'.")


if __name__ == "__main__":
    main()
