import tkinter as tk
from tkinter import scrolledtext
import subprocess
import threading

# Function to run a process in a separate thread
def run_in_thread(command):
    def task():
        try:
            print("Running command:", command)  # Debugging
            result = subprocess.run(command, capture_output=True, text=True, check=True, shell=True)
            output_text.delete(1.0, tk.END)
            output_text.insert(tk.END, result.stdout)
        except subprocess.CalledProcessError as e:
            output_text.delete(1.0, tk.END)
            output_text.insert(tk.END, f"Error occurred:\n{e.stderr}\nCommand: {e.cmd}")
        except FileNotFoundError as e:
            output_text.delete(1.0, tk.END)
            output_text.insert(tk.END, f"File not found: {command}\nDetails: {e}")
        except Exception as e:
            output_text.delete(1.0, tk.END)
            output_text.insert(tk.END, f"An unexpected error occurred:\n{e}")
    thread = threading.Thread(target=task)
    thread.start()

# Command functions
def frontend():
    run_in_thread(['python3', 'phase1.py'])

def registration():
    run_in_thread(['python3', 'phase2_regis.py'])

def variables():
    exe_path = r"C:\Users\Nishanth\Documents\GitHub\Zero-Knowledge-Proof-Authentication\phase3.exe"
    run_in_thread([exe_path])

# Create main Tkinter window
root = tk.Tk()
root.title("Code Runner with Tkinter")

# Split the window into two frames (left for buttons, right for output)
frame_left = tk.Frame(root, width=300, height=500, bg='lightgray')
frame_left.pack(side=tk.LEFT, fill=tk.Y)

frame_right = tk.Frame(root, width=500, height=500)
frame_right.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True)

# Add buttons for different commands
button1 = tk.Button(frame_left, text="Phase 1 (Frontend)", width=20, command=frontend)
button1.pack(pady=10)

button2 = tk.Button(frame_left, text="Phase 2 (Registration)", width=20, command=registration)
button2.pack(pady=10)

button3 = tk.Button(frame_left, text="Phase 3 (Variables)", width=20, command=variables)
button3.pack(pady=10)

# Create a scrolled text widget on the right frame to display output
output_text = scrolledtext.ScrolledText(frame_right, wrap=tk.WORD, width=60, height=20, font=("Arial", 12))
output_text.pack(padx=10, pady=10)

# Run the Tkinter event loop
root.mainloop()
