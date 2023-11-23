#pragma once
#include <iostream>
#include <vector>
#include "character.h"
#include "inventory.h"
#include "location.h"

class Screen: public Location{ // output in console
    protected:
        int turn;
        std::vector<Location*> choice_list;
    public:
        Screen(const std::vector<std::vector<std::string>>& file_list, std::vector<Location*>);
        int turn_get();
        void turn_input();
        void entrance_screen(Party&) override;
        void start(Party&);
    private:
};
