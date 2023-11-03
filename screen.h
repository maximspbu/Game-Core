#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include "character.h"
#include "inventory.h"
#include "tavern.h"
#include "merchant.h"
#include "quest_giver.h"
#include "fight.h"

class Screen{ // output in console
    protected:
        int turn;
    public:
        int turn_get();
        void turn_input();
        void home_menu_output(Merchant& merchant, Quest_giver& quest_giver, Tavern& tavern); // Merchant& merchant, Quest& quest, Tavern& tavern
        void quest_menu_output(Quest_giver& quest_giver);
        void start(Merchant& merchant, Quest_giver& quest_giver, Tavern& tavern);
        void merchant_output(Merchant& merchant);
        void tavern_output(Tavern& tavern);
    private:
};
#endif