#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

#include "card.hpp"

using namespace ariel;

using namespace std;

namespace ariel {

    class Player {
        string name;
        vector<Card> cardsStack;
        vector<Card> cardesTakenPlayer;
        int numberOfWins=0;



    public:
        Player(const Player& o){}
        Player(Player&& o) noexcept{}
        Player& operator=(const Player& other){return *this;}
        Player& operator=(Player&& other) noexcept {return *this;}
        Player(string name);// constructor
        ~Player();

        string getname(){return this->name;}
        int getnumberOfWins()const{return this->numberOfWins;}
        void setnumberOfWins(int n){this->numberOfWins=n;}


        int stacksize();
        int cardesTaken();

        void addToStackPlayer(Card card);
        void addToCardesTaken(Card card);

        Card popCardsStack();

        void printStackPlayer();
        void printCardesTaken();



    };
};
#endif