#ifndef SHOP_H
#define SHOP_H


#include "party.h"

class Shop{
    public:
        void PriceList(const std::vector<std::vector<std::string>>& list_file);
        void ReadFile(std::string file_name, std::map<std::string, std::string>& description, std::map<std::string, int>& stats);
        int Choice();
        void Buy(Party&, Object*);
    protected:
        int turn;
        int player_choice;
};

#endif //SHOP_H
