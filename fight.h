#pragma once
#include "party.h"
#include "location.h"

class Fight:public Location{
    public:
        std::vector<std::string> list_enemies;
        //Fight() //take list of files of the enemies
        Fight(std::vector<std::string>);
        void entrance_screen(Party_player&) override; //=fight_output
        void fight_output(Party_player& party_heroes, Party_player& party_enemies); //private
        void victory_fight_output(Party_player& party_player, Party_player& party_enemies); //private
        void failture_fight_output(); //private
        void fight_mechanics(Party_player& party_enemies);  //private
        void add_enemy();
};
