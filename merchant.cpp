#include "merchant.h"
#include <iostream>
Merchant::Merchant(Goods goods){
    this->goods = goods;
}

void Merchant::enterance_screen(){
    std::cout << "What do you want to buy?\n";
    std::cout << "1)Weapons.\t2)Armor.\t3)Consumables.\n";
    int turn;
    std::cin >> turn;
    if (turn==1){
        price_list_weapon();
    }
    else if (turn==2){
        price_list_armor();
    }
    else if (turn==3){
        price_list_consumables();
    }
    else if (turn==0){

    }
}
void Merchant::price_list_armor(){

}
void Merchant::buy_armor(){

}
void Merchant::price_list_weapon(){

}
void Merchant::buy_weapon(){

}
void Merchant::price_list_consumables(){

}
void Merchant::buy_consumables(){

}
void Merchant::price_list_spells(){

}
void Merchant::buy_spell(){

}