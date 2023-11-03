#ifndef PARTY_H
#define PARTY_H
#include <string>
#include <vector>
#include <iostream>
#include "hero.h"
#include "character.h"


class Party_player{ //party player
    // stats of game: time, score, money, inventory, heroes count, (save)
    // stats of characters hp, exp, mp, defense, damage, crit rate, crit multiply, speed, steal hp, inventory (used armor, weapons)
    friend class Merchant;
    friend class Tavern;
    //friend class Screen;
    protected:
        struct Stats{
            int time;
            int money;
            int score;
            int cur_heroes_count=0;
            int heroes_count=4;
            std::vector<Hero> party;
            Inventory inventory;
        } stats;
    public:
        Party_player(Stats stats);
        void add_character(Hero hero); //?hero (потом сделать класс пати врагов, класс enemy)
        Stats get_stats();
    private:
};

class Party_enemy{
    protected:
        struct Stats{
            int heroes_count;
            std::vector<Character> party;
            Inventory inventory;
        } stats;
    public:
        Party_enemy(Stats stats);
        void add_character(Character character); //?hero (потом сделать класс пати врагов, класс enemy)
        Stats get_stats();
    private:
};
#endif