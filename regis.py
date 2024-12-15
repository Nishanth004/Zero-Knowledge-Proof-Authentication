import tkinter as tk
from tkinter import messagebox

# Function to save the password to a file
def save_password():
    password = password_entry.get()
    confirm_password = confirm_password_entry.get()
    user_name = user_entry.get()

    # Check if passwords match
    if password != confirm_password:
        messagebox.showerror("Error", "Passwords do not match. Please try again.")
        return

    # Save password to "password.txt"
    try:
        with open("password.txt", "w") as file:
            file.write(password)
        messagebox.showinfo("Success", "Password saved successfully!")
    except IOError:
        messagebox.showerror("Error", "Failed to save the password. Please try again.")
    try:
        with open("username.txt", "w") as file:
            file.write(user_name)
        messagebox.showinfo("Success", "username saved successfully!")
    except IOError:
        messagebox.showerror("Error", "Failed to save the username. Please try again.")
    # Clear entries
    # user_name.delete(0, tk.END)
    password_entry.delete(0, tk.END)
    confirm_password_entry.delete(0, tk.END)

# GUI setup
root = tk.Tk()
root.title("Zero-Knowledge Proof - Phase 4")
root.geometry("400x400")

# Header
header_label = tk.Label(root, text="Phase 4: Registration", font=("Arial", 16))
header_label.pack(pady=10)

# Password entry
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
confirm_password_label = tk.Label(root, text="Confirm Password:", font=("Arial", 12))
confirm_password_label.pack(pady=5)
confirm_password_entry = tk.Entry(root, show="*", font=("Arial", 12))
confirm_password_entry.pack(pady= 5)

# Save button
save_button = tk.Button(root, text="Save credentials", command=save_password, font=("Arial", 12))
save_button.pack(pady=20)

# Bind the Enter key to save_password function
root.bind('<Return>', lambda event: save_password())

# Run the Tkinter event loop
root.mainloop()