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
        Screen(std::vector<Location*>);
        int turn_get();
        void turn_input();
        void entrance_screen(Party_player&) override;
        void start(Party_player&);
    private:
};
