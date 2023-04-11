#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include <iostream>


using namespace std;

namespace ariel {
    class Game {
        Player& player1;
        Player& player2;
        int severalTurns;
        int draws;

    public:
        Game(const Game& o) : player1(o.player1), player2(o.player2),severalTurns(0), draws(0) {}
        Game(Game&& other) noexcept: player1(other.player1),player2(other.player2),severalTurns(0), draws(0){}   
        Game& operator=(const Game& other){return *this;}
        Game& operator=(Game&& other) noexcept {return *this;}
        ~Game();
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


    };
};
#endif