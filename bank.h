#pragma once
#include <vector>
#include "BankCustomer.h"

class Bank {
private:
    std::vector<BankCustomer> accounts;
    BankCustomer* findAccountById(int accountId);

public:
    Bank();
    void addAccount(const BankCustomer& newCustomer);
    bool processTransfer(int fromAccountId, int toAccountId, double amount);
    void displayAllAccounts() const;
};