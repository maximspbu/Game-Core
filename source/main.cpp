#include "../include/merchant.h"
#include "../include/tavern.h"
#include "../include/fight.h"
#include "../include/equipment.h"
#include "../include/quest_giver.h"


int main(){
    std::string pwd = "../samples/";
    const std::vector<std::vector<std::string>> list_items_merchant = {
        {pwd + "weapon/knife.txt"},
        {pwd + "armor/leather_armor.txt"}, 
        {pwd + "spells/fire.txt"}, 
        {pwd + "consumables/potion.txt", pwd + "consumables/ether.txt"}
    };
    Merchant merchant(list_items_merchant);
    const std::vector<std::vector<std::string>> list_items_tavern = {
        {pwd + "heroes/knight.txt"}, 
    };
    Tavern tavern(list_items_tavern, 40);
    const std::vector<std::vector<std::string>> list_enemies = {{pwd + "enemies/goblin.txt"}};
    Fight fight(list_enemies);
    const std::vector<std::vector<std::string>> list_equipment = {{""}};
    Equipment equipment(list_equipment);
    const std::vector<std::vector<std::string>> list_quests = {{pwd + "quests/quest1.txt"}};
    Quest_giver quest_giver(list_quests);
    std::vector<Location*> choice_list{&fight, &quest_giver, &tavern, &merchant, &equipment};
    const std::vector<std::vector<std::string>> list_screens = {{""}};
    Screen screen(list_screens, choice_list);
    Party party_player(pwd + "party/player.txt");
    screen.EntranceScreen(party_player);
    return 0;
}
