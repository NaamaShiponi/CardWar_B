#include <iostream>
#include "card.hpp"

using namespace std;

using namespace ariel;

Card::Card() : num(0), type(0) {}

Card::Card(int num, int type) : num(num), type(type) {}

Card::Card(const Card& o) : num(o.getNum()), type(o.getType()) {}

Card::Card(Card&& o) noexcept {
    this->num = o.num;
    this->type = o.type;
    o.num = 0;
    o.type = 0;
}

Card& Card::operator=(const Card& other) {
    if (this != &other) {
        this->num = other.getNum();
        this->type = other.getType();
    }
    return *this;
}

    Card& Card::operator=(Card&& other) noexcept {
        if (this != &other) {
            this->num = other.num;
            this->type = other.type;
            other.num = 0;
            other.type = 0;
        }
        return *this;
    }

    Card::~Card() {}
int Card::getNum() const{
    return this->num;
}
int Card::getType() const {
    return this->type;
}