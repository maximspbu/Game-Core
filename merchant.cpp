#include "merchant.h"

Merchant::Merchant(std::vector<std::vector<std::string>> list){
    this->list_items = list;
    //this->stats["armor"] = std::vector<Armor>;
}

void Merchant::entrance_screen(Party_player& party){
    while (true){
        std::cout << "What do you want to buy?\n";
        std::cout << "1)Weapons.\t2)Armor.\t3)Spells.\t4)Consumables.\n";
        int turn;
        std::cin >> turn;
        if (turn == 0){
            break;
        }
        turn -= 1;
        this->price_list(turn);
        std::cout << "Money: " << party.stats.money << '\n';
        this->buy(turn, party);
    }
}

void Merchant::price_list(int turn){
    Location::price_list(list_items[turn]);
}

void Merchant::buy(int turn, Party_player& party){
    int player_choice = Location::choice();
    if (player_choice==0) return;
    player_choice-=1;
    Item new_item(list_items[turn][player_choice]);
    if (new_item.stats["price"]>party.stats.money){
        std::cout << "Doesn't enough money.\n";
        return;
    }
    party.stats.inventory.inventory_player[new_item.type].push_back(new_item); //add to txt type stat 0-weapom, 1-chest ...
    party.stats.money -= new_item.stats["price"];
    std::cout << "Money: " << party.stats.money << '\n';
}
