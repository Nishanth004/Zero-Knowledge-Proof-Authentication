import tkinter as tk
from tkinter import messagebox
import subprocess
import os

# Function to trigger C++ hashing program and display the result
def hash_password():
    # Execute the C++ program to hash the password
    try:
        # Running the C++ hashing program (main.exe)
        subprocess.run(["./main.exe"], check=True)

        # Read the hashed password from the output file
        with open("hashed_password.txt", "r") as file:
            hashed_password = file.read().strip()

        # Update the GUI with the hashed password
        hashed_label.config(text=f"Your hashed password: {hashed_password}")
        shared_label.config(text="This hashed value will be shared, not your plaintext password.")

    except FileNotFoundError:
        messagebox.showerror("Error", "Hashing program or output file not found.")
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "An error occurred during hashing.")

# GUI setup
root = tk.Tk()
root.title("Zero-Knowledge Proof - Phase 5")
root.geometry("500x300")

# Header
header_label = tk.Label(root, text="Phase 5: Hashing Password", font=("Arial", 16))
header_label.pack(pady=10)

# Button to start hashing
hash_button = tk.Button(root, text="Hash Password", command=hash_password, font=("Arial", 12))
hash_button.pack(pady=20)

# Label to display the hashing progress and result
hashed_label = tk.Label(root, text="", font=("Arial", 12))
hashed_label.pack(pady=10)

# Label to indicate sharing of hashed password
shared_label = tk.Label(root, text="", font=("Arial", 12), fg="blue")
shared_label.pack(pady=10)

# Run the Tkinter event loop
root.mainloop()
