#include "../include/tavern.h"

Tavern::Tavern(const std::vector<std::vector<std::string>>& list_file, int recovery_price_): Location::Location(list_file), recovery_price(recovery_price_){}

void Tavern::EntranceScreen(Party& party){
    while (true){
        std::cout << "Money: " << party.stats["money"] << '\n';
        std::cout << "Choose options:\n1)Recovery.\t2)Hire heroes.\n";
        int player_turn;
        std::cin >> player_turn;
        if (player_turn == 2){
            Shop::player_choice = 0;
            Shop::PriceList(fileList_);
            Buy(party);
        } else if (player_turn == 1){
            Recovery(party);
        } else if (player_turn == 0) return;
    }
}

void Tavern::Buy(Party& party){
    int player_choice_ = Choice();
    if (player_choice_== 0) return;
    --player_choice_;
    if (party.stats["cur_members_count"] >= party.stats["max_members_count"]){
        std::cout << "You have already max count of heroes.\n";
    } else {
        //weapon fists
        Character new_character(fileList_[0][player_choice_]);
        Shop::Buy(party, &new_character);
        party.AddCharacter(new_character);
        //set index of new hero
    }
}

void Tavern::Recovery(Party& party){ //Location* Location
    std::cout << "Recovery will cost " << recovery_price << " money. Do you want to recovery?\n1)Yes\t2)No\n";
    int turn;
    std::cin >> turn;
    if (turn == 1){
        if (party.stats["money"] < recovery_price){
            std::cout << "Doesn't enough money.\n";
            return;
        }
        party.stats["money"] -= recovery_price;
        for (auto& character: party.party){
            character.UpdateCurStats(character.GetStat("hp"), 0);
        }
    }
}
