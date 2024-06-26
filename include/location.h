#pragma once
#include "party.h"
#include "item.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

class Location{
    protected:
        std::vector<std::vector<std::string>> fileList_;
        Location(const std::vector<std::vector<std::string>>& file_list);
        int turn;
    public:
        virtual void EntranceScreen(Party&) = 0; //location only

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
};
