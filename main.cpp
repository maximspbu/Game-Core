#include "location.h"
#include "screen.h"
#include "character.h"
#include "party.h"
#include "inventory.h"
#include <vector>
#include "merchant.h"
#include "tavern.h"
#include "fight.h"
#include "equipment.h"
#include "quest_giver.h"


int main(){
    std::string pwd = "/home/vboxuser/Desktop/new_folder/prog/vs/lab2/sources/";
    std::vector<std::vector<std::string>> list_items_merchant = {
        {pwd+"weapon/knife.txt"}, //sources/weapon/long_sword.txt
        {pwd+"armor/leather_armor.txt"}, 
        {pwd+"spells/fire.txt"}, 
        {pwd+"consumables/potion.txt", pwd+"consumables/ether.txt"}
    };
    Merchant merchant(list_items_merchant);
    std::vector<std::vector<std::string>> list_items_tavern = {
        {pwd+"heroes/knight.txt"}, 
    };
    Tavern tavern(list_items_tavern);
    std::vector<std::string> list_enemies = {pwd+"enemies/goblin.txt"};
    Fight fight(list_enemies);
    Equipment equipment;
    std::vector<std::string> list_quests = {pwd+"quests/quest1.txt"};
    Quest_giver quest_giver(list_quests);
    std::vector<Location*> choice_list{&fight, &quest_giver, &tavern, &merchant, &equipment};
    Screen screen(choice_list);
    Party_player party_player;
    screen.entrance_screen(party_player);
    return 0;
}
