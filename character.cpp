#include <string>
#include <vector>
#include <iostream>
#include "character.h"
#include "screen.h"


void Character::attack(Character* character){
    //attack = weapon attack + strength/2
    //without weapon: attack = level*2
    this->stats.rand_num = rand()%200;
    int deal_damage = 0;
    //party_enemies.get_stats().party[num_attack_enemy].stats.hp -= deal_damage;

}
void Character::defend(){
    
}
void Character::spell(){

}
void Character::levelup(){
    if (this->stats.cur_exp>=stats.exp){
        std::cout << "Choose upgrate for your Character: " << this->stats.name << '\n';
    }
}
void Character::dead(){
    // no turns, can not be damaged, buffed, debuffed, only revived
    
}


Weapon* Character::get_weapon(){
    return this->stats.weapon;
}
std::vector<Armor*> Character::get_armor(){
    return this->stats.armor;
}

void Character::equip_weapon(Weapon* weapon, Inventory& inventory){ // сделать unequip
    if (((*this->stats.weapon).get_stats().type == 0) && ((*weapon).stats.used == 0)){
        this->stats.weapon = weapon;
        (*weapon).stats.used = this->stats.order_num;
    } else if ((*weapon).stats.used != 0){
        std::cout << "This weapom is already used. Unequip this weapon from from Character#" << (*weapon).stats.used << ".\n";
    } else {
        (*this->stats.weapon).stats.used = 0;
        this->stats.weapon = weapon;
        (*weapon).stats.used = this->stats.order_num;
    }
}
void Character::equip_armor(Armor* armor, Inventory& inventory){
    int cur_type = (*armor).get_stats().type;
    if (((*this->stats.armor[cur_type]).get_stats().type == 0) && ((*armor).stats.used == 0)){
        this->stats.armor[cur_type] = armor;
        (*armor).stats.used = this->stats.order_num;
    } else if ((*armor).stats.used != 0){
        std::cout << "This armor is already used. Unequip this armor from from Character#" << (*armor).stats.used << ".\n";
    } else {
        (*this->stats.armor[cur_type]).stats.used = 0;
        this->stats.armor[cur_type] = armor;
        (*armor).stats.used = this->stats.order_num;
    }
}
void Character::equip_spell(Spell* spell, Inventory& inventory){
    int cur_type = (*spell).get_stats().type;
    if (((*this->stats.spell[cur_type]).get_stats().type == 0) && ((*spell).stats.used == 0)){
        this->stats.spell[cur_type] = spell;
        (*spell).stats.used = this->stats.order_num;
    } else if ((*spell).stats.used != 0){
        std::cout << "This spell is already used. Unequip this spell from from Character#" << (*spell).stats.used << ".\n";
    } else {
        (*this->stats.spell[cur_type]).stats.used = 0;
        this->stats.spell[cur_type] = spell;
        (*spell).stats.used = this->stats.order_num;
    }
}
void Character::equipment(Inventory& inventory){
    std::cout<<"Armor:\n";
    std::vector<std::string> list_armor{"Helmet", "Chest", "Legs", "Belt", "Boots", "Ring"};
    for (int i = 0; i < list_armor.size(); i++){
        std::cout << list_armor[i] << ":\n";
        if ((*this->stats.armor[i]).get_stats().type!=0){
            std::cout << (*stats.armor[i]).get_stats().name <<'\n';
        } else {
            std::cout << "---\n";
        }
    }
    std::cout<<"Weapon:\n";
    if ((*this->stats.weapon).get_stats().type==0){
        std::cout<<"---\n";
    } else {
        std::cout << (*stats.weapon).get_stats().name << '\n';
    }
    std::cout<<"Spells:\n";
    if (this->stats.spell.empty()){
        std::cout<<"---\n";
    } else {
        for (int i = 0; i<this->stats.spell.size(); i++){
            std::cout << (*this->get_stats().spell[i]).get_stats().name << '\n';
        }
    }
}
void Character::update_stats(){

}
void Character::use_consuambles(Inventory& inventory){

}


/*
class Enemy : public Character{ // no exp, has give_money, give_exp, give_quest_item
    //classes: magical, dragon, giant, undead, were, aquatic, mage, regenerative
    public:
        int given_money;
        int given_exp;
    private:
};*/