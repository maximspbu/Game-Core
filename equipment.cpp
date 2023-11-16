#include "equipment.h"

Equipment::Equipment(){

}

void Equipment::entrance_screen(Party_player& party){
    int turn;
    while (true){
        std::cout << "What do you want to do?\n1)Check inventory\t2)Check heroes\t3)Equip\t4)Change order\t5)Use consumable\n";
        std::cin >> turn;
        if (turn == 0){
            return;
        } else if (turn == 1) {
            show_inventory(party);
        } else if (turn == 2){
            show_heroes(party);
        } else if (turn == 3){
            equip(party);
        } else if (turn == 4){
            change_order(party);
        } else if (turn == 5){
            use_consumable(party);
        }
    }
}

void Equipment::show_inventory(Party_player& party){
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
    int ind1, ind2;
    std::cout << "Enter indicies of characters:\n";
    std::cin >> ind1 >> ind2;
    ind1-=1;
    ind2-=1;
    std::swap(party.stats.party[ind1].stats["order_num"], party.stats.party[ind2].stats["order_num"]);
    std::swap(party.stats.party[ind1], party.stats.party[ind2]);
}

void Equipment::equip(Party_player& party){
    show_inventory(party);
    std::cout << "Choose who to equip item:\n";
    int input;
    std::cin >> input;
    input-=1;
    std::cout << "Choose the type of equipment:\n1)Weapon\t2)Chest\t3)Helmet\t4)Spell\n";
    int type;
    std::cin >> type;
    type-=1;
    for (int j = 0; j<party.stats.inventory.inventory_player[list_equipment[type]].size(); j++){
        std::cout << j+1 << ") " << party.stats.inventory.inventory_player[list_equipment[type]][j].name << '\n';
    }
    int item;
    std::cin >> item;
    item-=1;
    party.stats.party[input].equipments[list_equipment[type]] = &party.stats.inventory.inventory_player[list_equipment[type]][item];
    party.stats.party[input].update_stats();
}

void Equipment::use_consumable(Party_player& party){
    std::cout << "Choose who to use consumable:\n";
    int input;
    std::cin >> input;
    input-=1;
    bool status = party.stats.inventory.use_consumable(party.stats.party[input]);
}
