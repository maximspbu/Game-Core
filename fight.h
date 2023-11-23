#pragma once
#include "party.h"
#include "location.h"

class Fight:public Location{
    private:
        int input;
        int type;
        int target;
        int item;
        bool complete_action;
    public:
        //Fight() //take list of files of the enemies
        Fight(const std::vector<std::vector<std::string>>& file_list_);
        void entrance_screen(Party&) override; //=fight_output
        void choose_action(Party& party_heroes, Party& party_enemies); //private
        void victory_fight_output(Party& party_player, Party& party_enemies); //private
        void failture_fight_output(); //private
        void fight_mechanics(Party&, Party&);  //private
        bool attack_action(Party&, Party&, int);
        bool defend_action(Party&, int);
        bool spell_action(Party&, Party&, int);
        bool use_consumables_action(Party&, int);
        int fight_status(Party&, Party&);
        void choice(Party&, bool, int);
        Party create_party();
};
