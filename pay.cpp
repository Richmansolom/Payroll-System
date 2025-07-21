#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account 
{
private:
    int id;
    double balance;
    double annualInterestRate;

public: 
    Account() {
        id = 0;
        balance = 0;
        annualInterestRate = 0;
    }

    int getID() const {
        return id;
    }

    double getBalance() const {
        return balance;
    }

    double getAnnualInterestRate() const {
        return annualInterestRate;
    }

    void setID(int id) {
        this->id = id;
    }

    void setBalance(double bal) {
        if (bal > 0)
            balance = bal;
        else
            cout << "Error: Initial balance must be positive.\n";
    }

    void setAnnualInterestRate(double rate) {
        if (rate > 0)
            annualInterestRate = rate;
        else
            cout << "Error: Annual interest rate must be positive.\n";
    }

    double getMonthlyInterestRate() const {
        return annualInterestRate / 12;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive.\n";
        } else if (amount > balance) {
            cout << "Sorry, you have insufficient funds.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Error: Deposit amount must be positive.\n";
        }
    }

    double getMonthlyInterest() const {
        return getMonthlyInterestRate() * getBalance() / 100;
    }
};

int main() 
{
    Account myAccount;
    myAccount.setID(2563);
    myAccount.setBalance(80000);
    myAccount.setAnnualInterestRate(4.5);

    cout << fixed << setprecision(2);
    cout << "==== Account Summary ====\n";
    cout << "Account ID: " << myAccount.getID() << endl;
    cout << "Balance: $" << myAccount.getBalance() << endl;
    cout << "Annual Interest Rate: " << myAccount.getAnnualInterestRate() << "%\n";
    cout << "Monthly Interest: $" << myAccount.getMonthlyInterest() << "\n\n";

    cout << "Attempting to withdraw $2500...\n";
    myAccount.withdraw(2500);
    cout << "New Balance: $" << myAccount.getBalance() << endl;
    cout << "Monthly Interest: $" << myAccount.getMonthlyInterest() << "\n\n";

    cout << "Attempting to deposit $3000...\n";
    myAccount.deposit(3000);
    cout << "New Balance: $" << myAccount.getBalance() << endl;
    cout << "Monthly Interest: $" << myAccount.getMonthlyInterest() << "\n";

    return 0;
}

