#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "object.h"

class Item: public Object{
    friend class Location;
    friend class Character;
    friend class Merchant;
    friend class Fight;
    protected:

    public:
        Item(std::string&);
        void StatsOutput();
        ~Item(){};
};

#endif //ITEM_H
