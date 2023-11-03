#ifndef SPELL_H
#define SPELL_H
#include <string>
class Spell{
    //effectivity - This determines the damage a spell does, or its effect.
    // spell accuracy
    //element
    friend class Character;
    protected:
        struct Stats{
            std::string name;
            int eff;
            int price;
            int spell_acc;
            int duraction;
            int base_chance; //148 (if target weak +=40)
            //chance to hit = base_chance + spell_acc - magic_defense
            int type;
            int used = 0;
        } stats;
    public:
        
        Spell(Stats stats);
        Stats get_stats();
        
};
#endif