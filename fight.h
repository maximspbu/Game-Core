#pragma once
#include "party.h"
#include "location.h"

class Fight:public Location{
    private:
        int turn;
        int input;
        int type;
        int target;
        int item;
        bool complete_action;
        std::vector<std::string> list_enemies;
    public:
        //Fight() //take list of files of the enemies
        Fight(std::vector<std::string>);
        void entrance_screen(Party_player&) override; //=fight_output
        void choose_action(Party_player& party_heroes, Party_player& party_enemies); //private
        void victory_fight_output(Party_player& party_player, Party_player& party_enemies); //private
        void failture_fight_output(); //private
        void fight_mechanics(Party_player&, Party_player&);  //private
        bool attack_action(Party_player&, Party_player&, int);
        bool defend_action(Party_player&, int);
        bool spell_action(Party_player&, Party_player&, int);
        bool use_consumables_action(Party_player&, int);
        int fight_status(Party_player&, Party_player&);
        void choice(Party_player&, bool, int);
        Party_player create_party();
};
