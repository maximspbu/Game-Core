#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include "object.h"

class Item: public Object{
    friend class Location;
    friend class Character;
    friend class Merchant;
    friend class Fight;
    protected:

    public:
        Item(std::string);
        void stats_output();
        ~Item(){};
};
