#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const throw() {
        return "Error: Insufficient funds for this withdrawal.";
    }
};

class InvalidAmountException : public exception {
public:
    const char* what() const throw() {
        return "Error: Invalid amount for withdrawal. Amount cannot be negative.";
    }
};

class BankAccount {
private:
    double balance;
public:
    BankAccount(double initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative.");
        }
        balance = initialBalance;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw InvalidAmountException();
        } else if (amount > balance) {
            throw InsufficientFundsException();
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        }
    }

    // Getter
    double getBalance() const {
        return balance;
    }
};

int main() {
    double initialBalance = 1000;
    BankAccount account(initialBalance);

    double withdrawalAmount;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawalAmount;

    try {
        account.withdraw(withdrawalAmount);
    } catch (const InsufficientFundsException &e) {
        cout << e.what() << endl;
    } catch (const InvalidAmountException &e) {
        cout << e.what() << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
