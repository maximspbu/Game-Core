#ifndef SCREEN_H
#define SCREEN_H


#include "location.h"

class Screen: public Location{ // output in console
    protected:
        int turn;
        std::vector<Location*> choice_list;
    public:
        Screen(const std::vector<std::vector<std::string>>& file_list, std::vector<Location*> choice_list_);

        int GetTurn();
        void InputTurn();
        void EntranceScreen(Party&) override;
        void Start(Party&);
    private:
};

#endif //SCREEN_H
