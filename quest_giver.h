#pragma once
#include <string>
#include <vector>
#include "location.h"

class Quest_giver: public Location{
    //list of string: texts of quests
    //list of bools, integers ... : status completing of quests
    protected:
    /*
        struct Quest{
            std::string text_quest;
            bool active=false;
            bool complete=true;
            bool p_complete=false;
            int num_complete;
            int p_num_complete=0;
        } quest;
        */
        std::vector<std::string> quest_list;
    public:
        Quest_giver(std::vector<std::string>); //private
        void entrance_screen(Party_player&) override;
        void get_status_quest();
        void complete_quest(); // if ((this->quest.complete==quest.p_complete)||(this->quest.p_num_complete>=this->quest.num_complete))
};
