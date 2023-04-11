#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

namespace ariel {

    class Card {
        int num;
        int type;
    public:
        Card(int num=0, int type=0);
   
        int getNum() const;
        int getType() const;

    
    };
};
#endif