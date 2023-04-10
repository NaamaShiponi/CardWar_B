#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

namespace ariel {

    class Card {
        int num;
        int type;
    public:
        Card();
        Card(int num, int type);
        Card(const Card& o);
        Card(Card&& o) noexcept;
        Card& operator=(const Card& other);
        Card& operator=(Card&& other) noexcept;
        ~Card();

        int getNum() const;
        int getType() const;
    
    };
};
#endif