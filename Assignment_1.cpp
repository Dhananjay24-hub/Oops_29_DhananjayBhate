#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string name;
    string accountNo;
    double balance;
    int pin;

public:
    // Updated constructor with balance
    BankAccount(string n, string accNo, int p, double initialBalance) {
        name = n;
        accountNo = accNo;
        pin = p;
        balance = initialBalance >= 0 ? initialBalance : 0;
    }

    string getAccountNo() {
        return accountNo;
    }

    bool verifyPin(int enteredPin) {
        return (enteredPin == pin);
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void getDetails() {
        cout << "----- Account Details -----\n";
        cout << "Name       : " << name << endl;
        cout << "Account No : " << accountNo << endl;
        cout << "Balance    : ₹" << balance << endl;
    }
};

// Search function
int findAccount(vector<BankAccount>& accounts, string accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNo() == accNo)
            return i;
    }
    return -1;
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n====== BANKING SYSTEM MENU ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Search Account\n";
        cout << "5. Get Account Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string accNo;
        int pin;

        switch (choice) {
            case 1: {
                string name;
                double initialBalance;

                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter New Account Number: ";
                cin >> accNo;

                cout << "Set 4-digit Security PIN: ";
                cin >> pin;

                cout << "Enter Initial Balance: ";
                cin >> initialBalance;

                if (findAccount(accounts, accNo) == -1) {
                    accounts.emplace_back(name, accNo, pin, initialBalance);
                    cout << "Account created successfully!\n";
                } else {
                    cout << "Account number already exists!\n";
                }
                break;
            }

            case 2: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                int index = findAccount(accounts, accNo);
                if (index != -1) {
                    cout << "Enter PIN: ";
                    cin >> pin;
                    if (accounts[index].verifyPin(pin)) {
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        accounts[index].deposit(amount);
                    } else {
                        cout << "Incorrect PIN!\n";
                    }
                } else {
                    cout << "Account not found!\n";
                }
                break;
            }

            case 3: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                int index = findAccount(accounts, accNo);
                if (index != -1) {
                    cout << "Enter PIN: ";
                    cin >> pin;
                    if (accounts[index].verifyPin(pin)) {
                        double amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        accounts[index].withdraw(amount);
                    } else {
                        cout << "Incorrect PIN!\n";
                    }
                } else {
                    cout << "Account not found!\n";
                }
                break;
            }

            case 4: {
                cout << "Enter Account Number to search: ";
                cin >> accNo;
                if (findAccount(accounts, accNo) != -1)
                    cout << "Account found!\n";
                else
                    cout << "Account not found!\n";
                break;
            }

            case 5: {
                cout << "Enter Account Number: ";
                cin >> accNo;
                int index = findAccount(accounts, accNo);
                if (index != -1) {
                    cout << "Enter PIN: ";
                    cin >> pin;
                    if (accounts[index].verifyPin(pin)) {
                        accounts[index].getDetails();
                    } else {
                        cout << "Incorrect PIN!\n";
                    }
                } else {
                    cout << "Account not found!\n";
                }
                break;
            }

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}