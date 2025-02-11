# 📌 **Phonebook Dictionary**
A contact management system implemented in **C++** using a **Binary Search Tree (BST)** and file handling techniques for efficient contact storage, retrieval, and management.

---

## 🚀 **Project Overview**
The **Phonebook Dictionary** is an advanced contact management application that allows users to store, search, and manage their contacts dynamically using a **Binary Search Tree (BST)**. The application ensures **data persistence** across sessions by utilizing **file handling** techniques. Each contact entry consists of a **name** and a **unique phone number**, ensuring efficient organization and retrieval.

---

## 🔹 **Key Features**
- **✅ Add Contact** – Inserts a new contact into both the file and the BST.
- **✅ Remove Contact** – Deletes an existing contact from both the file and the BST.
- **✅ Search by Phone Number** – Retrieves a contact using a phone number lookup.
- **✅ Search by Name** – Retrieves contacts associated with a given name.
- **✅ Display All Contacts** – Lists all stored contacts from the phonebook file.
- **✅ File Persistence** – Saves contact data in a file to maintain records between sessions.

---

## 📜 **Functionality**
### **1️⃣ User Input Handling**
- The system takes user input to manage contacts dynamically.

### **2️⃣ Binary Search Tree (BST) Operations**
- **🔹 Insertion** – Inserts a contact by name and phone number.
- **🔹 Deletion** – Deletes a contact by phone number, removing it from both the BST and the file.

### **3️⃣ File Handling Operations**
- **📂 Persistent Storage** – Contact information is saved in `phonebook.txt`.
- **📌 Data Consistency** – Ensures that contacts are correctly updated during addition and deletion.
- **🔍 Efficient Search** – Reads contact data from the file for quick lookup.

---

## 📖 **Usage Guide**

### 📌 **Adding a Contact**
- **🔹 The program checks the file to ensure the phone number is unique before insertion.** If the contact is new, it is stored in both the BST and the file.

### 🗑️ **Removing a Contact**
- **🔹 Contacts can be deleted by entering the phone number.** The deletion is performed in both the BST and the file. If the contact exists, it will be removed from both storage systems.

### 🔍 **Searching for a Contact**
- **🔹 Search by either phone number or name.** The program reads the contact information from the file and displays the result.

### 📜 **Displaying All Contacts**
- **🔹 The program lists all contacts stored in the phonebook file.**

---

## 🏛 **Code Structure**
### **📌 Binary Search Tree (BST)**
- **🔹 Efficiently manages dynamic contact data.**
- **🔹 Ensures fast search and delete operations for the contact directory.**

### **📌 File Handling**
- **🔹 Supports persistent data storage across sessions.**
- **🔹 The file stores contact information in a structured format, allowing data retrieval and updates.**

---

## 📂 **File Handling**
The program uses a file called **`phonebook.txt`** to store contact information, ensuring long-term data storage and retrieval.

---

## 🛠 **Technologies Used**
- **🔹 Programming Language:** C++
- **🔹 Data Structure:** Binary Search Tree (BST)
- **🔹 File Handling:** C++ File I/O for Persistent Data Storage

