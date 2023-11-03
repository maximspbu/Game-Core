#include <iostream>
#include "screen.h"

int Screen::turn_get(){
    return this->turn;
}
void Screen::turn_input(){
    std::cin >> this->turn;
    if (this->turn==0){
        exit(0);
    }
}
void Screen::enterance_screen(){
    std::cout << "1)Fighting.\t2)Get a quest.\t3)Tavern.\t4)Merchant.\t5)See inventory.\t6)Heroes.\n";
}
void Screen::home_menu_output(Merchant& merchant, Quest_giver& quest_giver, Tavern& tavern){
    
    
    turn_input();
    if (this->turn==1){
        //fight
    } else if (this->turn == 2){
        quest_giver.enterance_screen();
    } else if (this->turn == 3){
        tavern.enterance_screen();
    } else if (this->turn == 4){
        merchant.enterance_screen();
    } else if (this->turn == 5){
        
    } else if (this->turn == 6){
        
    }
}
void Screen::quest_menu_output(Quest_giver& quest_giver){
    std::cout << "Find the artifact.\n";
}
void Screen::start(Merchant& merchant, Quest_giver& quest_giver, Tavern& tavern){
    // init in start merchant, tavern, quest_giver, fight?
    //home location
    std::cout << "Go buy characters in the tavern.\n";
    home_menu_output(merchant, quest_giver, tavern);
    std::cout << "Go get a quest.\n";
    home_menu_output(merchant, quest_giver, tavern);
    std::cout << "Go fighting.\n";
    home_menu_output(merchant, quest_giver, tavern);
    //fight
    //...
    //another location
    //...
    
}
