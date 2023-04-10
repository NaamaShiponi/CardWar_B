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



    public:
        Player(string name);// constructor
        ~Player();

        string getname();
        int stacksize();
        int cardesTaken();

        void addToStackPlayer(Card card);
        void addToCardesTaken(Card card);

        void printStackPlayer();
        void printCardesTaken();



    };
};
#endif