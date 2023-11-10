#include "location.h"
#include "party.h"

class Equipment:public Location{
    public:
        Equipment();
        void entrance_screen(Party_player&) override;
        void show_inventory(Party_player&);
        void show_heroes(Party_player&);
        void change_order(Party_player&);
        void equip(Party_player&);
};
