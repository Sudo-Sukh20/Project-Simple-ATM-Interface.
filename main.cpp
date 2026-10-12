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
    // object creation for different atm users

    return 0;
}
