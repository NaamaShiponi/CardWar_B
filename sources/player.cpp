#include <iostream>
#include "player.hpp"


using namespace std;
using namespace ariel;

Player::~Player(){
    
}
Player::Player(string name): name(name), numberOfWins(0){} // constructor

int Player::stacksize(){
    return cardsStack.size();
}

int Player::cardesTaken(){
    return cardesTakenPlayer.size();
}

void Player::addToStackPlayer(Card card){
    cardsStack.push_back(card);
}

void Player::addToCardesTaken(Card card){
    cardesTakenPlayer.push_back(card);
}

Card Player::popCardsStack(){
    Card card = cardsStack.back();
    cardsStack.pop_back();
    return card;
}


void Player::printStackPlayer(){
    cout << "print stack OF player " << this->name << ": ";
    for (auto i = cardsStack.begin(); i != cardsStack.end(); ++i){
        cout << "(" << i->getNum() << " , " << i->getType() << ") " ;
    }
    cout << endl;
}

void Player::printCardesTaken(){
    cout << "print stack of player " << this->name << ": ";
    for (auto i = cardesTakenPlayer.begin(); i != cardesTakenPlayer.end(); ++i){
        cout << "(" << i->getNum() << " , " << i->getType() << ") " ;
    }
    cout << endl;
}


