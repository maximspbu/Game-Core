#pragma once
#include "party.h"
#include "screen.h"
#include "location.h"

class Tavern:public Location{
    protected:
        std::vector<std::vector<std::string>> list_items;
    public:
        Tavern(std::vector<std::vector<std::string>>); //private
        void entrance_screen(Party_player&) override;
        void price_list();
        void buy(Party_player& party);
        void recovery(Party_player& party); //party
};
