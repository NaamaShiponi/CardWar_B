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
        double numberOfWins;



    public:
        Player(string name);// constructor

        string getname(){return this->name;}
        double getnumberOfWins()const{return this->numberOfWins;}
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