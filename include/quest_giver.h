#ifndef QUEST_GIVER_H
#define QUEST_GIVER_H


#include "location.h"
#include "shop.h"

class QuestGiver: public Location, public Shop{
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
        QuestGiver(const std::vector<std::vector<std::string>>& file_list);
        void EntranceScreen(Party&) override;
        void GetQuestStatus();
        void CompleteQuest(); // if ((this->quest.complete==quest.p_complete)||(this->quest.p_num_complete>=this->quest.num_complete))
        void TakeQuest(Party&);
};

#endif //QUEST_GIVER_H
