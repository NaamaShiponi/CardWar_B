#include <iostream>
#include "card.hpp"

using namespace std;

using namespace ariel;

Card::Card(int num, int type) {
    this->num = num;
    this->type = type;
}

int Card::getNum() const{
    return this->num;
}
int Card::getType() const {
    return this->type;
}
