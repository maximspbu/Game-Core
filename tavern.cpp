#include "tavern.h"
#include "hero.h"

Tavern::Tavern(Goods goods){
    this->goods = goods;
}
void Tavern::enterance_screen(){
    std::cout << "Choose options:\n1)Recovery.\t2)Hire heroes.\n";
}
void Tavern::price_list_heroes(Goods goods){
    for (int i = 0; i<goods.heroes.size(); i++){
        std::cout << i+1<< ") "<<goods.heroes[i].get_stats().name<<' '<<goods.heroes[i].get_stats().price<<'\n';
    }
}
void Tavern::buy_hero(Party_player& party){
    std::cout << "Do you want to buy a hero?\n1)Yes\t2)No\n";
    int turn;
    std :: cin >> turn;
    if (turn == 1){
        if (party.stats.cur_heroes_count>=party.stats.heroes_count){
            std::cout << "You have already max count of heroes.\n";
        } else{
        std::cout << "Enter the index of the hero:\n";
        std::cin>>turn;
        //party.add_character(arr[i]);
        //party.stats.money -= arr[i].stats.money
        //set index of new hero
        }
    }
}
void Tavern::recovery(Party_player& party){
    std::cout << "Recovery will cost ... money. Do you want to recovery?\n1)Yes\t2)No\n";
    int turn;
    std::cin >> turn;
    if (turn==1){
        for (int i = 0; i<party.stats.heroes_count; i++){
            //party.stats.party[i].
        }
    } else if (turn==2) {

    }
}