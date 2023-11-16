#include "location.h"
#include "party.h"


class Equipment: public Location{
    private:
        std::vector<std::string> list_equipment{"weapon", "chest", "helmet", "spell", "consumables"};
    public:
        Equipment();
        void entrance_screen(Party_player&) override;
        void show_inventory(Party_player&);
        void show_heroes(Party_player&);
        void change_order(Party_player&);
        void equip(Party_player&);
        void use_consumable(Party_player&);
};
