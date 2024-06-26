#ifndef FIGHT_H
#define FIGHT_H

#include "location.h"

class Fight: public Location{
    private:
        int input;
        int type;
        int target;
        int item;
        bool completeAction;
    public:
        //Fight() //take list of files of the enemies
        Fight(const std::vector<std::vector<std::string>>& file_list_): Location(file_list_){}
        void EntranceScreen(Party&) override; //=fight_output
        void ChooseAction(Party& party_heroes, Party& party_enemies); //private
        void VictoryFightOutput(Party& party_player, Party& party_enemies); //private
        void FailtureFightOutput(); //private
        void FightMechanics(Party&, Party&);  //private
        bool AttackAction(Party&, Party&, int);
        bool DefendAction(Party&, int);
        bool SpellAction(Party&, Party&, int);
        bool UseConsumablesAction(Party&, int);
        int FightStatus(Party&, Party&);
        void Choice(Party&, bool, int);
        Party CreateParty();
};

#endif //FIGHT_H
