#include "../include/fight.h"


//Fight::Fight(const std::vector<std::vector<std::string>>& file_list): Location(file_list){}

Party Fight::CreateParty(){
    Party party_enemies("sources/party/enemy.txt");
    party_enemies.stats["members_count"] = 3+rand()%5;
    party_enemies.stats["cur_members_count"] = party_enemies.stats["members_count"];
    for (int i = 0; i<party_enemies.stats["members_count"]; ++i){
        int num_rand_file = rand()%(fileList_[0].size());
        //AddCharacter
        Character new_enemy(fileList_[0][num_rand_file]);
        party_enemies.party.push_back(new_enemy);
    }
    return party_enemies;
}

void Fight::EntranceScreen(Party& party){
    if (party.stats["cur_members_count"] == 0){
        std::cout << "Hire heroes in tavern before you can fight.\n";
        return;
    }
    Party party_enemies = CreateParty();
    turn = 0;
    ChooseAction(party, party_enemies); //return bool
}

void Fight::Choice(Party& party, bool is_ai, int i){
    if (!is_ai){
        std::cout << "Choose action for Character#" << i+1 << '\n';
        std::cout << "1)Attack\t2)Defend\t3)Spell\t4)Use a consumable\n";
        std::cin>>input;
        if (input==1){
            std::cout << "Choose target to attack\n";
            std::cin >> target;
            --target;
        } if (input==3){
            std::cout << "Choose spell:\n";
            for (int x = 0; x<party.party[i].stats["count_spells"]; ++i){
                std::cout << x+1 << ") " << (*party.party[i].equipments_["spell"+(char)(x+1)]).GetDescription("name") << '\n';
            }
            std::cin >> type;
            --type;
            std::cout << "Choose target\n";
            std::cin >> target;
            --target;
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
    if (rand_input>0){
        input=1;
        //std::cout << rand_input << '\n';
        //std::cout << rand_input << ' ' << rand_target << '\n';
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

void Fight::ChooseAction(Party& party_heroes, Party& party_enemies){
    int status = 0;
    while (status==0){
        status = FightStatus(party_heroes, party_enemies);
        if (turn%2==0){
            FightMechanics(party_heroes, party_enemies);
        } else {
            FightMechanics(party_enemies, party_heroes);
        }
        turn+=1;
    }
    if (status==-1){
        FailtureFightOutput();
    } else if (status==1) {
        VictoryFightOutput(party_heroes, party_enemies);
    }
}

void Fight::VictoryFightOutput(Party& party_heroes, Party& party_enemies){
    std::cout << "Victory!\n";
    int total_exp = 0;
    int total_money = 0;
    for (int i = 0; i < party_enemies.stats["cur_members_count"]; ++i){
        total_money += party_enemies.party[i].stats["money"];
        total_exp += party_enemies.party[i].stats["exp"];
        if (party_enemies.party[i].description["name"]==(*party_heroes.inventory_.GetInventory("quest", 0)).GetDescription("enemy_name")){
            party_heroes.inventory_.inventoryPlayer_["quest"][0].stats["cur_count"]++;
        }
    }
    std::cout << "Gained:\nMoney:\t" << total_money << '\n';
    std::cout << "Exp (for each hero): " << total_exp/party_heroes.stats["cur_members_count"] << '\n';
    if (party_heroes.inventory_.inventoryPlayer_["quest"][0].stats["cur_count"] > party_heroes.inventory_.inventoryPlayer_["quest"][0].stats["count"]){
        std::cout << "You have completed quest#1\n";
        party_heroes.inventory_.inventoryPlayer_["quest"].erase(party_heroes.inventory_.inventoryPlayer_["quest"].end() - 1);
    }
    party_heroes.stats["money"]+=total_money;
    for (int i = 0; i<party_heroes.stats["cur_members_count"]; i++){
        party_heroes.party[i].stats["cur_exp"] += total_exp/party_heroes.stats["cur_members_count"];
        party_heroes.party[i].LevelUp();
    }
}

void Fight::FailtureFightOutput(){
    std::cout << "Failture!\n";
}

void Fight::FightMechanics(Party& party1, Party& party2){
    int x=0;
    for (int i = 0; i<party1.stats["cur_members_count"]; i++){
        completeAction=false;
        if (party1.party[i].is_dead) continue;
        while (!completeAction){
            Choice(party1, turn%2, i);
            if (input == 0){
                completeAction=true;
            } if (input==1){
                completeAction = AttackAction(party1, party2, i);
            } if (input==4){
                completeAction = UseConsumablesAction(party1, i);
            } if (input==2){
                completeAction = DefendAction(party1, i);
            } if (input==3){
                completeAction = SpellAction(party1, party2, i);
            }
            if (completeAction)
            x = FightStatus(party1, party2);
            if (x != 0) return;
        }
    }
}

bool Fight::AttackAction(Party& party1, Party& party2, int i){
    //if enemy[target] is not dead (else return false)
    //hit%
    //evasion
    std::cout << party2.stats["cur_members_count"] << '\n';
    std::cout << target << '\n';
    if (target >= party2.stats["cur_members_count"]) return false;
    if (party2.party[target].is_dead) return false;
    //std::cout << "flag\n";
    party1.party[i].Attack(party2.party[target]);
    std::cout << "Character#" << i+1 << " deals " << "damage to enemy#" << target + 1 << '\n';
    return true;
}

bool Fight::DefendAction(Party& party1, int i){
    party1.party[i].Defend(); //stats["bonus_defense"] = 0.5*stats["defense"]
    std::cout << "Character#" << i << " increases armor to " << party1.party[i].stats["defense"] << "\n";
    return true;
}

bool Fight::SpellAction(Party& party1, Party& party2, int i){
    if (party2.party[target].is_dead) return false;
    if (party1.party[i].stats["cur_mp"] < party1.party[i].equipments_["spell"]->stats["mp_cost"]) return false;
    party1.party[i].UpdateCurStats(0, -party1.party[i].equipments_["spell"]->stats["mp_cost"]);
    party1.party[i].UseSpell(party2.party[target], type);
    std::cout << "Character#" << i+1 << " deals " << "damage to enemy#" << target + 1 << '\n';
    return true;
}

bool Fight::UseConsumablesAction(Party& party1, int i){
    return party1.inventory_.UseConsumable(party1.party[i]);
}

int Fight::FightStatus(Party& party1, Party& party2){
    //fighting 0, failture -1, victory 1
    int c1 = 0;
    int c2 = 0;
    if (turn%2==0) std::cout << "You:\n";
    for (int i = 0; i < party1.stats["cur_members_count"]; ++i){
        if (turn%2==0) std::cout << party1.party[i].description["name"] << ":\tHP:" << party1.party[i].stats["cur_hp"] << "\tMP:" << party1.party[i].stats["cur_mp"]<<"\n"; //Character::ShowMainStats
        if (party1.party[i].is_dead) c1 += 1;
    }
    if (turn%2==0) std::cout << "Enemy:\n";
    for (int i = 0; i < party2.stats["cur_members_count"]; ++i){
        if (turn%2==0) std::cout << party2.party[i].description["name"] << ":\tHP:" << party2.party[i].stats["cur_hp"] << "\tMP:" << party2.party[i].stats["cur_mp"]<<"\n";
        if (party2.party[i].is_dead) c2 += 1;
    }
    if (c1 == party1.stats["cur_members_count"]){
        return -1;
    } else if (c2 == party2.stats["cur_members_count"]){
        return 1;
    }
    return 0;
    //check if fight is over return -1 || 1;
}
