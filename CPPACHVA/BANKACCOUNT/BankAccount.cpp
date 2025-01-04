#include "BankAccount.hpp"
#include <iostream>

// Constructor implementation
BankAccount::BankAccount(const std::string& holder, int number, double initialBalance)
    : accountHolder(holder), accountNumber(number), balance(initialBalance),
      transactionCount(0), transactionCapacity(INITIAL_CAPACITY) {
    // Allocate initial memory for transaction history
    transactionHistory = new Transaction[transactionCapacity];
}

// Destructor implementation
BankAccount::~BankAccount() {
    // Print message indicating the account is being closed
    std::cout << "Account " << accountNumber << " for " << accountHolder << " is closed.\n";
    // Free the memory allocated for transaction history
    delete[] transactionHistory;
}

// Method to resize the transaction history array when full
void BankAccount::resizeTransactionHistory() {
    // Double the capacity
    transactionCapacity *= 2;
    // Allocate new memory with the increased capacity
    Transaction* newHistory = new Transaction[transactionCapacity];
    // Copy old transactions to the new array
    for (int i = 0; i < transactionCount; ++i) {
        newHistory[i] = transactionHistory[i];
    }
    // Delete the old array
    delete[] transactionHistory;
    // Update the pointer to the new array
    transactionHistory = newHistory;
}

// Method to deposit money into the account
void BankAccount::deposit(double amount) {
    // Increase balance by the deposit amount
    balance += amount;
    // Check if the transaction history array is full
    if (transactionCount == transactionCapacity) {
        resizeTransactionHistory();
    }
    // Add the new transaction to the history
    transactionHistory[transactionCount++] = Transaction("Deposit", amount);
    // Print the new balance
    std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
}

// Method to withdraw money from the account
void BankAccount::withdraw(double amount) {
    // Check if there are sufficient funds for the withdrawal
    if (amount > balance) {
        std::cout << "Insufficient funds for withdrawal.\n";
    } else {
        // Decrease balance by the withdrawal amount
        balance -= amount;
        // Check if the transaction history array is full
        if (transactionCount == transactionCapacity) {
            resizeTransactionHistory();
        }
        // Add the new transaction to the history
        transactionHistory[transactionCount++] = Transaction("Withdrawal", amount);
        // Print the new balance
        std::cout << "Withdrew $" << amount << ". New balance: $" << balance << std::endl;
    }
}
 

// Constant method to display the transaction history
void BankAccount::displayTransactionHistory() const {
    std::cout << "Transaction History for Account " << accountNumber << ":\n";
    // Loop through each transaction and print its details
    for (int i = 0; i < transactionCount; ++i) {
        std::cout << transactionHistory[i].type << ": $" << transactionHistory[i].amount << std::endl;
    }
}
