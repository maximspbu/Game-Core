#ifndef FIGHT_H
#define FIGHT_H
#include "party.h"
class Fight{
    public:
        void fight_output(Party_player& party_heroes, Party_enemy& party_enemies); //private
        void victory_fight_output(Party_enemy& party_enemies); //private
        void failture_fight_output(); //private
        void fight_mechanics(Party_enemy& party_enemies);  //private
};
#endif