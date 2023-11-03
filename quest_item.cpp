#include "quest_items.h"
Quest_items::Quest_items(Stats stats){
    this->stats = stats;
}

Quest_items::Stats Quest_items::get_stats(){
    return this->stats;
}