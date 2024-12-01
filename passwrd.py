import tkinter as tk
from tkinter import messagebox

# Function to handle password entry and confirmation
def enter_password(event=None):
    password = password_entry.get()  # Get the password from the input field
    confirm_password = confirm_password_entry.get()  # Get the confirm password from the input field
    
    # Check if both passwords match
    if password == confirm_password:
        if password:  # Ensure the password is not empty
            messagebox.showinfo("Password Entered", "Password entered successfully!")
            print(f"Entered password: {password}")  # For debugging purposes
            # Here you can call the next phase function
        else:
            messagebox.showwarning("Input Error", "Please enter a password.")
    else:
        messagebox.showwarning("Password Mismatch", "Passwords do not match. Please try again.")

# Creating the main window
window = tk.Tk()
window.title("Zero-Knowledge Proof - Phase 4")

# Label for password entry
label = tk.Label(window, text="Please enter your password:")
label.pack(pady=10)

# Password input field (hidden text)
password_entry = tk.Entry(window, show="*", width=30)
password_entry.pack(pady=10)

# Label for confirm password entry
confirm_label = tk.Label(window, text="Confirm your password:")
confirm_label.pack(pady=10)

# Confirm password input field (hidden text)
confirm_password_entry = tk.Entry(window, show="*", width=30)
confirm_password_entry.pack(pady=10)

# Button to submit the password
submit_button = tk.Button(window, text="Submit", command=enter_password)
submit_button.pack(pady=20)

# Bind the Enter key to the submit function
window.bind('<Return>', enter_password)

# Run the Tkinter event loop
window.mainloop()
