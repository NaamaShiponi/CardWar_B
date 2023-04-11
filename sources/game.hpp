#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include <iostream>


using namespace std;

namespace ariel {
    class Game {
        Player& player1;
        Player& player2;
        vector<Card> CTSp1;
        vector<Card> CTSp2;
        string log="";
        int severalTurns;
        int draws;

    public:
        Game(const Game& o) : player1(o.player1), player2(o.player2),severalTurns(0), draws(0),CTSp1(o.CTSp1),CTSp2(o.CTSp2) {}
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
        void addCardsToTaken(Player& p, vector<Card> CTSp1, vector<Card> CTSp2 );
        void getStrTurn(string& s);

    };
};
#endif