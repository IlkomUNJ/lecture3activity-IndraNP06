#include "bank.h"
#include <iostream>

Bank::Bank() {}

BankCustomer* Bank::findAccountById(int accountId) {
    for (auto& account : accounts) {
        if (account.getId() == accountId) {
            return &account; 
        }
    }
    return nullptr; 
}

void Bank::addAccount(const BankCustomer& newCustomer) {
    accounts.push_back(newCustomer);
}

bool Bank::processTransfer(int fromAccountId, int toAccountId, double amount) {
    BankCustomer* sender = findAccountById(fromAccountId);
    BankCustomer* receiver = findAccountById(toAccountId);

    if (sender == nullptr || receiver == nullptr) {
        std::cout << "Error Transfer: Salah satu akun tidak valid." << std::endl;
        return false;
    }

    if (sender->withdraw(amount)) { 
        receiver->deposit(amount);
        std::cout << "Notifikasi: Transfer sebesar Rp" << amount << " dari "
                  << sender->getName() << " ke " << receiver->getName() << " berhasil." << std::endl;
        return true;
    } else {
        std::cout << "Error Transfer: Saldo " << sender->getName() << " tidak mencukupi." << std::endl;
        return false;
    }
}

void Bank::displayAllAccounts() const {
    std::cout << "\n--- Daftar Akun Bank ---" << std::endl;
    if (accounts.empty()) {
        std::cout << "Tidak ada akun terdaftar." << std::endl;
    } else {
        for (const auto& account : accounts) {
            account.display();
        }
    }
    std::cout << "--------------------------\n" << std::endl;
}