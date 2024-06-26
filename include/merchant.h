#ifndef MERCHANT_H
#define MERCHANT_H

#include "location.h"
#include "shop.h"


class Merchant: public Location, public Shop{
    protected:
    public:
        Merchant(const std::vector<std::vector<std::string>>& file_list); //private
        void EntranceScreen(Party&) override;
        void Buy(Party&);
};

#endif //MERCHANT_H
