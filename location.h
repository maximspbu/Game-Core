#pragma once
#include "party.h"
#include "item.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

class Location{
    public:
        int turn;
        virtual void entrance_screen(Party_player&) = 0; //while (true)
        void price_list(std::vector<std::string> list_file);
        std::map<std::string, int> buy(Party_player& party, std::string file_name, std::string* item_name);
        void cycle();
        /*
        void read_file(std::string file_name, Item* item){
            std::map<std::string, int> local_stats;
            std::ifstream fs;
            std::string key;
            int value;
            fs.open(file_name);
            while (fs >> key >> value){
                local_stats[key] = value;
            }
            (*item).stats = local_stats;
            fs.close();
        }*/
        virtual ~Location(){}
        int choice();
};
