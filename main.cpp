
#include <iostream>
#include <string>
using namespace std;

class Account {

    // Private data members
    string holderName;
    string accNo;
    int pin;
    long long balance;

    bool isBlocked;
    int failedAttempts;
    bool isCreated;

public:

    // Default constructor
    Account() {
        holderName = "";
        accNo = "";
        pin = -1;
        balance = 0;
        isBlocked = false;
        failedAttempts = 0;
        isCreated = false;
    }

    // Member function to verify the PIN
    bool VerifyPin() {

        if (isBlocked) {
            cout << "Account is temporarily blocked. "
                 << "Please contact your bank.\n";
            return false;
        }

        int enteredPin;

        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            failedAttempts = 0;
            return true;
        }

        failedAttempts++;

        cout << "Incorrect PIN!\n";

        if (failedAttempts >= 3) {
            isBlocked = true;
            cout << "Account blocked due to multiple "
                 << "incorrect PIN attempts.\n";
        }
        else {
            cout << 3 - failedAttempts
                 << " attempts remaining.\n";
        }

        return false;
    }

    // Member function to create an account
    void createAccount() {

        int pin1, pin2;
        int count = 0;

        cout << "\nEnter your bank account number: ";
        cin >> ws;
        getline(cin, accNo);

        cout << "Enter your name: ";
        getline(cin, holderName);

        do {

            cout << "Set your PIN (4-digit): ";
            cin >> pin1;

            cout << "Re-enter the same PIN: ";
            cin >> pin2;

            if (pin1 == pin2 && pin1 >= 1000 && pin1 <= 9999) {

                pin = pin1;
                isCreated = true;

                cout << "\nPIN set successfully!\n";
                cout << "Account created successfully!\n";
                break;
            }
            else {
                cout << "Invalid PIN! Both PINs must match "
                     << "and contain exactly 4 digits.\n";
            }

            count++;

        } while (count < 3);

        if (!isCreated) {
            isBlocked = true;
            cout << "Account creation failed. Card blocked.\n";
        }
    }

    // Member function to display account details
    void displayAccount() {

        if (!isCreated) {
            cout << "Account not created successfully.\n";
            return;
        }

        cout << "\n====== ACCOUNT HOLDER DETAILS ======\n";
        cout << "Account holder name: " << holderName << endl;
        cout << "Account number: " << accNo << endl;
        cout << "Account balance: " << balance << " Rs.\n";
    }

    // Member function to deposit money
    void depositMoney() {

        if (!isCreated) {
            cout << "Create an account first!\n";
            return;
        }

        cout << "\n========= DEPOSIT MONEY =========\n";

        if (VerifyPin()) {

            long long amount;

            cout << "Enter the amount to deposit: ";
            cin >> amount;

            if (amount > 0) {

                balance += amount;

                cout << "Amount deposited successfully!\n";
                cout << "Current balance: "
                     << balance << " Rs.\n";
            }
            else {
                cout << "Invalid deposit amount!\n";
            }
        }
    }

    // Member function to withdraw money
    void withdrawMoney() {

        if (!isCreated) {
            cout << "Create an account first!\n";
            return;
        }

        long long money;

        cout << "\n========= WITHDRAW MONEY =========\n";

        if (VerifyPin()) {

            cout << "Enter the amount to withdraw: ";
            cin >> money;

            if (money > 0 && money <= balance) {

                balance -= money;

                cout << "Amount withdrawn successfully!\n";
                cout << "Collect your money.\n";
                cout << "Current balance: "
                     << balance << " Rs.\n";
            }
            else {
                cout << "Invalid amount or insufficient balance!\n";
                cout << "No amount deducted from your account.\n";
            }
        }
    }

    // Member function to check account balance
    void checkBalance() {

        if (!isCreated) {
            cout << "Create an account first!\n";
            return;
        }

        cout << "\n========= CHECK BALANCE =========\n";

        if (VerifyPin()) {

            cout << "Your account balance is: "
                 << balance << " Rs.\n";

            cout << "Thank you for using our ATM services!\n";
        }
    }
};

int main() {

    int n;

    cout << "====== ATM MANAGEMENT SYSTEM ======\n";

    cout << "Enter the number of users: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of users!\n";
        return 0;
    }

    // Dynamically create accounts for multiple users
    Account* accounts = new Account[n];

    // Create accounts
    for (int i = 0; i < n; i++) {
        cout << "\nCreating account for User " << i + 1 << ":\n";
        accounts[i].createAccount();
    }

    int userChoice, choice;

    // ATM operations for all users
    do {

        cout << "\n====== ATM USER MENU ======\n";
        cout << "Enter user number (1 to " << n << "): ";
        cout << "\nEnter 0 to exit.\n";
        cin >> userChoice;

        if (userChoice == 0) {
            break;
        }

        if (userChoice < 1 || userChoice > n) {
            cout << "Invalid user number!\n";
            continue;
        }

        do {

            cout << "\n======= ATM SERVICES =======\n";
            cout << "1. Deposit Money\n";
            cout << "2. Withdraw Money\n";
            cout << "3. Check Balance\n";
            cout << "4. Display Account Details\n";
            cout << "0. Back to User Menu\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {

                case 1:
                    accounts[userChoice - 1].depositMoney();
                    break;

                case 2:
                    accounts[userChoice - 1].withdrawMoney();
                    break;

                case 3:
                    accounts[userChoice - 1].checkBalance();
                    break;

                case 4:
                    accounts[userChoice - 1].displayAccount();
                    break;

                case 0:
                    cout << "Returning to user menu...\n";
                    break;

                default:
                    cout << "Invalid choice! Try again.\n";
            }

        } while (choice != 0);

    } while (true);

    // Release dynamically allocated memory
    delete[] accounts;

    cout << "Thank you for using our ATM services!\n";

    return 0;
}
