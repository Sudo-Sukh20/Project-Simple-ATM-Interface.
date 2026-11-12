
# ATM Management System

## Description
This is a console-based ATM Management System developed using C++. It allows users to create bank accounts, log in using their account number and PIN, deposit money, withdraw money and check their account balance.

The project uses Object-Oriented Programming concepts and file handling to manage and store account information.

## Features
- Create a new bank account.
- Login using account number and PIN.
- PIN verification with a limit of three incorrect attempts.
- Temporary account blocking after multiple incorrect PIN attempts.
- Deposit money into an account.
- Withdraw money from an account.
- Check account balance.
- Display account details.
- Store account records using file handling.
- Load previously saved accounts when the program starts.

## Technologies Used
- C++
- Object-Oriented Programming
- File Handling
- Vectors

## OOP Concepts Used

- **Class and Object:** The `Account` class represents a bank account, and its objects store and manage individual account details.
- **Encapsulation:** Data members such as account number, PIN, holder name and balance are declared private and accessed through public member functions.
- **Data Abstraction:** Account operations are performed through member functions without exposing their internal implementation.
- **Constructors:** A default constructor initializes account data members with default values.
- **Member Functions:** Functions are used to perform operations such as account creation, PIN verification, depositing and withdrawing money.

## File Handling
File handling is used to store account information permanently.

- `ofstream` is used to write account records into a file.
- `ifstream` is used to read saved account records.
- `stringstream` is used to separate and extract individual account details.
- Account information is stored in `accounts.txt`.
- Saved records are loaded automatically when the program starts.

## Project Structure

```text
ATM-Management-System/
│
├── main.cpp
├── README.md
└── .gitignore
```

**Note:** The `accounts.txt` file is created automatically when account records are saved. It is excluded from GitHub using `.gitignore`.

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/Sudo-Sukh20/Project-Simple-ATM-Interface.git
   ```

2. Open the project folder.

3. Compile the program:

   ```bash
   g++ main.cpp -o atm
   ```

4. Run the program:

   ```bash
   ./atm
   ```

   On Windows, use:

   ```bash
   atm.exe
   ```

## How to Use

1. Select **Create New Account** to register a new account.
2. Enter your account number, name and a four-digit PIN.
3. Select **Login to Account**.
4. Enter your account number and PIN.
5. Choose from the available ATM services.
6. Select **Logout** to return to the main menu.
7. Select **Exit** to close the program.

## Important Note
This project is developed for educational purposes as part of learning Object-Oriented Programming in C++.

The PIN is stored in plain text in the local file. Therefore, use only dummy account details and never use real banking information.

## Future Improvements
- Add transaction history.
- Add an option to update account details.
- Improve input validation.
- Add a more user-friendly interface.

## Learning Outcomes
Through this project, We practised:
- Implementing OOP concepts in C++.
- Managing multiple objects using vectors.
- Working with file handling.
- Using classes and member functions to organize code.
- Implementing basic account operations and PIN verification.

---

**Made with C++**
