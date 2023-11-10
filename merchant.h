#pragma once
#include "location.h"
#include <map>

class Merchant: public Location{
    protected:
        std::vector<std::vector<std::string>> list_items;
    public:
        Merchant(std::vector<std::vector<std::string>>); //private
        void entrance_screen(Party_player&) override;
        void price_list(int);
        void buy(int, Party_player&);
};
