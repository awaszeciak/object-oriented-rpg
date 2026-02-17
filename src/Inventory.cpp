#include "Inventory.h"
#include "Colors.h"
#include <iostream>

Inventory::Inventory():
    _items() {
        #ifdef DEBUG
            std::cout << "[DEBUG][Inventory] Constructor\n";
        #endif
    }

Inventory::~Inventory() {
    _items.clear();
    #ifdef DEBUG
        std::cout << "[DEBUG][Inventory] Destructor\n";
    #endif
}

void Inventory::add(const Item& item) {
    _items.push_back(item);
    #ifdef DEBUG
        std::cout << "[DEBUG][Inventory] Added: " << item.getName() << "\n";
    #endif
}

void Inventory::show() const {
    std::cout << MAGENTA << "\n=== Inventory ===\n" << RESET;
    for (size_t i = 0; i < _items.size(); ++i) {
        std::cout << _items[i].getName() << " (DMG: " << _items[i].getDamage() << ", " << "Value: "<< _items[i].getValue() <<")\n";
    }

}