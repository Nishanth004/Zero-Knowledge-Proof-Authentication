import tkinter as tk
from tkinter import messagebox
import subprocess
import time

# Global Counter for Progress Updates
progress_counter = 0

# Log File
LOG_FILE = "python_phase1_log.txt"

# Function to Log Messages
def log_message(message):
    with open(LOG_FILE, "a") as log_file:
        log_file.write(message + "\n")
    print(message)  # For console output (debugging)

# Function to Update Progress Dynamically
def update_progress(message, max_dots=6):
    """Update the progress dynamically on the status label."""
    global progress_counter
    dots = "." * (progress_counter % max_dots)
    status_label.config(text=f"{message}{dots}")
    root.update()
    progress_counter += 1

# Function to Run the C++ Program
def run_cpp_program(operation):
    """Run the C++ program and capture output."""
    try:
        process = subprocess.Popen(["./connections.exe", operation], stdout=subprocess.PIPE, text=True)
        while True:
            output_line = process.stdout.readline()
            if output_line:
                # Update the UI with output from the C++ program
                status_label.config(text=output_line.strip())
                root.update()
            if process.poll() is not None:
                break
        process.wait()
        log_message(f"Successfully executed C++ program with operation: {operation}")
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "An error occurred while running the C++ program.")
        log_message("Error: Failed to execute the C++ program.")
    except FileNotFoundError:
        messagebox.showerror("Error", "C++ program or status file not found.")
        log_message("Error: C++ executable or status.txt not found.")

# Function to Check Connections
def check_connections():
    """Check connection status dynamically."""
    global progress_counter
    progress_counter = 0
    status_label.config(text="Checking connections...")  # Initial message
    root.update()

    # Simulate dynamic progress for 2 seconds (update every 400ms)
    for _ in range(6):
        time.sleep(0.4)  # Simulate a delay for dynamic progress
        update_progress("Checking connections")

    # Run the C++ program for checking
    run_cpp_program("check")

    # Read the connection status from the file
    try:
        with open("status.txt", "r") as file:
            status = file.read().strip().lower()
        if status == "yes":
            status_label.config(text="Connections are established!", fg="green")
            messagebox.showinfo("Phase 1", "Connections are enabled.\nYou may proceed.")
            log_message("Connections are established. Phase 1 passed.")
        else:
            status_label.config(text="No ports or connections are established.", fg="red")
            messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed to Phase 2.")
            log_message("Connections are disabled. Phase 1 passed with no connections.")
    except FileNotFoundError:
        status_label.config(text="No ports or connections are established.", fg="red")
        messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed.")
        log_message("Error: status.txt file not found.")

# Create Main Window
root = tk.Tk()
root.title("Phase 1: Connection Check")
root.geometry("400x200")
root.config(bg="#282c34")  # Dark background color for the window

# Add Status Label with Color and Styling
status_label = tk.Label(root, text="No connections checked yet.", font=("Arial", 12), bg="#282c34", fg="white")
status_label.pack(pady=20)

# Add "Check Connections" Button with Color
check_button = tk.Button(root, text="Check Connections", command=check_connections, font=("Arial", 12), bg="#4CAF50", fg="white", activebackground="#45a049", activeforeground="white", relief="raised")
check_button.pack(pady=20)

# Run the Application
root.mainloop()
