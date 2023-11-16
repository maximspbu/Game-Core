#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "character.h"
#include "inventory.h"

class Party_player{ //party player
    // stats of game: time, score, money, inventory, heroes count, (save)
    // stats of characters hp, exp, mp, defense, damage, crit rate, crit multiply, speed, steal hp, inventory (used armor, weapons)
    friend class Merchant;
    friend class Tavern;
    friend class Equipment;
    friend class Fight;
    //friend class Screen;
    protected:
        struct Stats{
            int money;
            int cur_heroes_count=0;
            int heroes_count=4;
            std::vector<Character> party;
            Inventory inventory;
        } stats;
    public:
        Party_player();
        void add_character(Character hero);
        Stats get_stats();
    private:
};
