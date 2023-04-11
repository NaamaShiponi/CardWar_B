#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;

using namespace ariel;

Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2),severalTurns(0), draws(0) 
{
   
    createPileCards();
}

void Game::createPileCards()
{
    vector<Card> deck;
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            deck.push_back(Card(i, j));
        }
    }

    random_shuffle(deck.begin(), deck.end());
    
    for (int i = 0; i < 26; i++)
    {
        player1.addToStackPlayer(deck.back());
        deck.pop_back();
        player2.addToStackPlayer(deck.back());
        deck.pop_back();
    }
    
}



void Game::playTurn()
{
    if (player1.getname() == player2.getname())
    {
        throw std::exception();
    }
    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        throw std::exception();
    }
    vector<Card> CTSp1;
    vector<Card> CTSp2;
    bool inTurn = true;
    while (inTurn && player1.stacksize() != 0 && player2.stacksize() != 0)
    {
        CTSp1.push_back(player1.popCardsStack());
        CTSp2.push_back(player2.popCardsStack());
        cout << "cards stack P1 " << CTSp1.rbegin()->getNum() << endl;
        cout << "cards stack P2 " << CTSp2.rbegin()->getNum() << endl;

        if (CTSp1.rbegin()->getNum() != CTSp2.rbegin()->getNum())
        {
            inTurn = false;
        }
        else if (player1.stacksize() != 0 && player2.stacksize() != 0)
        {
            this->draws++;
            cout << "draw !!" << endl;
            CTSp1.push_back(player1.popCardsStack());
            CTSp2.push_back(player2.popCardsStack());
        }
        this->severalTurns++;

    }
    if (inTurn)
    {
        cout << "draw" << endl;

        for (auto i = CTSp2.begin(); i != CTSp2.end(); ++i)
        {
            this->player2.addToCardesTaken(*i);
        }
        for (auto i = CTSp1.begin(); i != CTSp1.end(); ++i)
        {
            this->player1.addToCardesTaken(*i);
        }
    }
    /*
    (p1>2 && p2=1) || (p1!=1 && p1 < p2) --> p2
    */
    else if ((CTSp1.rbegin()->getNum() > 2 && CTSp2.rbegin()->getNum() == 1) || (CTSp1.rbegin()->getNum() != 1 && CTSp1.rbegin()->getNum() < CTSp2.rbegin()->getNum()))
    {
        cout << "P2 is the Winer" << endl;
        this->player2.setnumberOfWins(this->player2.getnumberOfWins()+1);
        for (auto i = CTSp2.begin(); i != CTSp2.end(); ++i)
        {
            this->player2.addToCardesTaken(*i);
        }
        for (auto i = CTSp1.begin(); i != CTSp1.end(); ++i)
        {
            this->player2.addToCardesTaken(*i);
        }
    }
    else
    { // P1 is the Winer
        cout << "P1 is the Winer" << endl;
        this->player1.setnumberOfWins(this->player1.getnumberOfWins()+1);
        for (auto i = CTSp2.begin(); i != CTSp2.end(); ++i)
        {
            this->player1.addToCardesTaken(*i);
        }
        for (auto i = CTSp1.begin(); i != CTSp1.end(); ++i)
        {
            this->player1.addToCardesTaken(*i);
        }
    }

    cout << "p1: stacksize " << this->player1.stacksize() << " cardesTaken " << this->player1.cardesTaken() << endl;
    cout << "p2: stacksize " << this->player2.stacksize() << " cardesTaken " << this->player2.cardesTaken() << endl;

    cout << "The Turn is over " << endl;
}

void Game::playAll()
{
    while (player1.stacksize() != 0 && player2.stacksize() != 0)
    {
        playTurn();
    }
}

void Game::printWiner()
{
    cout << endl;
    if (player1.stacksize() != 0 && player2.stacksize() != 0)
    {
        cout << "The game is not over yet" << endl;
    }
    else if (player1.cardesTaken() == player2.cardesTaken())
    {
        cout << "The game ended in a draw" << endl;
    }
    else if (player1.cardesTaken() > player2.cardesTaken())
    {
        cout << player1.getname() << " won the game" << endl;
    }
    else
    {
        cout << player2.getname() << " won the game" << endl;
    }
}

void Game::printLastTurn()
{

}
void Game::printLog()
{

}
void Game::printStats()
{
    double drawRate = 0;
    if(this->severalTurns!=0 && this->draws !=0) 
        drawRate =((this->severalTurns/this->draws)*100);
    int percentageP1Won=0;
    if(this->severalTurns!=0 && this->player1.getnumberOfWins() !=0) 
        percentageP1Won=((this->severalTurns/this->player1.getnumberOfWins())*100);
    int percentageP2Won=0;
    if(this->severalTurns!=0 && this->player2.getnumberOfWins() !=0) 
        percentageP2Won=((this->severalTurns/this->player2.getnumberOfWins())*100);
    

    cout << endl << "----------- printStats -----------"<< endl;
    cout << "General data about the game:"<< endl ;
    cout << "There have been " << this->severalTurns << " turns in the game so far" << endl;
    cout << "draw rate: " << drawRate<< "%" << endl;
    cout << "mount of draws: " << this->draws << endl << endl;

    cout << "Player1 " << player1.getname() << ":" << endl;
    cout << "size of cardes taken is " << player1.cardesTaken() << endl;
    cout << "he won " << this->player1.getnumberOfWins() << " times, in percentages:" << percentageP1Won <<"% " << endl << endl;

    cout << "Player2 " << player2.getname() << ":" << endl;
    cout << "size of cardes taken is " << player2.cardesTaken() << endl;
    cout << "he won " << this->player2.getnumberOfWins() << " times, in percentages:" << percentageP2Won <<"% " << endl ;

    cout <<  "-------------------------------------"<< endl;

}
Game::~Game()
{

}
