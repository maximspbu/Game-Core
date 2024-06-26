#include "../include/shop.h"


void Shop::PriceList(const std::vector<std::vector<std::string>>& list){
    std::ifstream fs;
    std::string short_stat;
    for (size_t i = 0; i < list[player_choice].size(); ++i){
        fs.open(list[player_choice][i]);
        std::getline(fs, short_stat);
        std::cout << i+1 << ") " << short_stat << '\n';
        fs.close();
    }
}

void Shop::Buy(Party& party, Object* object){
    if (object->stats["price"] > party.stats["money"]){
        std::cout << "Doesn't enough money\n";
        return;
    }
    party.stats["money"] -= object->stats["price"];
    std::cout << "Successfully purchased " << object->description["name"] << '\n';
}

void Shop::ReadFile(std::string file_name, std::map<std::string, std::string>& description, std::map<std::string, int>& stats){
    std::ifstream fs;
    fs.open(file_name);
    std::string key;
    std::string string_value;
    while (fs >> key >> string_value){
        description[key] = string_value;
    }
    int int_value;
    getline(fs, string_value);
    while (fs >> key >> int_value){
        stats[key] = int_value;
    }
    fs.close();
}

int Shop::Choice(){
    std::cout << "Enter the number of item:\n";
    int player_choice_;
    std::cin >> player_choice_;
    return player_choice_;
}
