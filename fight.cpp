#include "fight.h"
#include <iostream>


Fight::Fight(std::vector<std::string> list){
    list_enemies = list;
    turn = 0;
    complete_action = false;
}

Party_player Fight::create_party(){
    Party_player party_enemies;
    party_enemies.stats.heroes_count = 3+rand()%5;
    party_enemies.stats.cur_heroes_count = party_enemies.stats.heroes_count;
    for (int i = 0; i<party_enemies.stats.heroes_count; i++){
        int num_rand_file = rand()%(list_enemies.size());
        //add_character
        Character new_enemy(list_enemies[num_rand_file]);
        party_enemies.stats.party.push_back(new_enemy);
    }
    return party_enemies;
}

void Fight::entrance_screen(Party_player& party){
    Party_player party_enemies = create_party();
    turn = 0;
    choose_action(party, party_enemies); //return bool
}

void Fight::choice(Party_player& party, bool is_ai, int i){
    if (!is_ai){
        std::cout << "Choose action for Character#" << i+1 << '\n';
        std::cout << "1)Attack\t2)Defend\t3)Spell\t4)Use a consumable\n";
        std::cin>>input;
        if (input==1){
            std::cout << "Choose target to attack\n";
            std::cin >> target;
            target-=1;
        } if (input==3){
            std::cout << "Choose spell:\n";
            for (int x = 0; x<party.stats.party[i].stats["count_spells"]; i++){
                std::cout << x+1 << ") " << (*party.stats.party[i].equipments["spell"+(char)(x+1)]).name << '\n';
            }
            std::cin >> type;
            type-=1;
            std::cout << "Choose target\n";
            std::cin >> target;
            target-=1;
        } if (input == 4){
            /*
            for (int i = 0; i<party.stats.inventory.inventory_player["consumables"].size(); i++){
            std::cout << i+1 << ") " << party.stats.inventory.inventory_player["consumables"][i].brief << '\n';
            std::cin >> item;

            }
            */
        }
        return;
    }
    int rand_input = std::rand()%10;
    int rand_target = std::rand()%16;
    //std::cout << rand_input << '\n';
    if (rand_input>0){
        input=1;
        //std::cout << rand_input << '\n';
        std::cout << rand_input << ' ' << rand_target << '\n';
        if (rand_target<=7){
            this->target = 0;
        } else if (8<=rand_target<=11){
            this->target = 1;
        } else if (12<=rand_target<=13){
            this->target = 2;
        } else {
            this->target = 3;
        }
    } else {
        input = 2;
    }
}

void Fight::choose_action(Party_player& party_heroes, Party_player& party_enemies){
    int status = 0;
    while (status==0){ //while fight_status==0
        status = fight_status(party_heroes, party_enemies);
        if (turn%2==0){
            fight_mechanics(party_heroes, party_enemies);
        } else {
            fight_mechanics(party_enemies, party_heroes);
        }
        turn+=1;
    }
    if (status==-1){
        failture_fight_output();
    } else if (status==1) {
        victory_fight_output(party_heroes, party_enemies);
    }
}

void Fight::victory_fight_output(Party_player& party_heroes, Party_player& party_enemies){
    std::cout << "Victory!\n";
    int total_exp = 0;
    int total_money = 0;
    for (int i = 0; i<party_enemies.stats.heroes_count; i++){
        total_money += party_enemies.stats.party[i].stats["money"];
        total_exp += party_enemies.stats.party[i].stats["exp"];
    }
    std::cout << "Gained:\nMoney:\t" << total_money << '\n';
    party_heroes.stats.money+=total_money;
    for (int i = 0; i<party_heroes.stats.cur_heroes_count; i++){
        party_heroes.stats.party[i].stats["exp"] += total_exp/party_enemies.stats.heroes_count;
    }
}

void Fight::failture_fight_output(){
    std::cout << "Failture!\n";
}

void Fight::fight_mechanics(Party_player& party1, Party_player& party2){
    for (int i = 0; i<party1.stats.cur_heroes_count; i++){ //party_heroes.stats.cur_heroes_count
        complete_action=false;
        if (party1.stats.party[i].is_dead) continue;
        while (!complete_action){
            //if character[i] is not dead (else break)
            choice(party1, turn%2, i);
            if (input == 0){
                complete_action=true;
            } if (input==1){
                complete_action = attack_action(party1, party2, i);
            } if (input==4){
                complete_action = use_consumables_action(party1, i);
            } if (input==2){
                complete_action = defend_action(party1, i);
            } if (input==3){
                complete_action = spell_action(party1, party2, i);
            }
            if (complete_action)
            fight_status(party1, party2);
        }
    }
}

bool Fight::attack_action(Party_player& party1, Party_player& party2, int i){
    //if enemy[target] is not dead (else return false)
    //hit%
    //evasion
    std::cout << party2.stats.cur_heroes_count << '\n';
    std::cout << target << '\n';
    if (target>=party2.stats.cur_heroes_count) return false;
    if (party2.stats.party[target].is_dead) return false;
    std::cout << "flag\n";
    party1.stats.party[i].attack(party2.stats.party[target]);
    std::cout << "Character#" << i << " deals " << "damage to\n";
    return true;
}

bool Fight::defend_action(Party_player& party1, int i){
    party1.stats.party[i].defend(); //stats["bonus_defense"] = 0.5*stats["defense"]
    std::cout << "Character#" << i << " increases armor to " << party1.stats.party[i].stats["defense"] << "\n";
    return true;
}

bool Fight::spell_action(Party_player& party1, Party_player& party2, int i){
    if (party2.stats.party[target].is_dead) return false;
    party1.stats.party[i].use_spell(party2.stats.party[target]);
    return true;
}

bool Fight::use_consumables_action(Party_player& party1, int i){
    return party1.stats.inventory.use_consumable(party1.stats.party[i]);
}

int Fight::fight_status(Party_player& party1, Party_player& party2){
    //fighting 0, failture -1, victory 1
    int c1=0;
    int c2=0;
    std::cout<<"You:\n";
    for (int i = 0; i < party1.stats.cur_heroes_count; ++i){
        std::cout << party1.stats.party[i].name << ":\tHP:"<<party1.stats.party[i].stats["cur_hp"]<<"\tMP:"<<party1.stats.party[i].stats["cur_mp"]<<"\n";
        if (party1.stats.party[i].is_dead) c1+=1;
    }
    std::cout<<"Enemy:\n";
    for (int i = 0; i < party2.stats.cur_heroes_count; ++i){
        std::cout << party2.stats.party[i].name << ":\tHP:"<<party2.stats.party[i].stats["cur_hp"]<<"\tMP:"<<party2.stats.party[i].stats["cur_mp"]<<"\n";
        if (party2.stats.party[i].is_dead) c2+=1;
    }
    if (c1==party1.stats.cur_heroes_count){
        return -1;
    } else if (c2==party2.stats.cur_heroes_count){
        return 1;
    }
    return 0;
    //check if fight is over return -1 || 1;
}
