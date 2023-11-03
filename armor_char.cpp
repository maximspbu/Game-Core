#include "armor_char.h"
Armor::Armor(Stats stats_l){
    this->stats = stats_l;
}

Armor::Stats Armor::get_stats(){
    return this->stats;
}