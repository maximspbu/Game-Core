#ifndef PARTY_H
#define PARTY_H

#include "character.h"
#include "inventory.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>


class Party: public Object{ //party player
    // stats of game: time, score, money, inventory, heroes count, (save)
    // stats of characters hp, exp, mp, defense, damage, crit rate, crit multiply, speed, steal hp, inventory (used armor, weapons)
    friend class Merchant;
    friend class Tavern;
    friend class Equipment;
    friend class Fight;
    friend class Shop;
    friend class QuestGiver;
    //friend class Screen;
    protected:
        std::vector<Character> party;
        Inventory inventory_;
        //std::map<std::string, int> stats; //money, heroes_count(max_member_count), cur_heroes_count (cur_member_count)
    public:
        Party(std::string file_name);
        void AddCharacter(Character hero);
    private:
};

#endif //PARTY_H

