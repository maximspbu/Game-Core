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
    update_stats();
    update_cur_stats(0,0);
    stats["cur_hp"] = stats["hp"];
    stats["cur_mp"] = stats["mp"];
}

void Character::attack(Character& character){
    update_stats();
    stats["attack"] = stats["strength"]/32;
    if (equipments.find("weapon")!=equipments.end())
    stats["attack"] = stats["strenght"]/32+(*equipments["weapon"]).stats["attack"]; // if hasn't weapon
    int damage = stats["attack"] + (int)(std::rand()%(stats["attack"]/4+1));
    int final_damage = (int)(damage*(100-character.stats["defense"])/100)+1;
    //std::cout << "cur hp " << (*character).stats["cur_hp"] << '\n';
    character.stats["cur_hp"] -= final_damage;
    if (character.stats["cur_hp"] <= 0){
        character.stats["cur_hp"] = 0;
        character.is_dead = true;
    }
}

void Character::defend(){
    update_stats();
    stats["bonus_defense"] = 0.5*stats["defense"];
    stats["defense"] += stats["bonus_defense"];
}

void Character::use_spell(Character&){

}

void Character::levelup(){
    if (this->stats["cur_exp"]>=stats["exp"]){
        stats["level"]+=1;
        stats["cur_exp"]%=stats["exp"]; // %= needed exp for new level
        stats["exp"]*=2;
        std::cout << "Choose upgrate for your Character: " << this->name << '\n';
    }
}

void Character::dead(){
    // no turns, can not be damaged, buffed, debuffed, only revived
    if (stats["cur_hp"]<=0){
        stats["cur_hp"] = 0;
        is_dead = true;
    } else {
        is_dead = false;
    }
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
    stats["cur_hp"] = std::min(stats["cur_hp"]+added_hp, stats["hp"]);
    stats["cur_mp"] = std::min(stats["cur_mp"]+added_hp, stats["mp"]);
}

void Character::update_stats(){
    std::string prefix = "base_";
    std::vector<std::string> not_upd{"level", "exp", "price", "hp", "mp", "bonus_defense"};
    stats["hp"] = (stats["base_hp"]*(stats["vitality"]+32))/32;
    stats["mp"] = (stats["base_mp"]*(stats["magic"]+32))/32;
    stats["bonus_defense"] = 0;
    for (auto& i : stats){
        if ((std::find(not_upd.begin(), not_upd.end(), i.first)==not_upd.end())&&(i.first.substr(0,5)=="base_")){
            //if i.first do not begin with base_
            //std::cout << i.first.substr(5,i.first.size()-5) << '\n';
            stats[i.first.substr(5,i.first.size()-5)] = i.second;
            //i.second = stats[prefix+i.first]; // fix
            for (auto& j : equipments){
                //i.second += (*j.second).stats[i.first];
                stats[i.first.substr(5,i.first.size()-5)] += (*j.second).stats[i.first.substr(5,i.first.size()-5)];
            }
        }
    }
}

void Character::equip_item(Item* item){
    equipments[(*item).type] = item;
}

int Character::get_stats(std::string name_stat){
    return stats[name_stat];
}

/*
class Enemy : public Character{ // no exp, has give_money, give_exp, give_quest_item
    //classes: magical, dragon, giant, undead, were, aquatic, mage, regenerative
    public:
        int given_money;
        int given_exp;
    private:
};*/