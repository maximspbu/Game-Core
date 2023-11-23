#pragma once
#include <vector>
#include <string>
#include <map>
//#include "object.h"
#include "party.h"

class Shop{
    public:
        void price_list(const std::vector<std::vector<std::string>>& list_file);
        void read_file(std::string file_name, std::map<std::string, std::string>& description, std::map<std::string, int>& stats);
        int choice();
        void buy(Party&, Object*);
    protected:
        int turn;
        int player_choice;
};
