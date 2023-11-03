#include "party.h"
#include "character.h"
#include "hero.h"

class Character;

Party_player::Party_player(Stats stats_):stats(stats_){
}
void Party_player::add_character(Hero character){
    this->stats.cur_heroes_count++;
    this->stats.party.push_back(character);
}

Party_player::Stats Party_player::get_stats(){
    return this->stats;
}

Character::Character(Stats c_s):stats(c_s){
}

Character::Stats Character::get_stats(){
    return this->stats;
}
Party_enemy::Stats Party_enemy::get_stats(){
    return this->stats;
}