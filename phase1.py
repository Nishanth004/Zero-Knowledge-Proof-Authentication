# # # import tkinter as tk
# # # from tkinter import messagebox
# # # import os

# # # def check_status():
# # #     if os.path.exists("status.txt"):
# # #         with open("status.txt", "r") as file:
# # #             status = file.read()
# # #         if "Initialized" in status:
# # #             messagebox.showinfo("Status", "Connections are established.")
# # #         else:
# # #             messagebox.showinfo("Status", "All ports and connections are not made yet.")
# # #     else:
# # #         messagebox.showinfo("Status", "All ports and connections are not made yet.")

# # # def initialize_connections():
# # #     # Simulate backend call
# # #     os.system("main.exe")  # Run the C++ executable
# # #     check_status()

# # # # Create the GUI window
# # # root = tk.Tk()
# # # root.title("Phase 1: Connection Setup")

# # # # Add labels and buttons
# # # label = tk.Label(root, text="Network Connections Monitor.", font=("Arial", 12))
# # # label.pack(pady=20)

# # # check_button = tk.Button(root, text="Check Status", command=check_status, width=20)
# # # check_button.pack(pady=10)

# # # init_button = tk.Button(root, text="Initialize Connections", command=initialize_connections, width=20)
# # # init_button.pack(pady=10)

# # # # Run the GUI
# # # root.mainloop()
# # import tkinter as tk
# # from tkinter import messagebox
# # import time

# # def check_connections():
# #     # Simulate checking connections
# #     status_label.config(text="Checking connections...")
# #     root.update()
# #     time.sleep(2)  # Simulate delay
# #     status_label.config(text="No ports or connections are established.")
# #     messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed to Phase 2.")

# # # Create main window
# # root = tk.Tk()
# # root.title("Phase 1: Connection Check")
# # root.geometry("400x200")

# # # Add status label
# # status_label = tk.Label(root, text="No connections checked yet.", font=("Arial", 12))
# # status_label.pack(pady=20)

# # # Add "Check Connections" button
# # check_button = tk.Button(root, text="Check Connections", command=check_connections, font=("Arial", 12))
# # check_button.pack(pady=20)

# # # Run the application
# # root.mainloop()

# import tkinter as tk
# from tkinter import messagebox
# import subprocess
# import time

# def check_connections():
#     try:
#         # Run the C++ program to check the connection status
#         subprocess.run(["./connections.exe"], check=True)

#         # Read the connection status from the file
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
#         messagebox.showerror("Error", "Status file or C++ program is missing.")
#     except subprocess.CalledProcessError:
#         status_label.config(text="Error checking connections.")
#         messagebox.showerror("Error", "An error occurred while checking connections.")

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


# import tkinter as tk
# from tkinter import messagebox
# import subprocess
# import time

# def check_connections():
#     try:
#         # Simulate a delay before checking connections
#         status_label.config(text="Checking connections...")
#         root.update()  # Update the UI with the message
#         time.sleep(2)  # Simulate a delay to represent the time taken by the process

#         # Run the C++ program to check the connection status
#         subprocess.run(["./connections.exe", "check"], check=True)

#         # Read the connection status from the file
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
#         messagebox.showerror("Error", "Status file or C++ program is missing.")
#     except subprocess.CalledProcessError:
#         status_label.config(text="Error checking connections.")
#         messagebox.showerror("Error", "An error occurred while checking connections.")

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
        while True:
            output_line = process.stdout.readline()
            if output_line:
                # Update the UI with output from the C++ program
                status_label.config(text=output_line.strip())
                root.update()
            if process.poll() is not None:
                break
        process.wait()
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "An error occurred while running the C++ program.")
    except FileNotFoundError:
        messagebox.showerror("Error", "C++ program or status file not found.")

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
            status_label.config(text="Connections are established!")
            messagebox.showinfo("Phase 1", "Connections are enabled.\nYou may proceed.")
        else:
            status_label.config(text="No ports or connections are established.")
            messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed to Phase 2.")
    except FileNotFoundError:
        status_label.config(text="No ports or connections are established.")
        messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed.")

# Create main window
root = tk.Tk()
root.title("Phase 1: Connection Check")
root.geometry("400x200")

# Add status label
status_label = tk.Label(root, text="No connections checked yet.", font=("Arial", 12))
status_label.pack(pady=20)

# Add "Check Connections" button
check_button = tk.Button(root, text="Check Connections", command=check_connections, font=("Arial", 12))
check_button.pack(pady=20)

# Run the application
root.mainloop()
