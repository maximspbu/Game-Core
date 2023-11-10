#include "tavern.h"

Tavern::Tavern(std::vector<std::vector<std::string>> list){
    this->list_items = list;
}

void Tavern::entrance_screen(Party_player& party){
    while (true){
        std::cout << "Money: " << party.stats.money << '\n';
        std::cout << "Choose options:\n1)Recovery.\t2)Hire heroes.\n";
        int turn;
        std::cin >> turn;
        if (turn == 2){
            this->price_list();
            this->buy(party);
        } else if (turn == 1){
            this->recovery(party);
        } else if (turn == 0) return;
    }
}

void Tavern::price_list(){
    Location::price_list(list_items[0]);
}

void Tavern::buy(Party_player& party){
    int player_choice = Location::choice()-1;
    if (party.stats.cur_heroes_count >= party.stats.heroes_count){
        std::cout << "You have already max count of heroes.\n";
    } else {
    //weapon fists
    Character new_character(list_items[0][player_choice]);
    new_character.stats["num_order"] = party.stats.cur_heroes_count;
    new_character.stats["cur_heroes_count"]+=1;
    party.add_character(new_character);
    party.stats.money -= new_character.stats["price"];
    //set index of new hero
    }
}

void Tavern::recovery(Party_player& party){ //Location* Location
    std::cout << "Recovery will cost ... money. Do you want to recovery?\n1)Yes\t2)No\n";
    int turn;
    std::cin >> turn;
    if (turn == 1){
        for (int i = 0; i<party.stats.heroes_count; i++){
            //party.stats.party[i].
        }
    } else if (turn == 2){
        
    }
}
