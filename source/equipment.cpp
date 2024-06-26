#include "../include/equipment.h"

Equipment::Equipment(const std::vector<std::vector<std::string>>& file_list) : Location::Location(file_list){}

void Equipment::EntranceScreen(Party& party){
    int turn;
    while (true){
        std::cout << "What do you want to do?\n1)Check inventory\t2)Check heroes\t3)Equip\t4)Change order\t5)Use consumable\n";
        std::cin >> turn;
        if (turn == 0){
            return;
        } else if (turn == 1) {
            ShowInventory(party);
        } else if (turn == 2){
            ShowHeroes(party);
        } else if (turn == 3){
            Equip(party);
        } else if (turn == 4){
            ChangeOrder(party);
        } else if (turn == 5){
            UseConsumable(party);
        }
    }
}

void Equipment::ShowInventory(Party& party){
    std::cout << "Inventory:\n";
    //party.inventory_.inventoryPlayer_
    for (auto& i : party.inventory_.inventoryPlayer_){
        std::cout << i.first << ":\n";
        for (int j = 0; j < i.second.size(); ++j){
            std::cout << j+1 << ") " << i.second[j].GetDescription("name") << '\n';
        }
    }
    /*
    for (int i = 0; i<fileList_[0].size(); i++){
        std::cout<<fileList_[0][i] << ":\n";
        for (int j = 0; j<party.inventory_.inventoryPlayer_[fileList_[0][i]].size(); j++){
            std::cout << party.inventory_.inventoryPlayer_[fileList_[0][i]][j].GetDescription("name") << '\n';
        }
    }
    */
}

void Equipment::ShowHeroes(Party& party){
    std::cout << "Party:\n";
    for (int i = 0; i<party.stats["cur_members_count"]; ++i){
        party.party[i].Equipment();
        std::cout << '\n'; 
    }
}

void Equipment::ChangeOrder(Party& party){
    int ind1, ind2;
    std::cout << "Enter indicies of characters:\n";
    std::cin >> ind1 >> ind2;
    --ind1;
    --ind2;
    std::swap(party.party[ind1].stats["order_num"], party.party[ind2].stats["order_num"]);
    std::swap(party.party[ind1], party.party[ind2]);
}

void Equipment::Equip(Party& party){
    ShowInventory(party);
    std::vector<std::string> types_equipment = {"weapon", "chest", "helmet", "spell"};
    std::cout << "Choose who to equip item:\n";
    int input_;
    std::cin >> input_;
    input_-=1;
    std::cout << "Choose the type of equipment:\n1)Weapon\t2)Chest\t3)Helmet\t4)Spell\n";
    int type_;
    std::cin >> type_;
    type_-=1;
    for (int j = 0; j<party.inventory_.inventoryPlayer_[types_equipment[type_]].size(); ++j){
        std::cout << j+1 << ") " << party.inventory_.inventoryPlayer_[types_equipment[type_]][j].GetDescription("name") << '\n';
    }
    int item_;
    std::cout << "Enter the index of item:\n";
    std::cin >> item_;
    if (item_==0) return;
    --item_;
    std::cout << "input: " << input_ << " type: " << type_ << " item: " << item_ << '\n';
    for (int i = 0; i < party.stats["cur_members_count"]; ++i){
        if (&party.inventory_.inventoryPlayer_[types_equipment[type_]][item_]==party.party[i].equipments_[types_equipment[type_]]){
            std::cout << "This weapon is already equipped by character#" << i+1 << '\n';
            return;
        }
    }
    std::cout << "FLAG\n";
    party.party[input_].equipments_[types_equipment[type_]] = &party.inventory_.inventoryPlayer_[types_equipment[type_]][item_];
    std::cout << "FLAG2\n";
    //party.party[input_].UpdateStats();
    std::cout << "Item was equipped!\n";
}

void Equipment::UseConsumable(Party& party){
    for (int i = 0; i < party.inventory_.inventoryPlayer_["consumable"].size(); ++i){
        std::cout << i+1 << ") " << party.inventory_.inventoryPlayer_["consumable"][i].GetDescription("name") << '\n';
    }
    std::cout << "Choose who to use consumable:\n";
    int input;
    std::cin >> input;
    if (input == 0) return;
    --input;
    bool status = party.inventory_.UseConsumable(party.party[input]);
}
