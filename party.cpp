#include "party.h"
#include "character.h"

class Character;

Party_player::Party_player(){
    stats.money = 1000;
    stats.heroes_count = 4;
    stats.cur_heroes_count = 0;
    stats.party = {};
    Inventory new_inventory;
    stats.inventory = new_inventory;
}
void Party_player::add_character(Character hero){
    hero.stats["order_num"] = stats.cur_heroes_count;
    this->stats.cur_heroes_count++;
    this->stats.party.push_back(hero);
}

Party_player::Stats Party_player::get_stats(){
    return this->stats;
}
/*
Character::Character(Stats c_s):stats(c_s){
}

Character::Stats Character::get_stats(){
    return this->stats;
}
*/