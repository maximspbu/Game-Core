#include "party.h"
#include "character.h"

class Character;

Party::Party(std::string file_name):Object(file_name){}

void Party::add_character(Character hero){
    hero.stats["order_num"] = stats["cur_members_count"];
    stats["cur_members_count"]++;
    this->party.push_back(hero);
}

/*
Character::Character(Stats c_s):stats(c_s){
}

Character::Stats Character::get_stats(){
    return this->stats;
}
*/