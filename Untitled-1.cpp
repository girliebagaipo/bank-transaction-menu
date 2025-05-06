#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Structure to represent a bank account
struct Account {
    string accountNumber;
    string accountHolderName;
    double balance;
};

// Function to create a new account
Account createAccount() {
    Account newAccount;
   

    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter account holder name: ";
    cin.ignore(); // Consume newline character left in the buffer
    getline(cin, newAccount.accountHolderName);
    cout << "Enter initial balance: ";
    cin >> newAccount.balance;
    return newAccount;
}

// Function para magdeposit
void deposit(vector<Account>& accounts, string accountNumber) {
    for (Account& account : accounts) {
        if (account.accountNumber == accountNumber) {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.balance += amount;
            cout << "Deposit successful. New balance: " << account.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function para magwithdraw
void withdraw(vector<Account>& accounts, string accountNumber) {
    for (Account& account : accounts) {
        if (account.accountNumber == accountNumber) {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            if (amount <= account.balance) {
                account.balance -= amount;
                cout << "Withdrawal successful. New balance: " << account.balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to display account details
void displayAccount(vector<Account>& accounts, string accountNumber) {
    for (const Account& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Account Number: " << account.accountNumber << endl;
            cout << "Account Holder Name: " << account.accountHolderName << endl;
            cout << "Balance: " << account.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

void clearScreen() {
    // to clear
        system("cls");
    
}

int main() {
    vector<Account> accounts; // Vector to store bank accounts

    int choice;
    do {

        cout << "\nBank Transaction Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        

        switch (choice) {
             
            case 1:
                accounts.push_back(createAccount());
                clearScreen();
                break;

            case 2: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                deposit(accounts, accountNumber);
                break;
            }
            case 3: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                withdraw(accounts, accountNumber);
                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                displayAccount(accounts, accountNumber);
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

                if (!(cin >> choice)) {
            // If the input is not a valid integer (string or other non-numeric input)
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a numeric choice." << endl;
            continue; // Ask the user for the input again

    
        }
        }
    } while (choice != 5);
       
    
    return 0;
}