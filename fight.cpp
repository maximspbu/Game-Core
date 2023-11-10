#include "fight.h"
#include <iostream>


Fight::Fight(std::vector<std::string> list){
    list_enemies = list;
    Party_player party_enemies;
    party_enemies.stats.heroes_count = 3+rand()%5;
    party_enemies.stats.cur_heroes_count = party_enemies.stats.heroes_count;
    for (int i = 0; i<party_enemies.stats.heroes_count; i++){
        int num_rand_file = rand()%(list_enemies.size());
        //add_character
        Character new_enemy(list_enemies[num_rand_file]);
        party_enemies.stats.party.push_back(new_enemy);
    }
}

void Fight::entrance_screen(Party_player& party){
    while (true){
        int turn;
        std::cin>>turn;
        if (turn==0){
            return ;
        }
    }
}

void Fight::fight_output(Party_player& party_heroes, Party_player& party_enemies){
    std::cout << "Your party:\n";
    for (int i = 0; i < party_heroes.get_stats().heroes_count; ++i){
        std::cout << party_heroes.get_stats().party[i].name << ":\tHP:"<<party_heroes.get_stats().party[i].stats["cur_hp"]<<"\t: MP:"<<party_heroes.get_stats().party[i].stats["cur_mp"]<<"\n"; 
    }
    std::cout<< "Your enemies:\n";
    for (int i = 0; i<party_enemies.get_stats().heroes_count; ++i){
        std::cout << party_enemies.get_stats().party[i].name << ":\tHP:"<<party_enemies.get_stats().party[i].stats["cur_hp"]<<"\t: MP:"<<party_enemies.get_stats().party[i].stats["cur_mp"]<<"\n"; 
    }
    std::cout << "Choose option for Character#\n";

}

void Fight::victory_fight_output(Party_player& party_heroes, Party_player& party_enemies){
    std::cout << "Victory!\n";
    std::cout << "Gained:\tMoney:\n";
    int total_exp = 0;
    for (int i = 0; i<party_enemies.stats.heroes_count; i++){
        party_heroes.stats.money += party_enemies.stats.party[i].stats["money"];
        total_exp += party_enemies.stats.party[i].stats["exp"];
    }
    for (int i = 0; i<party_heroes.stats.cur_heroes_count; i++){
        party_heroes.stats.party[i].stats["exp"] += total_exp/party_enemies.stats.heroes_count;
    }
    
}

void Fight::failture_fight_output(){
    std::cout << "Failture!\n";
}

void Fight::fight_mechanics(Party_player& party_enemies){
    
}
