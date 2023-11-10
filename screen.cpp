#include <iostream>
#include "screen.h"

Screen::Screen(std::vector<Location*> choice_list){
    this->choice_list = choice_list;
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

void Screen::entrance_screen(Party_player& party){
    std::cout << "1)Fighting.\t2)Get a quest.\t3)Tavern.\t4)Merchant.\t5)Inventory/Heroes.\n";
    turn_input();
    while (true){
        if (this->turn == 0){
            exit(0);
        } else {
            (*this->choice_list[turn - 1]).entrance_screen(party);
        }
    }
}

void Screen::start(Party_player& party){
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
