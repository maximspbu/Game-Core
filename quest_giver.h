#ifndef QUEST_GIVER_H
#define QUEST_GIVER_H
#include <string>
#include <vector>
class Quest_giver{
    //list of string: texts of quests
    //list of bools, integers ... : status completing of quests
    protected:
        struct Quest{
            std::string text_quest;
            bool active=false;
            bool complete=true;
            bool p_complete=false;
            int num_complete;
            int p_num_complete=0;
        } quest;
        std::vector<Quest> quests;
    public:
        Quest_giver(std::vector<Quest> quests); //private
        void enterance_screen();
        void get_quest();
        void get_status_quest();
        void complete_quest(); // if ((this->quest.complete==quest.p_complete)||(this->quest.p_num_complete>=this->quest.num_complete))
};
#endif