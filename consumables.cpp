#include "consumables.h"
Consumables::Consumables(Stats stats){
    this->stats = stats;
}

Consumables::Stats Consumables::get_stats(){
    return this->stats;
}
