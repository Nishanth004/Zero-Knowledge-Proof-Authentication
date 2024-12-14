import tkinter as tk
from tkinter import messagebox, ttk
import subprocess
import time

# Simulate dynamic progress
progress_counter = 0

def update_progress(label, message, max_dots=6):
    """Update the progress dynamically on the status label."""
    global progress_counter
    dots = "." * (progress_counter % max_dots)
    label.config(text=f"{message}{dots}")
    root.update()
    progress_counter += 1

def run_cpp_program(operation):
    """Run the C++ program and display output dynamically."""
    try:
        process = subprocess.Popen(["./zkp_operations.exe", operation], stdout=subprocess.PIPE, text=True)
        while True:
            output_line = process.stdout.readline()
            if output_line:
                output_area.insert(tk.END, output_line)  # Add output to text area
                output_area.see(tk.END)  # Auto-scroll to the latest output
            if process.poll() is not None:
                break
        process.wait()
    except FileNotFoundError:
        messagebox.showerror("Error", "C++ program or required files not found.")
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "An error occurred while running the operation.")

def start_phase_9():
    """Initialize Phase 9 and display the introduction."""
    output_area.insert(tk.END, "Phase 9: Initiating Zero-Knowledge Proof Visualization\n")
    output_area.insert(tk.END, "---------------------------------------------------\n")
    output_area.see(tk.END)

def execute_step(step):
    """Execute a specific ZKP step and update the UI."""
    output_area.insert(tk.END, f"\nExecuting: {step}...\n")
    output_area.see(tk.END)

    # Simulate dynamic progress
    for _ in range(6):
        update_progress(status_label, f"{step} in progress")
        time.sleep(0.4)  # Delay to simulate the operation

    run_cpp_program(step)
    output_area.insert(tk.END, f"\n{step} completed.\n")
    output_area.see(tk.END)

# GUI setup
root = tk.Tk()
root.title("Phase 9: ZKP Visualization")
root.geometry("600x400")

# Status label
status_label = tk.Label(root, text="Status: Waiting for input", font=("Arial", 12))
status_label.pack(pady=10)

# Text area for output
output_area = tk.Text(root, height=15, width=70, wrap=tk.WORD, font=("Courier", 10))
output_area.pack(pady=10)

# Scrollbar for the text area
scrollbar = ttk.Scrollbar(root, command=output_area.yview)
output_area.config(yscrollcommand=scrollbar.set)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

# Buttons for steps
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

tk.Button(button_frame, text="Start Phase 9", command=start_phase_9, font=("Arial", 12)).grid(row=0, column=0, padx=10)
tk.Button(button_frame, text="Step 1: Compute y", command=lambda: execute_step("compute_y"), font=("Arial", 12)).grid(row=0, column=1, padx=10)
tk.Button(button_frame, text="Step 2: Send y", command=lambda: execute_step("send_y"), font=("Arial", 12)).grid(row=0, column=2, padx=10)
tk.Button(button_frame, text="Step 3: Verify t", command=lambda: execute_step("verify_t"), font=("Arial", 12)).grid(row=1, column=1, padx=10)

# Run the application
root.mainloop()
