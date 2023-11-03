#ifndef HERO_H
#define HERO_H
#include "character.h"

class Hero : Character{ //subclass of Characters; (subclass: warrior, archer, mage, summoner...)
    // escape, status
    friend class Party_player;
    protected:
        Stats stats;
    public:
        Hero(Stats stats);
        Stats get_stats();
        void change_name();
        void escape();
    private:
};
#endif