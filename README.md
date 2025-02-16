# Contact-Book
# Contact Management System in C++

This repository contains a simple Contact Management System implemented in C++.  It allows users to store, search, sort, add, and display contact information.

## Overview

This program provides a basic command-line interface for managing contacts.  It uses a `struct` called `contacts` to store information like name, phone number, email, address, notes, and category for each contact.  The program includes functionalities for:

* **Adding new contacts:**  Prompts the user for contact details and stores them.
* **Displaying contacts:** Shows a list of all saved contacts in a formatted table.
* **Searching for contacts:** Allows searching by name.
* **Sorting contacts:** Sorts the contacts alphabetically by name.

## Features

* **Data Storage:** Uses an array of `contacts` structs to store contact information in memory.  *(Note: Currently, data is not persistent across program executions.  Saving to a file would be a valuable addition.)*
* **Input Validation:** Basic input is handled, but more robust validation could be added.
* **User-Friendly Interface:**  Provides a simple menu-driven interface.

## Technologies Used

* **C++:** The core programming language.
* **Standard Library:** Uses standard C++ libraries like `<iostream>`, `<iomanip>`, `<fstream>`, `<cstring>`, `<stdio.h>`, `<cstdlib>`.
* **Windows-Specific Libraries:**  Uses `<conio.h>` (for `getch()`, which is non-standard and Windows-specific) and `<windows.h>` (for console manipulation like `system("cls")` and `gotoxy()`).  *(Note:  The use of `conio.h` makes the code less portable.  Consider alternatives for cross-platform compatibility.)*

## Building and Running

1. **Compiler:** You'll need a C++ compiler (like g++, Visual Studio, etc.) to compile the code.
2. **Compilation:**  Compile the source code (e.g., `g++ contact_manager.cpp -o contact_manager`).
3. **Execution:** Run the executable (e.g., `./contact_manager` on Linux/macOS, `contact_manager.exe` on Windows).

## Code Structure

The code is organized into functions for each feature:

* `add()`: Adds a new contact.
* `display()`: Displays all contacts.
* `search()`: Searches for a contact by name.
* `sort()`: Sorts contacts by name.
* `gotoxy()`: Sets the console cursor position (Windows-specific).
* `main()`: The main function that handles the program's flow.

The `contacts` struct is defined globally to hold the contact information.

## Future Improvements

* **Data Persistence:** Implement file I/O to save and load contacts from a file (e.g., using `fstream`).
* **Cross-Platform Compatibility:** Replace Windows-specific functions (`conio.h`, `system("cls")`) with cross-platform alternatives.
* **Robust Input Validation:** Add more thorough input validation to prevent errors.
* **Search by other criteria:** Allow searching by phone number, email, etc.
* **Deleting Contacts:** Implement functionality to delete existing contacts.
* **Error Handling:** Improve error handling to make the program more robust.
* **User Interface Enhancements:** Consider using a more advanced UI library for a better user experience.

## Dependencies

The code relies on standard C++ libraries and some Windows-specific libraries.  If you're compiling on a non-Windows system, you'll need to remove or replace the Windows-specific parts.

## Author
ehhsen 
