# Phonebook Dictionary

Phonebook Dictionary is a C++ project that manages contacts using a Binary Search Tree (BST) and file handling techniques. This application allows users to store, search, and manage contacts efficiently. It integrates BST operations for dynamic contact management and provides persistent storage through file handling.

## Project Overview

The Phonebook Dictionary application provides users with features such as adding, deleting, and searching contacts by name or phone number. All contacts are stored in a file, allowing the application to persist data between sessions. The implementation uses a Binary Search Tree for efficient data management and supports unique contacts for each phone number while handling duplicate names.

## Features

- **Add Contact:** Insert a new contact into both the file and the BST.
- **Remove Contact:** Delete an existing contact from both the file and the BST.
- **Search by Contact:** Search for a contact by phone number.
- **Search by Name:** Search for a contact by name.
- **Display Contacts:** List all contacts from the file.
- **File Persistence:** Contact data is saved in a file and retrieved during program execution.

## Functionality

1. **User Input:** The program accepts user input for managing contacts.
2. **Binary Search Tree (BST):**
   - **Insertion:** Insert a contact by name and phone number.
   - **Deletion:** Delete a contact by phone number, removing it from both the BST and the file.
3. **File Handling:**
   - Open, read, write, and close the phonebook file (`phonebook.txt`).
   - Copy file content to a temporary file during the delete operation.
   - Delete specific contact data from the file.

## Usage

### Adding a Contact
- When adding a contact, the program checks the file to ensure the phone number is unique. If the contact is new, it gets inserted into both the BST and the file.

### Removing a Contact
- Contacts can be deleted by entering the phone number. The deletion is performed in both the BST and the file. If the contact exists, it will be removed from both storage systems.

### Searching for a Contact
- Search by either phone number or name. The program reads the contact information from the file and displays the result.

### Displaying All Contacts
- The program can display all contacts stored in the phonebook file.

## Code Structure

- **Binary Search Tree (BST):**
  - Efficiently manages dynamic contact data.
  - Ensures fast search and delete operations for the contact directory.
  
- **File Handling:**
  - Supports persistent data storage across sessions.
  - The file stores contact information in a structured format, allowing data retrieval and updates.

## File Handling

The program uses a file called `phonebook.txt` to store contact information.

## Technologies Used

- **Programming Language:** C++
- **Data Structure:** Binary Search Tree (BST)
- **File Handling:** C++ file I/O for persistent data storage.
