#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <iostream>
#include <string>
//change
// Structure to hold details of a transaction
struct Transaction {
    
    std::string type;  // Type of transaction (e.g., "Deposit", "Withdrawal")
    double amount;     // Amount of money in the transaction

    // Default constructor
    Transaction() : type("Unknown"), amount(0.0) {}

    // Constructor to initialize transaction details
    Transaction(const std::string& t, double a)
        : type(t), amount(a) {}
};

// Class to represent a bank account
class BankAccount {
private:
    
    static const int INITIAL_CAPACITY = 10;
    std::string accountHolder;    // Name of the account holder
    int accountNumber;            // Unique account number
    double balance;               // Current balance of the account
    Transaction* transactionHistory;  // Array to store transaction history
    int transactionCount;         // Number of transactions recorded
    int transactionCapacity;      // Current capacity of the transaction history array

     
    // Function to resize the transaction history array when it's full
    void resizeTransactionHistory();

public:
    // Constructor with initializer list to set up account details
    BankAccount(const std::string& holder, int number , double initialBalance );

    // Destructor to clean up resources when the object is destroyed
    ~BankAccount();

    // Method to deposit money into the account
    void deposit(double amount);

    // Method to withdraw money from the account
    void withdraw(double amount);

    // Inline method to display the current balance (does not modify the object)
    inline void displayBalance() const {
        std::cout << "Current balance: $" << balance << std::endl;
    }

    // Constant method to display the transaction history (does not modify the object)
    void displayTransactionHistory() const;
};

#endif // BANKACCOUNT_HPP
