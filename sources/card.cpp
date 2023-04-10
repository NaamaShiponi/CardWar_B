#include <iostream>
#include "card.hpp"

using namespace std;

using namespace ariel;

Card::Card(): num(0),type(0){}

Card::Card(const Card& o){
    this->num=o.getNum();
    this->type=o.getType();
}

Card::Card(int num,int type): num(num),type(type){}

int Card::getNum() const{
    return this->num;
}
int Card::getType() const {
    return this->type;
}