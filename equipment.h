#include "location.h"
#include "party.h"


class Equipment: public Location{
    protected:
    public:
        Equipment(const std::vector<std::vector<std::string>>& file_list);
        void entrance_screen(Party&) override;
        void show_inventory(Party&);
        void show_heroes(Party&);
        void change_order(Party&);
        void equip(Party&);
        void use_consumable(Party&);
};
