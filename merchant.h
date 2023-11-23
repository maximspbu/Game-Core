#pragma once
#include "location.h"
#include "shop.h"
#include <map>

class Merchant: public Location, public Shop{
    protected:
    public:
        Merchant(const std::vector<std::vector<std::string>>& file_list); //private
        void entrance_screen(Party&) override;
        void buy(Party&);
};
