#pragma once
#include <string>

class BankCustomer {
private:
    int id;
    std::string name;
    double saving;

public:
    BankCustomer(int customerId, std::string customerName, double initialSaving);
    int getId() const;
    std::string getName() const;
    double getSaving() const;

    // Metode untuk transaksi
    void deposit(double amount);
    bool withdraw(double amount);

    // Metode untuk display
    void display() const;
};