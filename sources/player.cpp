#include <iostream>
#include "player.hpp"


using namespace std;
using namespace ariel;


Player::Player(string name): name(name) // constructor
{
 this->numberOfWins= 0;
}

int Player::stacksize(){
    return this->cardsStack.size();
}

int Player::cardesTaken(){
    return this->cardesTakenPlayer.size();
}

void Player::addToStackPlayer(Card card){
    this->cardsStack.push_back(card);
}

void Player::addToCardesTaken(Card card){
    this->cardesTakenPlayer.push_back(card);
}

Card Player::popCardsStack(){
    Card card = this->cardsStack.back();
    this->cardsStack.pop_back();
    return card;
}


void Player::printStackPlayer(){
    cout << "print stack OF player " << this->name << ": ";
    for (auto i = this->cardsStack.begin(); i != this->cardsStack.end(); ++i){
        cout << "(" << i->getNum() << " , " << i->getType() << ") " ;
    }
    cout << endl;
}

void Player::printCardesTaken(){
    cout << "print stack of player " << this->name << ": ";
    for (auto i = this->cardesTakenPlayer.begin(); i != this->cardesTakenPlayer.end(); ++i){
        cout << "(" << i->getNum() << " , " << i->getType() << ") " ;
    }
    cout << endl;
}


