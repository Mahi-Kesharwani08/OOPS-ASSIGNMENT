#include <iostream>
#include <exception>
using namespace std;

// Base exception class (inherits from std::exception)
class BankException : public exception {
public:
    const char* what() const noexcept override {
        return "Bank Error";
    }
};

// Derived exception: not enough money
class InsufficientBalanceException : public BankException {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance!";
    }
};

// Derived exception: negative or zero amount
class InvalidAmountException : public BankException {
public:
    const char* what() const noexcept override {
        return "Invalid Amount!";
    }
};

class Account {
    double balance;
public:
    Account() { balance = 5000; }

    void deposit(double amt) {
        if (amt <= 0)
            throw InvalidAmountException();
        balance += amt;
    }

    void withdraw(double amt) {
        if (amt <= 0)
            throw InvalidAmountException();
        if (amt > balance)
            throw InsufficientBalanceException();
        balance -= amt;
    }

    double getBalance() { return balance; }
};

int main() {
    Account acc;
    int choice;
    double amount;

    do {
        cout << "\n--- BANKING MENU ---" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                acc.deposit(amount);
                cout << "Amount Deposited Successfully." << endl;
            }
            else if (choice == 2) {
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                acc.withdraw(amount);
                cout << "Amount Withdrawn Successfully." << endl;
            }
            else if (choice == 3) {
                cout << "Current Balance: Rs. " << acc.getBalance() << endl;
            }
            else if (choice != 0) {
                cout << "Invalid choice!" << endl;
            }
        }
        catch (InsufficientBalanceException &e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (InvalidAmountException &e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (BankException &e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    cout << "Thank you!" << endl;
    return 0;
}