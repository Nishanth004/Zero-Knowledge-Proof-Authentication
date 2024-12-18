import tkinter as tk
from tkinter import messagebox
import subprocess

# Function to save the password to a file
def save_password():
    password = password_entry.get()
    username = user_entry.get()
    
    # Ensure both username and password are entered
    if not username or not password:
        messagebox.showwarning("Input Error", "Please enter both username and password.")
        return  # Stop execution if either is missing
    
    try:
        with open("password.txt", "w") as file:
            file.write(password)
        with open("username.txt", "w") as file:
            file.write(username)
        messagebox.showinfo("Success", "Credentials saved successfully!")
    except IOError:
        messagebox.showerror("Error", "Failed to save the credentials. Please try again.")

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
root.config(bg="#f0f0f0")  # Light background color for the window

# Phase 4: Enter Password Header
header_label = tk.Label(root, text="Phase 4: Enter Password", font=("Arial", 16, "bold"), bg="#f0f0f0", fg="#4CAF50")
header_label.pack(pady=20)

# Username entry
user_label = tk.Label(root, text="Enter Username:", font=("Arial", 12), bg="#f0f0f0")
user_label.pack(pady=5)
user_entry = tk.Entry(root, font=("Arial", 12), bd=2, relief="solid")
user_entry.pack(pady=5, ipadx=10, ipady=5)

# Password entry
password_label = tk.Label(root, text="Enter Password:", font=("Arial", 12), bg="#f0f0f0")
password_label.pack(pady=5)
password_entry = tk.Entry(root, show="*", font=("Arial", 12), bd=2, relief="solid")
password_entry.pack(pady=5, ipadx=10, ipady=5)

# Login button (calls both save_password and hash_password)
login_button = tk.Button(root, text="Login", command=login_and_hash, font=("Arial", 12), bg="#4CAF50", fg="white", activebackground="#45a049", activeforeground="white", relief="raised")
login_button.pack(pady=20)

# Labels for hashed password display
hashed_label = tk.Label(root, text="", font=("Arial", 12), bg="#f0f0f0", fg="green")
hashed_label.pack(pady=10)

# Shared label text (for explanation on sharing hashed password)
shared_label = tk.Label(root, text="", font=("Arial", 12), bg="#f0f0f0", fg="blue")
shared_label.pack(pady=10)

# Bind the Enter key to the login_and_hash function
root.bind('<Return>', lambda event: login_and_hash())

# Run the Tkinter event loop
root.mainloop()
