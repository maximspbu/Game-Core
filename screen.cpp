#include <iostream>
#include "screen.h"

Screen::Screen(const std::vector<std::vector<std::string>>& file_list, std::vector<Location*> choice_list_):Location(file_list), choice_list(choice_list_) { //add to location name
}

int Screen::turn_get(){
    return this->turn;
}

void Screen::turn_input(){
    std::cin >> this->turn;
    if (this->turn == 0){
        exit(0);
    }
}

void Screen::entrance_screen(Party& party){
    while (true){
        std::cout << "1)Fighting\t2)Get a quest\t3)Tavern\t4)Merchant\t5)Inventory/Heroes\n";
        turn_input();
        if (this->turn == 0){
            exit(0);
        } else {
            (*this->choice_list[turn - 1]).entrance_screen(party);
        }
    }
}

void Screen::start(Party& party){
    // init in start merchant, tavern, quest_giver, fight?
    //home location
    std::cout << "Go buy characters in the tavern.\n";
    this->entrance_screen(party);
    std::cout << "Go get a quest.\n";
    this->entrance_screen(party);
    std::cout << "Go fighting.\n";
    this->entrance_screen(party);
    //another location
    //...
}
