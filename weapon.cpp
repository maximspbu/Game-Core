#include "weapon.h"
Weapon::Weapon(Stats stats){
    this->stats = stats;
}

Weapon::Stats Weapon::get_stats(){
    return this->stats;
}