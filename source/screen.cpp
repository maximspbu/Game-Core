#include "../include/screen.h"

Screen::Screen(const std::vector<std::vector<std::string>>& file_list, std::vector<Location*> choice_list_): Location::Location(file_list), choice_list(choice_list_) { //add to location name
}

int Screen::GetTurn(){
    return this->turn;
}

void Screen::InputTurn(){
    std::cin >> this->turn;
    if (this->turn == 0){
        exit(0);
    }
}

void Screen::EntranceScreen(Party& party){
    while (true){
        std::cout << "1)Fighting\t2)Get a quest\t3)Tavern\t4)Merchant\t5)Inventory/Heroes\n";
        InputTurn();
        if (this->turn == 0){
            exit(0);
        } else {
            this->choice_list[turn - 1]->EntranceScreen(party);
        }
    }
}

void Screen::Start(Party& party){
    // init in start merchant, tavern, quest_giver, fight?
    //home location
    std::cout << "Go buy characters in the tavern.\n";
    this->EntranceScreen(party);
    std::cout << "Go get a quest.\n";
    this->EntranceScreen(party);
    std::cout << "Go fighting.\n";
    this->EntranceScreen(party);
    //another location
    //...
}
