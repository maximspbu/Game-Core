#pragma once
#include <string>

class Weapon{ 
    //weapon attack, crit rate, enemy type (deals more damage for specific enemies)
    friend class Merchant;
    protected:
        int weapon_attack;
        int crit_rate;
        int price;
        int type; //0 - no weapon
        std::string name;
        int used = 0;
        struct Stats{
            int weapon_attack=this->weapon_attack;
            int crit_rate=this->crit_rate;
            int price=this->price;
            int type=this->type; //0 - no weapon
            std::string name=this->name;
            int used = this->used;
        } stats;
    public:
        friend class Character;
        Weapon(Stats stats);
        Stats get_stats();
};
