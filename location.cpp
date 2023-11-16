#include "location.h"


void Location::price_list(std::vector<std::string> list_file){
    std::ifstream fs;
    std::string short_stat;
    for (int i = 0; i < list_file.size(); i++){
        fs.open(list_file[i]);
        std::getline(fs, short_stat);
        std::cout << "1) " << short_stat << '\n';
        fs.close();
    }
}

std::map<std::string, int> Location::buy(Party_player& party, std::string file_name, std::string* item_name){
    std::ifstream fs;
    std::string junk;
    fs.open(file_name);
    getline(fs, junk);
    std::map<std::string, int> local_stats;
    std::string key;
    int value;
    getline(fs, junk);
    (*item_name) = junk.substr(junk.find(' '));
    while (fs >> key >> value){
        local_stats[key] = value;
    }
    fs.close();
    return local_stats;
}

int Location::choice(){
    std::cout << "Enter the number of item:\n";
    std::cin >> turn;
    //0 - entrance_screen
    return turn;
}
