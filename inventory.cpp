#include <string>
#include <iostream>
#include <vector>
#include "inventory.h"


//weapons
/*
// statuses: death, petrifaction, poison, blind, paralysis, sleep, silence, confuse
class Elements{
    public: // elements: status, poison/stone, time, death, fire, ice, lightning, earth, non-elemental
    private:
};

class heal_magic : Spell{
    public:// hp recovery e...2e
    private:
};

class attack_magic : Spell{
    public://damage = e...2e (unresisted attack spell 2*(e...2e))
    private:
};
*/

Inventory::Inventory(){
    this->inventory_player = inventory_player;
}

Item* Inventory::get_inventory(std::string type, int num){
    return (&this->inventory_player[type][num]);
}

void Inventory::entrance_screen(){
    std::cout << "1)See weapon.\t2)See armor.\t3)See spells.\t4)See quest items.\t5)Use consumables.\n";
    int turn;
    std::cin >> turn;
    
}

bool Inventory::use_consumable(Character& character){
    if (inventory_player["consumable"].size() == 0) return false;
    for (int i = 0; i < inventory_player["consumable"].size(); i++){
        std::cout << i+1 << ") " << inventory_player["consumable"][i].get_description("brief") << '\n';
    }
    int item;
    std::cout << "Choose item:\n";
    std::cin >> item;
    if (item == 0) return false;
    item -= 1;
    character.update_cur_stats(inventory_player["consumable"][item].get_stat("hp"), inventory_player["consumable"][item].get_stat("mp"));
    inventory_player["consumable"].erase(inventory_player["consumable"].begin()+item);
    return true;
}
