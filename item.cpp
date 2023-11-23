#include "item.h"

Item::Item(std::string file_name):Object(file_name){}

void Item::stats_output(){
    std::cout << "Name: " << description["name"] << '\n';
    for (auto& i : this->stats){
        std::cout << i.first << ": " << i.second<<'\n';
    }
}
