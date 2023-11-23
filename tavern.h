#pragma once
#include "party.h"
#include "screen.h"
#include "location.h"
#include "shop.h"

class Tavern:public Location, public Shop{
    protected:
        int recovery_price;
    public:
        Tavern(const std::vector<std::vector<std::string>>& file_list, int); //private
        void entrance_screen(Party&) override;
        void buy(Party& party);
        void recovery(Party& party); //party
};
