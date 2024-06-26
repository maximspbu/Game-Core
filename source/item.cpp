#include "../include/item.h"

Item::Item(std::string& file_name):Object(file_name){}

void Item::StatsOutput(){
    std::cout << "Name: " << description["name"] << '\n';
    for (auto& i : stats){
        std::cout << i.first << ": " << i.second<<'\n';
    }
}
