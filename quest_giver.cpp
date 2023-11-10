#include "quest_giver.h"

Quest_giver::Quest_giver(std::vector<std::string> list_file){
    quest_list = list_file;
}

void Quest_giver::entrance_screen(Party_player& party){
    while (true){
        std::cout << "Do you want to take a quest?\n1)Yes\t2)No\n";
        int turn;
        std::cin >> turn;
        if (turn == 1){
            Location::price_list(quest_list);
            //this->price_list(Location);
            //this->buy(Location, party);
        } else if (turn==2){
            return;
        }
    }
}

void Quest_giver::get_status_quest(){

}

void Quest_giver::complete_quest(){

}
