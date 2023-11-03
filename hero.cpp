#include "hero.h"
#include <iostream>
#include <string>
#include "character.h"

Hero::Hero(Stats stats) : Character(stats){};

void Hero::change_name(){
    std::cout << "Input hero's name: ";
    std::string name_h;
    std::cin >> name_h;
    this->stats.name = name_h;
}
void Hero::escape(){

}
Character::Stats Hero::get_stats(){
    return this->stats;
}