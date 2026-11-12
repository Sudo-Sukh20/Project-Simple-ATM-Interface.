#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Account
{

    // Private data members
    string holderName;
    string accNo;
    int pin;
    long long balance;

    bool isBlocked;
    int failedAttempts;
    bool isCreated;

public:
    // Public member functions

    Account();
    bool verifyPin();
    bool createAccount();
    void displayAccount();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    string getAccNo();
    void saveToFile(ofstream &file);
    bool loadFromFile(ifstream &file);
};

// Default constructor
Account::Account()
{
    holderName = "";
    accNo = "";
    pin = -1;
    balance = 0;
    isBlocked = false;
    failedAttempts = 0;
    isCreated = false;
}

// Member function to verify the PIN
bool Account::verifyPin()
{
    int enteredPin;

    if (isBlocked)
    {
        cout << "Account is temporarily blocked. Please contact your bank.\n";
        return false;
    }

    do
    {
        // Take pin from the user
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) // if the pin entered by the user is correct, return true bcz the pin is verified.
        {
            failedAttempts = 0;
            return true;
        }

        failedAttempts++;
        cout << "Incorrect PIN!\n";
        cout << 3 - failedAttempts << " attempts remaining.\n";

    } while (enteredPin != pin && failedAttempts < 3);

    if (failedAttempts >= 3)
    {
        isBlocked = true;
        cout << "Account temporarily blocked due to multiple incorrect PIN attempts.\n";
    }
    return false;
}

// Member function to create an account
bool Account::createAccount()
{
    isCreated = false;
    int pin1, pin2;
    int count = 0;

    cout << "\nEnter your bank account number: ";
    cin >> ws;
    getline(cin, accNo);

    cout << "Enter your name: ";
    getline(cin, holderName);

    do
    {

        cout << "Set your PIN (4-digit): ";
        cin >> pin1;

        cout << "Re-enter the same PIN: ";
        cin >> pin2;

        if (pin1 == pin2 && pin1 >= 1000 && pin1 <= 9999)
        {

            pin = pin1;
            isCreated = true;

            cout << "\nPIN set successfully!\n";
            cout << "Account created successfully!\n";
            return true;
        }
        else
        {
            cout << "Invalid PIN! Both PINs must match and contain exactly 4 digits.\n";
        }

        count++;

    } while (count < 3);

    if (!isCreated)
    {
        cout << "Account creation failed because the entered PINs do not match.\n";
    }
    return false;
}

// Member function to display account details
void Account::displayAccount()
{

    if (!isCreated)
    { // If the account is not created with that number display that is doesn't exist.
        cout << "No such account exists.\n";
        return;
    }

    cout << "\n====== ACCOUNT HOLDER DETAILS ======\n";
    cout << "Account holder name: " << holderName << endl;
    cout << "Account number: " << accNo << endl;
    cout << "Account balance: " << balance << " Rs.\n";
}

// Member function to deposit money
void Account::depositMoney()
{

    if (!isCreated)
    {
        cout << "Create an account first!\n";
        return;
    }

    cout << "\n========= DEPOSIT MONEY =========\n";

    long long amount;

    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount > 0)
    {

        balance += amount;

        cout << "Amount deposited successfully!\n";
        cout << "Current balance: " << balance << " Rs.\n";
    }
    else
    {
        cout << "Invalid deposit amount!\n";
    }
}

// Member function to withdraw money
void Account::withdrawMoney()
{

    if (!isCreated)
    {
        cout << "Create an account first!\n";
        return;
    }

    long long money;

    cout << "\n========= WITHDRAW MONEY =========\n";

    cout << "Enter the amount to withdraw: ";
    cin >> money;

    if (money > 0 && money <= balance)
    {

        balance -= money;

        cout << "Amount withdrawn successfully!\n";
        cout << "Collect your money.\n";
        cout << "Current balance: " << balance << " Rs.\n";
    }
    else
    {
        cout << "Invalid amount or insufficient balance!\n";
        cout << "No amount deducted from your account.\n";
    }
}

// Member function to check account balance
void Account::checkBalance()
{

    if (!isCreated)
    {
        cout << "Create an account first!\n";
        return;
    }

    cout << "\n========= CHECK BALANCE =========\n";

    cout << "Your account balance is: " << balance << " Rs.\n";

    cout << "Thank you for using our ATM services!\n";
}

string Account::getAccNo()
{
    return accNo;
}

// Function to save an individual account's details into a file
// The '|' symbol is used to separate different data members.
void Account::saveToFile(ofstream &file)
{
    file << accNo << "|"
         << holderName << "|"
         << pin << "|"
         << balance << "|"
         << isBlocked << "\n";
}

// Function to read account details from a file
// It extracts the stored information and assigns it to the object's data members.
bool Account::loadFromFile(ifstream &file)
{   // Read one complete line containing the account details
    string line;

    if (!getline(file, line))
        return false;

    // Create a stringstream to extract individual values from the line
    stringstream data(line);

    // Temporary strings used to read numeric values before conversion
    string pinValue, balanceValue, blockedValue;

    getline(data, accNo, '|');
    getline(data, holderName, '|');
    getline(data, pinValue, '|');
    getline(data, balanceValue, '|');
    getline(data, blockedValue, '|');

    if (accNo.empty() || pinValue.empty() || balanceValue.empty())
        return false;

// Convert the stored string values into their respective data types
pin = stoi(pinValue);
balance = stoll(balanceValue);

// Restore the account's blocked status
isBlocked = (blockedValue == "1");

// Reset failed attempts when the program is restarted
failedAttempts = 0;

// Mark the loaded account as an existing account
isCreated = true;

    return true;
}

// Function to save all accounts stored in the vector into the file
void saveAccounts(vector<Account> &accounts)
{// Open the file in output mode to write account records
// Existing contents are replaced with the latest account records
ofstream file("accounts.txt");

    if (!file)
    {
        cout << "Error saving account records!\n";
        return;
    }

    for (int i = 0; i < accounts.size(); i++)
    {
        accounts[i].saveToFile(file);
    }

    file.close();
}

// Function to load previously saved accounts from the file into the vector
// If the file does not exist, the program starts with an empty account list.
void loadAccounts(vector<Account> &accounts)
{// Open the file in input mode to read previously saved records
ifstream file("accounts.txt");

    if (!file)
        return;
// Create a temporary Account object to hold each loaded record
Account temp;

// Read records one by one until no more records are available
while (temp.loadFromFile(file))
{
    accounts.push_back(temp);

    // Reset the temporary object before loading the next record
    temp = Account();
}

    file.close();
}

int main()
{
    // Vector to store multiple account objects
    vector<Account> accounts;

    // Load previously saved accounts when the program starts
    loadAccounts(accounts);

    int choice;

    cout << "====== ATM MANAGEMENT SYSTEM ======\n";

    // Display the main menu repeatedly until the user chooses to exit
    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Create New Account\n";
        cout << "2. Login to Account\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
case 1:
{
    // Create a temporary object for the new account
    Account newAccount;

    // Create the account and check whether the account number already exists

            if (newAccount.createAccount())
            {// Check whether another account already exists with the same account number
bool exists = false;

                for (int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i].getAccNo() == newAccount.getAccNo())
                    {
                        exists = true;
                        break;
                    }
                }

                if (exists)
                {
                    cout << "An account with this number already exists!\n";
                }
                else
                {// Add the newly created account to the vector
accounts.push_back(newAccount);

// Save all account records to the file
saveAccounts(accounts);
                    cout << "Account saved successfully!\n";
                }
            }

            break;
        }
        case 2:
        {// Take the account number to identify the account
            string enteredAccNo;
            bool found = false;

            cout << "\nEnter your account number: ";
            cin >> ws;
            getline(cin, enteredAccNo);

            // Search for the account number in the vector
            for (int i = 0; i < accounts.size(); i++)
            {
                if (accounts[i].getAccNo() == enteredAccNo)
                {
                    found = true;

                    cout << "\nAccount found!\n";

                    // Verify the PIN before allowing access to ATM services
                    if (accounts[i].verifyPin())
                    {
                        int atmChoice;

                        do
                        {
                            // Display account-specific services after successful login
                            cout << "\n========== ATM SERVICES ==========\n";
                            cout << "1. Deposit Money\n";
                            cout << "2. Withdraw Money\n";
                            cout << "3. Check Balance\n";
                            cout << "4. Display Account Details\n";
                            cout << "0. Logout\n";

                            cout << "Enter your choice: ";
                            cin >> atmChoice;

                            switch (atmChoice)
                            {
                            case 1:
                                accounts[i].depositMoney();
                                break;

                            case 2:
                                accounts[i].withdrawMoney();
                                break;

                            case 3:
                                accounts[i].checkBalance();
                                break;

                            case 4:
                                accounts[i].displayAccount();
                                break;

                            case 0:
                                cout << "Logged out successfully!\n";
                                break;

                            default:
                                cout << "Invalid choice!\n";
                            }
                            
                            // Update the file after every ATM operation to preserve the latest balance
                            saveAccounts(accounts);

                        } while (atmChoice != 0);
                    }

                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!\n";
            }

            break;
        }

        case 0:
            cout << "Thank you for using our ATM services!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
