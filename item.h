#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>

class Item{
    friend class Location;
    friend class Character;
    friend class Merchant;
    protected:
        std::map<std::string, int> stats;
    public:
        std::string name;
        std::string brief;
        Item(std::string);
        void stats_output();
        int get_stat(std::string stat);
        ~Item(){};
};
