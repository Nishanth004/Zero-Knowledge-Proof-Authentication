# import tkinter as tk
# from tkinter import messagebox

# # Function to handle password entry and confirmation
# def enter_password(event=None):
#     password = password_entry.get()  # Get the password from the input field
#     confirm_password = confirm_password_entry.get()  # Get the confirm password from the input field
    
#     # Check if both passwords match
#     if password == confirm_password:
#         if password:  # Ensure the password is not empty
#             messagebox.showinfo("Password Entered", "Password entered successfully!")
#             print(f"Entered password: {password}")  # For debugging purposes
#             # Here you can call the next phase function
#         else:
#             messagebox.showwarning("Input Error", "Please enter a password.")
#     else:
#         messagebox.showwarning("Password Mismatch", "Passwords do not match. Please try again.")

# # Creating the main window
# window = tk.Tk()
# window.title("Zero-Knowledge Proof - Phase 4")

# # Label for password entry
# label = tk.Label(window, text="Please enter your password:")
# label.pack(pady=10)

# # Password input field (hidden text)
# password_entry = tk.Entry(window, show="*", width=30)
# password_entry.pack(pady=10)

# # Label for confirm password entry
# confirm_label = tk.Label(window, text="Confirm your password:")
# confirm_label.pack(pady=10)

# # Confirm password input field (hidden text)
# confirm_password_entry = tk.Entry(window, show="*", width=30)
# confirm_password_entry.pack(pady=10)

# # Button to submit the password
# submit_button = tk.Button(window, text="Submit", command=enter_password)
# submit_button.pack(pady=20)

# # Bind the Enter key to the submit function
# window.bind('<Return>', enter_password)

# # Run the Tkinter event loop
# window.mainloop()

import tkinter as tk
from tkinter import messagebox

# Function to save the password to a file
def save_password():
    password = password_entry.get()

    # Save password to "password.txt"
    try:
        with open("password.txt", "w") as file:
            file.write(password)
        messagebox.showinfo("Success", "Password saved successfully!")
    except IOError:
        messagebox.showerror("Error", "Failed to save the password. Please try again.")

    # Clear entries
    password_entry.delete(0, tk.END)

# GUI setup
root = tk.Tk()
root.title("Zero-Knowledge Proof - Phase 4")
root.geometry("400x300")

# Header
header_label = tk.Label(root, text="Phase 4: Enter Password", font=("Arial", 16))
header_label.pack(pady=10)

user_label = tk.Label(root, text="Enter Username:", font=("Arial", 12))
user_label.pack(pady=5)
user_entry = tk.Entry(root, font=("Arial", 12))
user_entry.pack(pady=5)



# Password entry
password_label = tk.Label(root, text="Enter Password:", font=("Arial", 12))
password_label.pack(pady=5)
password_entry = tk.Entry(root, show="*", font=("Arial", 12))
password_entry.pack(pady=5)

# Save button
save_button = tk.Button(root, text="Login", command=save_password, font=("Arial", 12))
save_button.pack(pady=20)

# Bind the Enter key to save_password function
root.bind('<Return>', lambda event: save_password())

# Run the Tkinter event loop
root.mainloop()
