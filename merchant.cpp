#include "merchant.h"

Merchant::Merchant(const std::vector<std::vector<std::string>>& file_list):Location(file_list){}

void Merchant::entrance_screen(Party& party){
    while (true){
        std::cout << "What do you want to buy?\n";
        std::cout << "1)Weapons.\t2)Armor.\t3)Spells.\t4)Consumables.\n";
        player_choice = Shop::choice();
        if (player_choice == 0) return;
        player_choice -= 1;
        price_list(file_list);
        buy(party);
    }
}

void Merchant::buy(Party& party){
    int player_turn_ = Shop::choice();
    if (player_turn_ == 0) return;
    player_turn_-= 1;
    std::cout << "player_choice: " << player_choice << '\n';
    std::cout << "player_turn_: " << player_turn_ << '\n';
    Item new_item(file_list[player_choice][player_turn_]);
    Shop::buy(party, &new_item);
    party.inventory.inventory_player[new_item.description["type"]].push_back(new_item);
    std::cout << "Money: " << party.stats["money"] << '\n';
}
