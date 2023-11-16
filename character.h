#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "item.h"

class Character{
    protected:
        /*
        struct Stats{
            std::string name;
            int hp;
            int mp;
            int damage; //(min=1)
            //physical damage = a...2a-defense (If the Target is weak to an Elemental or Enemy-Type attribute of the weapon,add +4 to a)
            //crit damage = 2*(a...2a) - defense
            //target is asleep or parasyzed a = a*5/4
            int defense; // defense = sum of eq armor (without armor defense = level)
            int level;
            int exp;
            int strength;
            int agility;
            int intelligence;
            int vitality;
            int luck;
            //base chance = 168 (attacker is blind -= 40) (target is blind +=40) (target is weak to an attack+=40)
            // chance to hit = (base chance + hit_chance) - evade (target is asleep or paralyzed: chance to hit = bc)
            // percentage chance to hit = (chance to hit +1)/201
            // for attack: choose random number from 0 - 200 If that number is less than or equal to the Chance to Hit, the Hit connects. 0 is an automatic hit, and 200 is an automatic miss.
            // critical hit chance
            // critical rate = weapon index number (without weapon level*2)
            // percentage chance for critical = (critical rate+1)/201
            int hit_chance; // hit% = weapon accuaracy + character's hit%
            int evade; // 48 + agility - armor weight
            // crit rate = weapon crit rate (without weapon = level*2)
            // attack = weapon attack + strength/2 (without weapon: attack = level*2)
            int rand_num;
            int magic_defense;
            int price;
            int order_num;
            std::vector<Spell*> spell;
            Weapon* weapon;
            std::vector<Armor*> armor;
            int cur_hp;
            int cur_mp;
            int cur_exp;
            // magic_defense
        } stats;*/
        std::string name;
        std::string brief;
        std::map<std::string, int> stats;
        std::map<std::string, Item*> equipments;
        bool is_dead = false;
        void levelup();
        void dead();
    public:
        friend class Tavern;
        friend class Party_player;
        friend class Fight;
        friend class Equipment;
        friend class Inventory;
        int get_stats(std::string);
        Character(std::string);
        void equip_item(Item*);
        void update_cur_stats(int, int);
        void equipment(); //character
        //void use_consuambles(Inventory&); //character
        void attack(Character&);
        void defend();
        void use_spell(Character&);
        void update_stats();// set_hp(mp, attack...) пересчет характеристик после экипировки, повышения уровня и т.д.
    private: 
        
};
