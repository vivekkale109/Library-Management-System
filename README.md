# 📚 Library Management System

## 📌 Project Description

The Library Management System is a console-based application written in C.  
It allows users to manage library books by issuing and returning them.  
All book records are stored permanently in a file using C file handling functions.

This project uses structures and arrays to organize and manage data efficiently.

---

## 🚀 Features

- Add new books
- Issue books
- Return books
- Display all books
- Store records in file
- Menu-driven interface
- Persistent data storage

---

## 🛠 Concepts Used

- C Structures (struct)
- Arrays
- File Handling:
  - fopen()
  - fprintf()
  - fscanf()
  - fclose()
- switch statement
- Loops (while / do-while)
- Conditional statements

---

## 📂 Project Structure

Library-Management-System/
│
├── library.c      → Main source code
├── books.txt      → Stores book records
└── README.md      → Project documentation

---

## 📘 Data Fields

Each book record may contain:

- Book ID
- Book Title
- Author Name
- Availability Status (Available / Issued)

---

## ▶️ How to Compile and Run

Step 1: Compile
gcc library.c -o library

Step 2: Run
./library

(For Windows)
library.exe

---

## 🖥 Menu Options Example

1. Add Book
2. Issue Book
3. Return Book
4. Display Books
5. Exit

---

## 💡 Working Principle

- Book details are stored in a file named "books.txt".
- Structures define book information.
- Arrays temporarily store records during program execution.
- When a book is issued or returned, the file is updated.
- Data remains saved even after closing the program.

---

## ⚠ Limitations

- No login system
- No fine calculation
- Basic input validation
- Limited error handling

---

## 🔮 Future Improvements

- Add student/member management
- Add due date and fine system
- Add search functionality
- Add delete book feature
- Improve UI
- Add password protection

---

## 📋 Requirements

- GCC Compiler
- Works on Linux / Windows / macOS

---

## 📜 License

This project is open-source and free to use for educational purposes.
You may modify and improve it as needed.
