#pragma once
#include "armor_char.h"
#include "weapon.h"
#include "consumables.h"
#include "spell.h"
#include <vector>

class Merchant{
    protected:
        struct Goods{
            std::vector<Armor> armor;
            std::vector<Weapon> weapon;
            std::vector<Consumables> consumables;
            std::vector<Spell> spell;
        } goods;
    public:
        Merchant(Goods goods); //private
        void enterance_screen();
        void price_list_armor();
        void buy_armor(); //inventory
        void price_list_weapon();
        void buy_weapon(); //inventory
        void price_list_consumables();
        void buy_consumables(); //inventory
        void price_list_spells();
        void buy_spell();
};
