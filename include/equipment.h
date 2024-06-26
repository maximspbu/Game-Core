#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "location.h"


class Equipment: public Location{
    protected:
    public:
        Equipment(const std::vector<std::vector<std::string>>& file_list);
        void EntranceScreen(Party&) override;
        void ShowInventory(Party&);
        void ShowHeroes(Party&);
        void ChangeOrder(Party&);
        void Equip(Party&);
        void UseConsumable(Party&);
};

#endif //EQUIPMENT_H
