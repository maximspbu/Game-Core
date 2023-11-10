#include "equipment.h"

Equipment::Equipment(){

}

void Equipment::entrance_screen(Party_player& party){
    int turn;
    while (true){
        std::cout << "What do you want to do?\n1)Check inventory\t2)Check heroes\n";
        std::cin >> turn;
        if (turn == 0){
            return;
        } else if (turn == 1) {
            show_inventory(party);
        } else if (turn == 2){
            show_heroes(party);
        }
    }
}

void Equipment::show_inventory(Party_player& party){
    std::vector<std::string> list_equipment{"armor", "weapon", "spell", "consumables"}; 
    std::cout << "Inventory:\n";
    for (int i = 0; i<list_equipment.size(); i++){
        std::cout<<list_equipment[i] << ":\n";
        for (int j = 0; j<party.stats.inventory.inventory_player[list_equipment[i]].size(); j++){
            std::cout << party.stats.inventory.inventory_player[list_equipment[i]][j].name << '\n';
        }
    }
}

void Equipment::show_heroes(Party_player& party){
    std::cout << "Party:\n";
    for (int i = 0; i<party.stats.cur_heroes_count; i++){
        party.stats.party[i].equipment();
    }
}

void Equipment::change_order(Party_player& party){

}

void Equipment::equip(Party_player& party){
    
}