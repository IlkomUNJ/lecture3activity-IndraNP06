#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Seller {
private:
    int id;
    std::string name;
    int bankAccountId;
    std::vector<Item> stock;

public:
    Seller(int id, std::string name, int bankAccountId);

    void addItemToStock(const Item& newItem);
    
    Item* findItemById(int itemId);

    void displayStock() const;
};