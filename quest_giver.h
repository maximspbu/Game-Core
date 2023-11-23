#pragma once
#include <string>
#include <vector>
#include "location.h"
#include "shop.h"

class Quest_giver: public Location, public Shop{
    //list of string: texts of quests
    //list of bools, integers ... : status completing of quests
    friend class Fight;
    protected:
        int turn;
        int player_choice;
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
    public:
        Quest_giver(const std::vector<std::vector<std::string>>& file_list); //private
        void entrance_screen(Party&) override;
        void get_status_quest();
        void complete_quest(); // if ((this->quest.complete==quest.p_complete)||(this->quest.p_num_complete>=this->quest.num_complete))
        void take_quest(Party&);
};
