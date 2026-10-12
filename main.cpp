#include <iostream>
#include <string>
using namespace std;

class Account{
    // private data members
    string holderName;
    string accNo;
    int pin;
    long long balance;

public:
    // public member functions

    // Default constructor to initialize the atm of an user with default values
    Account() {
        holderName = "";
        accNo = "";
        int pin = -1;
        balance = 0;
    }

    // Member function to create an atm for a bank account user
    void createAccount() {
        int pin1, pin2; // variables to match the first and the re-entered verification pin by the user 
        int count = 0;  // variable for checking how many time user tried to set the pin

        cout << "Enter your bank account number: ";
        getline(cin, accNo);

        cout << "Enter your name: ";
        getline(cin, holderName);

        do {
            cout << "Set your PIN (4 - digit): ";
            cin >> pin1;
    
            cout << "Re-Enter the same PIN: ";
            cin >> pin2;
    
            if(pin1 == pin2) {
                pin = pin1;   // if the user entered the same pin both times, set the pin.
                cout << "\nPIN has been set successfully!\n";
                cout << "You may remove the card.\n";

            } else {
                cout << "\nWarning: You needed to enter the same PIN again.\n";
            }
            count++;
            
        } while (pin1 != pin2 && count < 3);

        // If the user entered incorrect PINs more than three times, temporarily block the card.
        if(count >= 3) {
            cout << "Your card is temporarily blocked due to entering of wrong PIN multiple times.\nYou may need to contact your bank for assistance.\n";
        }

    }

    // Member function to display the account details
    void displayAccount() {

    }


    // Member function to deposit money 
    void depositMoney() {

    }

    // Member function to withdraw money
    void withdrawMoney() {

    }

    // Member function to display account holder's balance
    void checkBalance() {

    }
};

int main() {
    //Account object creation for different ATM users
    Account a;
    a.createAccount();

    return 0;
}
