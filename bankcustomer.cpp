#include "bankcustomer.h"
#include <iostream>

BankCustomer::BankCustomer(int customerId, std::string customerName, double initialSaving)
    : id(customerId), name(customerName), saving(initialSaving) {}

int BankCustomer::getId() const { return id; }
std::string BankCustomer::getName() const { return name; }
double BankCustomer::getSaving() const { return saving; }

void BankCustomer::deposit(double amount) {
    if (amount > 0) {
        saving += amount;
    }
}
bool BankCustomer::withdraw(double amount) {
    if (amount > 0 && saving >= amount) {
        saving -= amount;
        return true; 
    }
    return false;
}

void BankCustomer::display() const {
    std::cout << "  ID Akun: " << id << ", Nama: " << name
              << ", Saldo: Rp" << saving << std::endl;
}