import tkinter as tk
from tkinter import messagebox
import subprocess

# Function to handle password entry and confirmation
def enter_password():
    password = password_entry.get()
    confirm_password = confirm_password_entry.get()

    if password == confirm_password:
        if password:  # Ensure the password is not empty
            messagebox.showinfo("Password Entered", "Password entered successfully!")
            save_and_hash_password()  # Save the password and hash it
        else:
            messagebox.showwarning("Input Error", "Please enter a password.")
    else:
        messagebox.showwarning("Password Mismatch", "Passwords do not match. Please try again.")

# Function to save the password and trigger hashing
def save_and_hash_password():
    save_password()
    hash_password()

# Function to save the password to a file
def save_password():
    password = password_entry.get()
    username = user_entry.get()
    try:
        with open("password.txt", "w") as file:
            file.write(password)
        with open("username.txt", "w") as file:
            file.write(username)
        messagebox.showinfo("Success", "Credentials saved successfully!")
    except IOError:
        messagebox.showerror("Error", "Failed to save credentials. Please try again.")

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

# GUI setup
root = tk.Tk()
root.title("Zero-Knowledge Proof - Password Management")
root.geometry("500x500")

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

# Confirm password entry
confirm_label = tk.Label(root, text="Confirm Password:", font=("Arial", 12))
confirm_label.pack(pady=5)
confirm_password_entry = tk.Entry(root, show="*", font=("Arial", 12))
confirm_password_entry.pack(pady=5)

# Submit button
submit_button = tk.Button(root, text="Register", command=enter_password, font=("Arial", 12))
submit_button.pack(pady=20)

# Labels for hashed password display
hashed_label = tk.Label(root, text="", font=("Arial", 12))
hashed_label.pack(pady=10)
shared_label = tk.Label(root, text="", font=("Arial", 12), fg="blue")
shared_label.pack(pady=10)

# Bind the Enter key to the enter_password function
root.bind('<Return>', lambda event: enter_password())

# Run the Tkinter event loop
root.mainloop()