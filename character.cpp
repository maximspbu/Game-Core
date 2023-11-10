#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "character.h"

Character::Character(std::string file_name){
    std::ifstream fs;
    fs.open(file_name);
    getline(fs, brief);
    std::string key;
    int value;
    getline(fs, name);
    while (fs >> key >> value){
        stats[key] = value;
    }
    fs.close();
    this->update_stats();
    stats["cur_hp"] = stats["hp"];
    stats["cur_mp"] = stats["mp"];
}

void Character::attack(Character* character){
    //attack = weapon attack + strength/2
    //without weapon: attack = level*2
    this->stats["rand_num"] = rand()%200;
    int deal_damage = 0;
    //party_enemies.get_stats().party[num_attack_enemy].stats.hp -= deal_damage;

}

void Character::defend(){
    
}

void Character::use_spell(){

}

void Character::levelup(){
    if (this->stats["cur_exp"]>=stats["exp"]){
        stats["level"]+=1;
        stats["exp"]%=100; // %= needed exp for new level
        std::cout << "Choose upgrate for your Character: " << this->name << '\n';
    }
}

void Character::dead(){
    // no turns, can not be damaged, buffed, debuffed, only revived
    
}



void Character::equipment(){
    std::cout << name << '\n' << "Stats:\n";
    for (auto& stat : stats){
        std::cout << stat.first << ": " <<stat.second << '\n';
    }
    std::cout << "Equipment:\n";
    for (auto& eq : equipments){
        std::cout << eq.first << ": " << eq.second << '\n';
    }
}

void Character::update_cur_stats(int added_hp, int added_mp){
    stats["cur_hp"] = std::min(stats["curr_hp"]+added_hp, stats["hp"]);
    stats["cur_mp"] = std::min(stats["curr_mp"]+added_hp, stats["mp"]);
}

void Character::update_stats(){
    std::string prefix = "base_";
    std::vector<std::string> not_upd{"level", "exp", "price", "hp", "mp"};
    stats["hp"] = (stats["base_hp"]*(stats["vitality"]+32))/32;
    stats["mp"] = (stats["base_mp"]*(stats["magic"]+32))/32;
    for (auto& i : stats){
        if (std::find(not_upd.begin(), not_upd.end(), i.first)==not_upd.end()){
            i.second = stats[prefix+i.first];
            for (auto& j : equipments){
                i.second += (*j.second).stats[i.first];
            }
        }
    }
}

void Character::use_consuambles(Inventory& inventory){

}

void Character::equip_item(Item* item){
    equipments[(*item).stats["type"]] = item;
}

/*
class Enemy : public Character{ // no exp, has give_money, give_exp, give_quest_item
    //classes: magical, dragon, giant, undead, were, aquatic, mage, regenerative
    public:
        int given_money;
        int given_exp;
    private:
};*/