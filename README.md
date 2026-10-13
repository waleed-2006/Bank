# 🏦 Bank Management System

A console-based **Bank Management System written in C++**. The project allows users to manage bank clients and perform basic banking transactions through a simple menu-driven interface.

## ✨ Features

### Client Management
- Show all clients
- Add new clients
- Delete clients
- Update client information
- Search for a client
- Check whether an account number already exists

Each client contains:
- Name
- Phone number
- Account number
- PIN code
- Account balance

### Banking Transactions
- Deposit money
- Withdraw money
- Show all account balances
- Return to the Main Menu

The program verifies that an account exists before performing transactions and saves updated balances to the client file.

## 🖥️ Main Menu

```text
=============================================
             MAIN MENU
=============================================
[1] Show client list
[2] Add New Client
[3] Delete Client
[4] Update Client
[5] Find client
[6] Transactions Menu
[7] Exit
=============================================
💳 Transactions Menu
=============================================
             Transactions
=============================================
[1] Deposit
[2] Withdraw
[3] Show all Balances
[4] Main Menu
=============================================
📁 Project Structure
Bank1/
├── Bank1.cpp
├── Client.h
├── transactions.h
├── filefunctions.h
├── stringfunctions.h
├── Clients.txt
└── README.md
File Descriptions

Bank1.cpp — Contains the main() function, main menu, and overall program flow.

Client.h — Defines the strCleint structure and contains client-management functions such as adding, deleting, updating, searching, and displaying clients.

transactions.h — Contains deposit, withdrawal, account-balance, and transaction-menu functionality.

filefunctions.h — Provides general file operations for reading, writing, updating, and deleting records.

stringfunctions.h — Provides reusable string and input utilities such as splitting, joining, trimming, case conversion, character counting, vowel detection, and user input functions.

Clients.txt — Stores client information so that data can persist between program executions.

💾 Data Storage

Client records are stored in Clients.txt using #//# as a delimiter:

AccountNumber#//#PINcode#//#Name#//#Phone#//#AccountBalance

The program loads the records into a vector<strCleint>, performs operations in memory, and writes changes back to the file.

🛠️ Technologies & Concepts
C++
Visual Studio
Git & GitHub
STL vector
Structures
Functions
Enumerations
References
File I/O
Strings
Loops and switch statements
Modular programming
🚀 How to Run
Clone the repository:
git clone https://github.com/waleed-2006/Bank1.git
Open the project in Visual Studio.
Build the solution.
Run using Ctrl + F5.
🎯 Learning Goals

This project was created to practice building a complete C++ application while learning how to organize code into multiple header files, work with structures and vectors, handle files, manipulate strings, and build menu-driven programs.

🔮 Future Improvements
Add stronger input validation.
Prevent withdrawals greater than the account balance.
Validate positive deposit and withdrawal amounts.
Add transaction history.
Add authentication and improve PIN security.
Improve account-number generation.
Separate declarations and implementations into .h and .cpp files.
Add automated tests.
👨‍💻 Author

Waleed Thabit
