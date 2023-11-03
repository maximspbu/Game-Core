#ifndef ARMOR_CHAR_H
#define ARMOR_CHAR_H
#include <string>
class Armor{
    // defense, weight
    friend class Character;
    protected:
        struct Stats{
            int defense;
            int weight;
            int price;
            int type; //0 - no weapon
            std::string name;
            int used = 0;
        } stats;
    public:
        
        Armor(Stats stats_l);
        Stats get_stats();
};
#endif