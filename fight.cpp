#include "fight.h"
//#include "party.h"
#include <iostream>
void Fight::fight_output(Party_player& party_heroes, Party_enemy& party_enemies){
    std::cout << "Your party:\n";
    for (int i = 0; i < party_heroes.get_stats().heroes_count; ++i){
        std::cout << party_heroes.get_stats().party[i].get_stats().name << ":\tHP:"<<party_heroes.get_stats().party[i].get_stats().hp<<"\t: MP:"<<party_heroes.get_stats().party[i].get_stats().mp<<"\n"; 
    }
    std::cout<< "Your enemies:\n";
    for (int i = 0; i<party_enemies.get_stats().heroes_count; ++i){
        std::cout << party_enemies.get_stats().party[i].get_stats().name << ":\tHP:"<<party_enemies.get_stats().party[i].get_stats().hp<<"\t: MP:"<<party_enemies.get_stats().party[i].get_stats().mp<<"\n"; 
    }
    std::cout << "Choose option for Character#\n";

}
void Fight::victory_fight_output(Party_enemy& party_enemies){
    std::cout << "Victory!\n";
    std::cout << "Gained:\tMoney:\n";
}
void Fight::failture_fight_output(){
    std::cout << "Failture!\n";
}
void Fight::fight_mechanics(Party_enemy& party_enemies){
    
}