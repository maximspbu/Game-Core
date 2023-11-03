#ifndef CONSUMABLES_H
#define CONSUMABLES_H
class Consumables{
    // restore hp, mp; buff/debuff
    friend class Character;
    protected:
        struct Stats{
            int type;
            int hp_recovery;
            int mp_recovery;
        } stats;
    public:
        Consumables(Stats stats);
        Stats get_stats();

};
#endif