#ifndef TAVERN_H
#define TAVERN_H
#include "party.h"
class Tavern{
    protected:
        struct Goods{
            std::vector<Hero> heroes;
        } goods;
    public:
        Tavern(Goods goods); //private
        void enterance_screen();
        void recovery(Party_player& party); //party
        void price_list_heroes(Goods goods); //party
        void buy_hero(Party_player& party);
};
#endif