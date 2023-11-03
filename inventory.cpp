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

Inventory::Inventory(Inventory_player inventory_player){
    this->inventory_player = inventory_player;
    for (int i = 0; i<6; i++){
        this->inventory_player.armor.push_back({});
    }
}
Inventory::Inventory_player Inventory::get_inventory(){
    return this->inventory_player;
}
void Inventory::enterance_screen(){
    std::cout<<"1)See weapon.\t2)See armor.\t3)See spells.\t4)See quest items.\t5)Use consumables.\n";
    int turn;
    std::cin >> turn;
    if (turn==1){

    } else if (turn==2){

    } else if (turn==3){
        
    } else if (turn==4){
        
    } else if (turn==5){
        
    } else if (turn==0){
        
    }
}
