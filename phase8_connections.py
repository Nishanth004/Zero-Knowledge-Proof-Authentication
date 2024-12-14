# import tkinter as tk
# from tkinter import messagebox
# import subprocess
# import time

# progress_counter = 0  # Counter for dynamic progress updates

# def update_progress(message, max_dots=6):
#     """Update the progress dynamically on the status label."""
#     global progress_counter
#     dots = "." * (progress_counter % max_dots)
#     status_label.config(text=f"{message}{dots}")
#     root.update()
#     progress_counter += 1

# def run_cpp_program(operation):
#     """Run the C++ program and capture output."""
#     try:
#         process = subprocess.Popen(["./connections.exe", operation], stdout=subprocess.PIPE, text=True)
#         while True:
#             output_line = process.stdout.readline()
#             if output_line:
#                 # Update the UI with output from the C++ program
#                 status_label.config(text=output_line.strip())
#                 root.update()
#             if process.poll() is not None:
#                 break
#         process.wait()
#     except subprocess.CalledProcessError:
#         messagebox.showerror("Error", "An error occurred while running the C++ program.")
#     except FileNotFoundError:
#         messagebox.showerror("Error", "C++ program or status file not found.")

# def check_connections():
#     """Check connection status dynamically."""
#     global progress_counter
#     progress_counter = 0
#     status_label.config(text="Checking connections...")  # Initial message
#     root.update()

#     # Simulate dynamic progress for 2 seconds (update every 400ms)
#     for _ in range(6):
#         time.sleep(0.4)  # Simulate a delay for dynamic progress
#         update_progress("Checking connections")

#     # Run the C++ program for checking
#     run_cpp_program("check")

#     # Read the connection status from the file
#     try:
#         with open("status.txt", "r") as file:
#             status = file.read().strip().lower()
#         if status == "yes":
#             status_label.config(text="Connections are established!")
#             messagebox.showinfo("Phase 1", "Connections are enabled.\nYou may proceed.")
#         else:
#             status_label.config(text="No ports or connections are established.")
#             messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed to Phase 2.")
#     except FileNotFoundError:
#         status_label.config(text="Connection status file not found.")
#         messagebox.showerror("Error", "Status file is missing.")

# # Create main window
# root = tk.Tk()
# root.title("Phase 1: Connection Check")
# root.geometry("400x200")

# # Add status label
# status_label = tk.Label(root, text="No connections checked yet.", font=("Arial", 12))
# status_label.pack(pady=20)

# # Add "Check Connections" button
# check_button = tk.Button(root, text="Check Connections", command=check_connections, font=("Arial", 12))
# check_button.pack(pady=20)

# # Run the application
# root.mainloop()


import tkinter as tk
from tkinter import messagebox
import subprocess
import time

progress_counter = 0  # Counter for dynamic progress updates

def update_progress(message, max_dots=6):
    """Update the progress dynamically on the status label."""
    global progress_counter
    dots = "." * (progress_counter % max_dots)
    status_label.config(text=f"{message}{dots}")
    root.update()
    progress_counter += 1

def run_cpp_program(operation):
    """Run the C++ program and capture output."""
    try:
        process = subprocess.Popen(["./connections.exe", operation], stdout=subprocess.PIPE, text=True)
        output = ""
        while True:
            output_line = process.stdout.readline()
            if output_line:
                # Update the UI with output from the C++ program
                output += output_line
                status_label.config(text=output_line.strip())
                root.update()
            if process.poll() is not None:
                break
        process.wait()
        return output.strip()
    except FileNotFoundError:
        messagebox.showerror("Error", "C++ program not found.")
        return "Error"
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "An error occurred while running the C++ program.")
        return "Error"

def perform_operation(operation, action_message, completion_message, popup_title, popup_message_success, popup_message_fail):
    """Generic function to handle dynamic UI updates for operations and show pop-ups."""
    global progress_counter
    progress_counter = 0
    status_label.config(text=action_message)  # Initial message
    root.update()

    # Simulate dynamic progress for 2 seconds (update every 400ms)
    for _ in range(6):
        time.sleep(0.4)  # Simulate a delay for dynamic progress
        update_progress(action_message)

    # Run the C++ program with the selected operation
    result = run_cpp_program(operation)
    if result != "Error":
        # Read the connection status from the file (only for 'check' operation)
        if operation == "check":
            try:
                with open("status.txt", "r") as file:
                    status = file.read().strip().lower()
                if status == "yes":
                    messagebox.showinfo(popup_title, popup_message_success)
                else:
                    messagebox.showwarning(popup_title, popup_message_fail)
            except FileNotFoundError:
                messagebox.showwarning(popup_title, popup_message_fail)
        else:
            # For establish and de-establish operations
            messagebox.showinfo(popup_title, completion_message)
        status_label.config(text=completion_message)

def check_connections():
    perform_operation(
        operation="check",
        action_message="Checking connections",
        completion_message="Check operation complete.",
        popup_title="Check Connections",
        popup_message_success="Connections are established! You may proceed.",
        popup_message_fail="No ports or connections are established. Proceed to the next phase."
    )

def establish_connections():
    perform_operation(
        operation="establish",
        action_message="Establishing connections",
        completion_message="Connections have been established.",
        popup_title="Establish Connections",
        popup_message_success="Connections have been successfully established!",
        popup_message_fail=""  # Not used for this operation
    )

def de_establish_connections():
    perform_operation(
        operation="de_establish",
        action_message="De-establishing connections",
        completion_message="Connections have been de-established.",
        popup_title="De-Establish Connections",
        popup_message_success="Connections have been successfully de-established!",
        popup_message_fail=""  # Not used for this operation
    )

# Create main window
root = tk.Tk()
root.title("Phase 8: Connection Management")
root.geometry("500x300")

# Add status label
status_label = tk.Label(root, text="Select an operation to begin.", font=("Arial", 12))
status_label.pack(pady=20)

# Add buttons for each operation
check_button = tk.Button(root, text="Check Connections", command=check_connections, font=("Arial", 12))
check_button.pack(pady=10)

establish_button = tk.Button(root, text="Establish Connections", command=establish_connections, font=("Arial", 12))
establish_button.pack(pady=10)

de_establish_button = tk.Button(root, text="De-Establish Connections", command=de_establish_connections, font=("Arial", 12))
de_establish_button.pack(pady=10)

# Run the application
root.mainloop()

