# import tkinter as tk
# from tkinter import messagebox
# import os

# def check_status():
#     if os.path.exists("status.txt"):
#         with open("status.txt", "r") as file:
#             status = file.read()
#         if "Initialized" in status:
#             messagebox.showinfo("Status", "Connections are established.")
#         else:
#             messagebox.showinfo("Status", "All ports and connections are not made yet.")
#     else:
#         messagebox.showinfo("Status", "All ports and connections are not made yet.")

# def initialize_connections():
#     # Simulate backend call
#     os.system("main.exe")  # Run the C++ executable
#     check_status()

# # Create the GUI window
# root = tk.Tk()
# root.title("Phase 1: Connection Setup")

# # Add labels and buttons
# label = tk.Label(root, text="Network Connections Monitor.", font=("Arial", 12))
# label.pack(pady=20)

# check_button = tk.Button(root, text="Check Status", command=check_status, width=20)
# check_button.pack(pady=10)

# init_button = tk.Button(root, text="Initialize Connections", command=initialize_connections, width=20)
# init_button.pack(pady=10)

# # Run the GUI
# root.mainloop()
import tkinter as tk
from tkinter import messagebox
import time

def check_connections():
    # Simulate checking connections
    status_label.config(text="Checking connections...")
    root.update()
    time.sleep(2)  # Simulate delay
    status_label.config(text="No ports or connections are established.")
    messagebox.showinfo("Phase 1", "All connections are disabled.\nProceed to Phase 2.")

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
