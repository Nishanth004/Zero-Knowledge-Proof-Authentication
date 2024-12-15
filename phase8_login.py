import tkinter as tk
from tkinter import messagebox
import subprocess

# Function to save the password to a file
def save_password():
    password = password_entry.get()
    if password:  # Ensure the password is not empty
        try:
            with open("password.txt", "w") as file:
                file.write(password)
            messagebox.showinfo("Success", "Password saved successfully!")
        except IOError:
            messagebox.showerror("Error", "Failed to save the password. Please try again.")
    else:
        messagebox.showwarning("Input Error", "Please enter a password.")

# Function to trigger C++ hashing program and display the result
def hash_password():
    try:
        subprocess.run(["./hash.exe"], check=True)
        with open("hashed_password.txt", "r") as file:
            hashed_password = file.read().strip()
        hashed_label.config(text=f"Your hashed password: {hashed_password}")
        shared_label.config(text="This hashed value will be shared, not your plaintext password.")
    except FileNotFoundError:
        messagebox.showerror("Error", "Hashing program or output file not found.")
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "An error occurred during hashing.")

# Wrapper function to execute both save_password and hash_password
def login_and_hash():
    save_password()
    hash_password()

# GUI setup
root = tk.Tk()
root.title("Zero-Knowledge Proof - Password Management")
root.geometry("500x400")

# Phase 4: Enter Password
header_label = tk.Label(root, text="Phase 4: Enter Password", font=("Arial", 16))
header_label.pack(pady=10)

# Username entry
user_label = tk.Label(root, text="Enter Username:", font=("Arial", 12))
user_label.pack(pady=5)
user_entry = tk.Entry(root, font=("Arial", 12))
user_entry.pack(pady=5)

# Password entry
password_label = tk.Label(root, text="Enter Password:", font=("Arial", 12))
password_label.pack(pady=5)
password_entry = tk.Entry(root, show="*", font=("Arial", 12))
password_entry.pack(pady=5)

# Login button (calls both save_password and hash_password)
login_button = tk.Button(root, text="Login", command=login_and_hash, font=("Arial", 12))
login_button.pack(pady=20)


# Labels for hashed password display
hashed_label = tk.Label(root, text="", font=("Arial", 12))
hashed_label.pack(pady=10)
shared_label = tk.Label(root, text="", font=("Arial", 12), fg="blue")
shared_label.pack(pady=10)

# Bind the Enter key to the login_and_hash function
root.bind('<Return>', lambda event: login_and_hash())

# Run the Tkinter event loop
root.mainloop()
