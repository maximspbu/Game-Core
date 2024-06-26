#include "../include/quest_giver.h"

QuestGiver::QuestGiver(const std::vector<std::vector<std::string>>& file_list):Location::Location(file_list){}

void QuestGiver::EntranceScreen(Party& party){
    while (true){
        std::cout << "Do you want to take a quest?\n1)Yes\t2)No\n";
        std::cin >> turn;
        if (turn == 1){
            Shop::PriceList(fileList_);
            std::cout << "Enter the index of quest.\n";
            std:: cin >> player_choice;
            if (player_choice == 0){
                return;
            }
            --player_choice;
            TakeQuest(party);
            return;
        } else if (turn == 2){
            return;
        }
    }
}

void QuestGiver::TakeQuest(Party& party){
    Item quest(fileList_[0][player_choice]);
    party.inventory.inventoryPlayer_[quest.GetDescription("type")].push_back(quest);
}

void QuestGiver::GetQuestStatus(){

}

void QuestGiver::CompleteQuest(){

}
