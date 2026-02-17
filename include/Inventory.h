#pragma once
#include "Item.h"
#include <vector>

class Inventory{
    private:
        std::vector<Item> _items; 

    public:
        Inventory();
        ~Inventory();

        void add(const Item&);
        void show() const;

};