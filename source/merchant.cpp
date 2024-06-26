#include "../include/merchant.h"

Merchant::Merchant(const std::vector<std::vector<std::string>>& file_list): Location::Location(file_list){}

void Merchant::EntranceScreen(Party& party){
    while (true){
        std::cout << "What do you want to buy?\n";
        std::cout << "1)Weapons.\t2)Armor.\t3)Spells.\t4)Consumables.\n";
        player_choice = Shop::Choice();
        if (player_choice == 0) return;
        player_choice -= 1;
        PriceList(fileList_);
        Buy(party);
    }
}

void Merchant::Buy(Party& party){
    int player_turn_ = Shop::Choice();
    if (player_turn_ == 0) return;
    --player_turn_;
    std::cout << "player_choice: " << player_choice << '\n';
    std::cout << "player_turn_: " << player_turn_ << '\n';
    Item new_item(fileList_[player_choice][player_turn_]);
    Shop::Buy(party, &new_item);
    party.inventory.inventoryPlayer_[new_item.description["type"]].push_back(new_item);
    std::cout << "Money: " << party.stats["money"] << '\n';
}
