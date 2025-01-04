#include "BankAccount.hpp"

int main() {
    // Create a BankAccount object
    BankAccount account("John Doe", 12345678, 500.0);

    // Perform some transactions
    account.deposit(200.0);
    account.withdraw(150.0);
    account.withdraw(700.0);

    // Display the balance and transaction history
    account.displayBalance();
    account.displayTransactionHistory();

    // Destructor will be called automatically when account goes out of scope
    return 0;
}
