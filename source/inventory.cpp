#include "../include/inventory.h"


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
    this->inventoryPlayer_ = inventoryPlayer_;
}

Item* Inventory::GetInventory(std::string type, int num){
    return (&this->inventoryPlayer_[type][num]);
}

void Inventory::EntranceScreen(){
    std::cout << "1)See weapon.\t2)See armor.\t3)See spells.\t4)See quest items.\t5)Use consumables.\n";
    int turn;
    std::cin >> turn;
    
}

bool Inventory::UseConsumable(Character& character){
    if (inventoryPlayer_["consumable"].size() == 0) return false;
    for (size_t i = 0; i < inventoryPlayer_["consumable"].size(); ++i){
        std::cout << i+1 << ") " << inventoryPlayer_["consumable"][i].GetDescription("brief") << '\n';
    }
    size_t item;
    std::cout << "Choose item:\n";
    std::cin >> item;
    if (item == 0) return false;
    --item;
    character.UpdateCurStats(inventoryPlayer_["consumable"][item].GetStat("hp"), inventoryPlayer_["consumable"][item].GetStat("mp"));
    inventoryPlayer_["consumable"].erase(inventoryPlayer_["consumable"].begin() + item);
    return true;
}
