#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "item.h"
/*
// statuses: death, petrifaction, poison, blind, paralysis, sleep, silence, confuse
class Elements{
    public: // elements: status, poison/stone, time, death, fire, ice, lightning, earth, non-elemental
    private:
};

class heal_magic : Spell{
    public:// hp recovery e...2e
    private:
};

class attack_magic : Spell{
    public://damage = e...2e (unresisted attack spell 2*(e...2e))
    private:
};*/

class Inventory{ //quest items, armor, weapon, spells
    // increase armor, damage, hp, speed, crit rate and etc.; item to complete quest
    friend class Party_player;
    friend class Merchant;
    friend class Equipment;
    protected:
        std::map<std::string, std::vector<Item>> inventory_player;
        
    public:
        Inventory();
        Item* get_inventory(std::string, int);
        void entrance_screen();
};
