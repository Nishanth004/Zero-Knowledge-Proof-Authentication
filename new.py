import tkinter as tk
from tkinter import scrolledtext
import subprocess

def run_cpp_program():
    try:
        # Run the C++ executable
        result = subprocess.run(
            ["c:\\Users\\Nishanth\\Documents\\GitHub\\Zero-Knowledge-Proof-Authentication\\phase3.exe"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        # Create a new window to show the output
        output_window = tk.Toplevel(root)
        output_window.title("C++ Program Output")
        output_window.geometry("600x400")

        # Add a scrollable text area
        text_area = scrolledtext.ScrolledText(output_window, wrap=tk.WORD, font=("Courier", 12))
        text_area.pack(expand=True, fill=tk.BOTH)

        # Display the output and errors
        if result.stdout:
            text_area.insert(tk.END, "=== Output ===\n")
            text_area.insert(tk.END, result.stdout)
        if result.stderr:
            text_area.insert(tk.END, "\n=== Errors ===\n")
            text_area.insert(tk.END, result.stderr)

        text_area.config(state=tk.DISABLED)  # Make the text read-only

    except Exception as e:
        # Display an error message in case of exceptions
        error_window = tk.Toplevel(root)
        error_window.title("Error")
        error_label = tk.Label(error_window, text=f"Error running the program:\n{e}", fg="red")
        error_label.pack(padx=10, pady=10)

# Create the main Tkinter window
root = tk.Tk()
root.title("Run C++ Program")
root.geometry("300x150")

# Add a button to run the C++ program
run_button = tk.Button(root, text="Run C++ Program", command=run_cpp_program, font=("Arial", 14))
run_button.pack(pady=40)

# Run the Tkinter main loop
root.mainloop()
