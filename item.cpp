#include "Item.h"
#include <iostream>

Item::Item(int id, std::string name, int quantity, double price)
    : id(id), name(name), quantity(quantity), price(price) {}


int Item::getId() const { return id; }
std::string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
double Item::getPrice() const { return price; }

void Item::setName(const std::string& newName) { this->name = newName; }
void Item::setQuantity(int newQuantity) { this->quantity = newQuantity; }
void Item::setPrice(double newPrice) { this->price = newPrice; }

void Item::display() const {
    std::cout << "  ID: " << id << ", Nama: " << name
              << ", Kuantitas: " << quantity << ", Harga: " << price << std::endl;
}