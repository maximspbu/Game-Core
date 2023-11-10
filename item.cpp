#include "item.h"

Item::Item(std::string file_name){
    std::ifstream fs;
    fs.open(file_name);
    getline(fs, brief);
    std::string key;
    int value;
    getline(fs, name);
    while (fs >> key >> value){
        stats[key] = value;
    }
    fs.close();
}

int Item::get_stat(std::string stat){
    return stats[stat];
}

void Item::stats_output(){
    std::cout << "Name: " << this->name << '\n';
    for (auto& i : this->stats){
        std::cout << i.first << ": " << i.second<<'\n';
    }
}
