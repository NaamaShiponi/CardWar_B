#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include <iostream>


using namespace std;

namespace ariel {
    class Game {
        Player& player1;
        Player& player2;


    public:
        ~Game();
        Game(Player& player1,Player& player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner(); 
        void printLog(); 
        void printStats();

    private:
        void createPileCards();


    };
};
#endif