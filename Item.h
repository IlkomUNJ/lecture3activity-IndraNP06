#pragma once
#include <string>
// No longer need <optional>

class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    Item(int id, std::string name, int quantity, double price);

    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    
    void setName(const std::string& newName);
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);

    void display() const;
};