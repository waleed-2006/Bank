# 🏦 Bank Management System

A console-based **Bank Management System written in C++** that allows users to manage bank clients, perform banking transactions, and manage user accounts with permission-based access control through a menu-driven interface.

## ✨ Features

### 👥 Client Management
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

### 💳 Banking Transactions
- Deposit money
- Withdraw money
- Show all account balances
- Return to the Main Menu
- Save updated account balances to the client file

The program verifies that an account exists before performing transactions and persists updated balances in a file.

### 🔐 User Management
- List all users
- Add new users
- Delete users
- Update user information
- Search for users
- Prevent duplicate usernames
- Assign full access or individual permissions

Each user contains:
- Username
- Password
- Permissions

### 🛡️ Access Control
The system includes a permission-based access control mechanism that determines which user-management menu options a logged-in user can access.

Available permissions include:
- List users
- Add users
- Delete users
- Update users
- Search for users
- Full access to all user-management options

## 🖥️ Main Menu

The main menu provides access to client management, banking transactions, and the program's exit option.

### 💳 Transactions Menu

```text
=============================================
             Transactions
=============================================
[1] Deposit
[2] Withdraw
[3] Show all Balances
[4] Main Menu
=============================================
```

### 🔐 User Management Menu

```text
=============================================
             Users Menu
=============================================
[1] List Users
[2] Add New Users
[3] Delete User
[4] Update User
[5] Search User
[6] Main Menu
=============================================
```

## 📁 Project Structure

```text
Bank/
├── Bank1/
│   ├── Bank1.cpp
│   ├── ATM.h
│   ├── Client.h
│   ├── Users.h
│   ├── transactions.h
│   ├── filefunctions.h
│   ├── stringfunctions.h
│   ├── Clients.txt
│   └── Users.txt
├── Bank1.sln
├── .gitignore
└── README.md
```

*Note: The structure above reflects the expected project organization. Keep the filenames and directory structure consistent with your actual repository.*

## 📝 File Descriptions

- **`Bank1.cpp`** — Contains the `main()` function, main menu, and overall program flow.
- **`ATM.h`** — Contains ATM-related functionality, if used by the project.
- **`Client.h`** — Defines the client structure and client-management functions, including adding, deleting, updating, searching, and displaying clients.
- **`Users.h`** — Defines user records and implements user-management functionality, including permission assignment and access checks.
- **`transactions.h`** — Handles deposits, withdrawals, account balances, and the transactions menu.
- **`filefunctions.h`** — Provides reusable file operations for reading, writing, updating, and deleting records.
- **`stringfunctions.h`** — Provides reusable string and input utilities.
- **`Clients.txt`** — Stores client records for persistence between program executions.
- **`Users.txt`** — Stores user records, including usernames, passwords, and permissions.
- **`Bank1.sln`** — Visual Studio solution file.

## 💾 Data Storage

The application uses text files to store records between program executions.

### Client Records

Client records use `#//#` as a delimiter:

```text
AccountNumber#//#PINcode#//#Name#//#Phone#//#AccountBalance
```

### User Records

User records use `#//#` as a delimiter:

```text
Username#//#Password#//#Permissions
```

Permissions are stored as numeric values corresponding to the available user-management options. The value `-1` represents full access.

The program loads records into vectors, processes operations in memory, and writes updated records back to the corresponding files.

**Security note:** Passwords and PIN codes should not be stored in plaintext in a production application. This project uses file-based storage for learning purposes.

## 🛠️ Technologies & Concepts

- C++
- Visual Studio
- Git and GitHub
- Standard Template Library (STL)
- Vectors and structures
- Functions and enumerations
- References
- File input/output (File I/O)
- String manipulation
- Loops and switch statements
- Modular programming
- Authentication and permission checks
- File-based data persistence

## 🚀 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/waleed-2006/Bank.git
   ```

2. Open `Bank1.sln` in Visual Studio.
3. Build the solution using **Build → Build Solution**.
4. Run the program using **Ctrl + F5**.

## 🎯 Learning Goals

This project was developed to practice building a modular C++ application while learning how to:

- Organize code across multiple header files.
- Use structures, vectors, and enumerations.
- Perform file operations and persist application data.
- Manipulate strings and validate user input.
- Build menu-driven console applications.
- Implement user management and permission-based access control.
- Integrate multiple features into a single application.
- Manage project versions using Git and GitHub.

## 🔮 Future Improvements

- Strengthen input validation and error handling.
- Prevent withdrawals exceeding the available account balance.
- Validate positive deposit and withdrawal amounts.
- Add transaction history.
- Hash passwords and improve PIN security.
- Improve account-number generation.
- Separate declarations and implementations into `.h` and `.cpp` files.
- Add automated tests.
- Improve permission management and authentication.
- Replace plaintext file storage with a more secure data-storage solution.

## 👨‍💻 Author

**Waleed Thabit**
