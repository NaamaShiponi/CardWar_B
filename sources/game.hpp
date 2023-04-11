#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "player.hpp"

using namespace std;

namespace ariel {
    class Game {
        Player& player1;
        Player& player2;
        vector<Card> CTSp1;
        vector<Card> CTSp2;
        string log="";
        double severalTurns=0;
        double draws=0;

    public:
        Game(Player& player1,Player& player2);

        Player& getplayer1(){ return player1;}
        Player& getplayer2(){ return player2;}

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner(); 
        void printLog(); 
        void printStats();

    private:
        void createPileCards();
        void addCardsToTaken(Player& p, vector<Card> CTSp1, vector<Card> CTSp2 );
        void getStrTurn(string& s);

    };
};
#endif