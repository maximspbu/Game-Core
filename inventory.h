#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <iostream>
#include <vector>
#include "quest_items.h"
#include "weapon.h"
#include "armor_char.h"
#include "consumables.h"
#include "spell.h"


//weapons
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
    protected:
        struct Inventory_player{
            std::vector<std::vector<Armor>> armor;
            std::vector<Weapon> weapon;
            std::vector<Spell> spell;
            std::vector<Consumables> consumables;
            std::vector<Quest_items> quest_item;
        } inventory_player;
        
    public:
        Inventory(Inventory_player intentory_player);
        Inventory_player get_inventory();
        void enterance_screen();
};
#endif