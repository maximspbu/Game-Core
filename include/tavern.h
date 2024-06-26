#ifndef TAVERN_H
#define TAVERN_H

#include "screen.h"
#include "shop.h"

class Tavern:public Location, public Shop{
    protected:
        int recovery_price;
    public:
        Tavern(const std::vector<std::vector<std::string>>& list_file, int recovery_price_);
        void EntranceScreen(Party&) override;
        void Buy(Party& party);
        void Recovery(Party& party); //party
};

#endif //TAVERN_H
