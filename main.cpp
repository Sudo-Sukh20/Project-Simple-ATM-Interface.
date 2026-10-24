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
        pin = -1;
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
        cout<<"======ACCOUNT HOLDER'S DETAILS======\n";
        cout<<"Account holder's name:"<<holderName<<endl;
        cout<<"Account number:"<<accNo<<endl;
        cout<<"Account balance:"<<balance<<endl;
    }


    // Member function to deposit money 
    void depositMoney() {
        int amount;
        int givenPin;
        if(pin !=-1){
            cout<<"Enter your pin:";
            cin>>givenPin;
            if(pin==givenPin){
                cout<<"Enter the amount to deposit:";
                cin>>amount;
                balance+=amount;
                cout<<"Amount deposited succesfully!"<<endl;
                cout<<"Your current balance is:"<<balance<<"Rs."<<endl;
            }else{
                cout<<"Incorrect pin! Please try again."<<endl;
            }
        }else{
            cout<<"You need to create an account first!"<<endl;
        }
        

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
    Account acc1, acc2;

    // Create accounts for two users
    cout << "Creating account for User 1:\n";
    acc1.createAccount();

    cout << "\nCreating account for User 2:\n";
    acc2.createAccount();

    // Display account details
    cout << "\nDisplaying account details for User 1:\n";
    acc1.displayAccount();

    cout << "\nDisplaying account details for User 2:\n";
    acc2.displayAccount();

    return 0;
}
