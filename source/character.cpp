#include <algorithm>
#include "../include/character.h"

Character::Character(std::string file_name): Object(file_name){
    UpdateStats();
    UpdateCurStats(0,0);
    stats["cur_hp"] = stats["hp"];
    stats["cur_mp"] = stats["mp"];
}

void Character::Attack(Character& character){
    UpdateStats();
    stats["attack"] = stats["strength"]/32;
    if (equipments_.find("weapon") != equipments_.end())
    stats["attack"] = stats["strenght"]/32 + equipments_["weapon"]->stats["attack"]; // if hasn't weapon
    int damage = stats["attack"] + (int)(std::rand()%(stats["attack"]/4 + 1));
    int final_damage = reinterpret_cast<int>((damage*(100 - character.stats["defense"])/100) + 1);
    //std::cout << "cur hp " << (*character).stats["cur_hp"] << '\n';
    character.UpdateCurStats(-final_damage, 0);
    /*
    character.stats["cur_hp"] -= final_damage;
    if (character.stats["cur_hp"] <= 0){
        character.stats["cur_hp"] = 0;
        character.is_dead = true;
    }
    */
}

void Character::Defend(){
    UpdateStats();
    stats["bonus_defense"] = 0.5*stats["defense"];
    stats["defense"] += stats["bonus_defense"];
}

void Character::UseSpell(Character& character, int type){
    int attack = equipments_["spell"][type].stats["power"] + (rand()%(equipments_["spell"][type].stats["power"]/8));
    int damage = (attack - character.stats["magic_defence"])*((stats["level"]*stats["magic"])/256+4);
    character.UpdateCurStats(-damage, 0);
}

void Character::LevelUp(){
    int prev_level = stats["level"];
    while (stats["cur_exp"]>=stats["exp"]){
        stats["level"]++;
        stats["cur_exp"] -= stats["exp"];
        stats["exp"] *= 2;
    }
    stats["base_hp"] += 2*(stats["level"] - prev_level);
    stats["base_mp"] += (stats["level"] - prev_level);
    stats["base_attack"] += (stats["level"] - prev_level);
    stats["base_defense"] += (stats["level"] - prev_level);
    stats["base_strength"] += 8*(stats["level"] - prev_level);
    stats["base_agility"] += 8*(stats["level"] - prev_level);
    stats["base_vitality"] += 8*(stats["level"] - prev_level);
    stats["base_magic"] += 8*(stats["level"] - prev_level);
    UpdateStats();
}

void Character::Equipment(){
    std::cout << description["name"] << '\n' << "Stats:\n";
    for (auto& stat : stats){
        std::cout << stat.first << ": " <<stat.second << '\n';
    }
    std::cout << "Equipment:\n";
    for (auto& eq : equipments_){
        std::cout << eq.first << ": " << eq.second->GetDescription("name") << '\n';
    }
}

void Character::UpdateCurStats(int added_hp, int added_mp){
    if (added_hp < 0){
        stats["cur_hp"] = std::max(stats["cur_hp"]+added_hp, 0);
        if (stats["cur_hp"] == 0) is_dead = true;
    } else {
        stats["cur_hp"] = std::min(stats["cur_hp"]+added_hp, stats["hp"]);
    }
    if (added_mp<0){
        stats["cur_mp"] = std::max(stats["cur_mp"]+added_mp, 0);
    } else {
        stats["cur_mp"] = std::min(stats["cur_mp"]+added_mp, stats["mp"]);
    }
}

void Character::UpdateStats(){
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
            for (auto& j : equipments_){
                //i.second += (*j.second).stats[i.first];
                stats[i.first.substr(5,i.first.size()-5)] += j.second->stats[i.first.substr(5,i.first.size()-5)];
            }
        }
    }
}

void Character::EquipItem(Item* item){
    equipments_[item->description["type"]] = item;
}

/*
class Enemy : public Character{ // no exp, has give_money, give_exp, give_quest_item
    //classes: magical, dragon, giant, undead, were, aquatic, mage, regenerative
    public:
        int given_money;
        int given_exp;
    private:
};*/