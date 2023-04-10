#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <cstdlib>

using namespace std;

using namespace ariel;

Game::Game(Player& p1,Player& p2): player1(p1),player2(p2){ 
    createPileCards();
}

void Game::createPileCards(){

    Card arrCard[52]; 
    int top = -1;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            arrCard[++top] = Card(i, j);
        }
    }
    
    //shuffle_array
    int shuffleNum = rand() % 60 + 40;         // randNum1 in the range 40 to 99

    for (int i = 0; i < shuffleNum; i++) {
        int k = rand() % 52;         // i in the range 0 to 51
        int j = rand() % 52;         // j in the range 0 to 51
        Card temp= arrCard[k];
        arrCard[k]=arrCard[j];
        arrCard[j]=temp;
    }

    for (int i = 0; i < 52; i += 2) {
        this->player1.addToStackPlayer(arrCard[i]);
        this->player2.addToStackPlayer(arrCard[i + 1]);
    }

}

Game::~Game(){

}
void Game::playTurn(){
    
}
void Game::printLastTurn(){

}
void Game::playAll(){

}
void Game::printWiner(){

} 
void Game::printLog(){

} 
void Game::printStats(){

}


