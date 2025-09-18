#include "seller.h"
#include <iostream>

Seller::Seller(int id, std::string name, int bankAccountId)
    : id(id), name(name), bankAccountId(bankAccountId) {}

void Seller::addItemToStock(const Item& newItem) {
    stock.push_back(newItem);
    std::cout << "Notifikasi: Item '" << newItem.getName() << "' berhasil ditambahkan ke stok '" << this->name << "'." << std::endl;
}

Item* Seller::findItemById(int itemId) {
    for (size_t i = 0; i < stock.size(); ++i) {
        if (stock[i].getId() == itemId) {
            return &stock[i];
        }
    }
    return nullptr; 
}

void Seller::displayStock() const {
    std::cout << "\n--- Stok Milik Seller: " << this->name << " ---" << std::endl;
    if (stock.empty()) {
        std::cout << "Stok kosong." << std::endl;
    } else {
        for (const auto& item : stock) {
            item.display();
        }
    }
    std::cout << "-------------------------------------\n" << std::endl;
}