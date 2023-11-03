#include "spell.h"
Spell::Spell(Stats stats){
    this->stats = stats;
}

Spell::Stats Spell::get_stats(){
    return this->stats;
}