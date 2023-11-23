#include "quest_giver.h"

Quest_giver::Quest_giver(const std::vector<std::vector<std::string>>& file_list):Location(file_list){}

void Quest_giver::entrance_screen(Party& party){
    while (true){
        std::cout << "Do you want to take a quest?\n1)Yes\t2)No\n";
        std::cin >> turn;
        if (turn == 1){
            Shop::price_list(file_list);
            std::cout << "Enter the index of quest.\n";
            std:: cin >> player_choice;
            if (player_choice == 0){
                return;
            }
            player_choice -= 1;
            take_quest(party);
            return;
        } else if (turn == 2){
            return;
        }
    }
}

void Quest_giver::take_quest(Party& party){
    Item quest(file_list[0][player_choice]);
    party.inventory.inventory_player[quest.get_description("type")].push_back(quest);
}

void Quest_giver::get_status_quest(){

}

void Quest_giver::complete_quest(){

}
