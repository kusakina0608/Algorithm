//
// Created by Kina on 2020/04/24.
//
#include <iostream>
#define MONEY 5000
#define ITEM_PRICE_1 500
#define ITEM_PRICE_2 800
#define ITEM_PRICE_3 1000

using namespace std;

int price[] = {0, ITEM_PRICE_1, ITEM_PRICE_2, ITEM_PRICE_3};

int main(void){
    int total_price = 0;
    int btn = 0;
    do {
        cin>>btn;
        total_price += price[btn];
    } while (getc(stdin) == ' ');
    cout<<(MONEY-total_price);
    return 0;
}