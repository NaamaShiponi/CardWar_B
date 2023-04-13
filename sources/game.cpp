#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;

using namespace ariel;

Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2) 
{
    createPileCards();
}

// This function creates a new pile of cards, consisting of cards with numbers between 1 and 13, and suits between 1 and 4.
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

    // Randomly shuffle 
    random_shuffle(deck.begin(), deck.end());
    
    // Distribute the cards equally between the two players
    for (int i = 0; i < 26; i++)
    {
        this->player1.addToStackPlayer(deck.back());
        deck.pop_back();
        this->player2.addToStackPlayer(deck.back());
        deck.pop_back();
    }
    
}


// This function represents a turn in the game.
void Game::playTurn()
{
    CTSp1.clear();
    CTSp2.clear();
    if (&player1 == &player2)
    {
        // If player 1 and player 2 are the same, an exception is thrown.
        throw std::exception();
    }
    if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
    {
        // If one of the players has no cards left, an exception is thrown.
        throw std::exception();
    }

    bool inTurn = true;
    while (inTurn && this->player1.stacksize() != 0 && this->player2.stacksize() != 0)
    {
        // Each player draws a card from the top of their deck.
        CTSp1.push_back(this->player1.popCardsStack());
        CTSp2.push_back(this->player2.popCardsStack());

        if (CTSp1.rbegin()->getNum() != CTSp2.rbegin()->getNum())
        {
            // If the cards drawn by the players have different numbers, the turn is over.
            inTurn = false;
        }
        else if (this->player1.stacksize() != 0 && this->player2.stacksize() != 0)
        {
            // If the cards drawn by the players have the same number and both players still have cards in their deck, another draw is made.
            this->draws++;
            CTSp1.push_back(this->player1.popCardsStack());
            CTSp2.push_back(this->player2.popCardsStack());
        }
        severalTurns++;

    }
    if (inTurn)
    {
        
        for (auto i = CTSp1.begin(); i != CTSp1.end(); ++i)
        {
            this->player1.addToCardesTaken(*i);
        }
        for (auto i = CTSp2.begin(); i != CTSp2.end(); ++i)
        {
            this->player2.addToCardesTaken(*i);
        }
    }
    /*
    (p1>2 && p2=1) || (p1!=1 && p1 < p2) --> p2
    */
    else if ((CTSp1.rbegin()->getNum() > 2 && CTSp2.rbegin()->getNum() == 1) || (CTSp1.rbegin()->getNum() != 1 && CTSp1.rbegin()->getNum() < CTSp2.rbegin()->getNum()))
    {
        this->player2.setnumberOfWins(this->player2.getnumberOfWins()+1);
        addCardsToTaken(this->player2,CTSp1,CTSp2);
    }
    else
    { // P1 is the Winer
        this->player1.setnumberOfWins(this->player1.getnumberOfWins()+1);
        addCardsToTaken(this->player1,CTSp1,CTSp2);
    }


    getStrTurn(log);

}

void Game::addCardsToTaken(Player& p, vector<Card> CTSp1, vector<Card> CTSp2 ){
    while(CTSp1.size()>0 && CTSp2.size()>0){
        p.addToCardesTaken(CTSp1.back());
        CTSp1.pop_back();
        p.addToCardesTaken(CTSp2.back());
        CTSp2.pop_back();
    }
}

// This function plays the game that players run out of cards in the pile.
void Game::playAll()
{
    while (this->player1.stacksize() != 0 && this->player2.stacksize() != 0)
    {
        playTurn();
    }
}

// This function prints the winner of the game, or a message if the game is not over.
void Game::printWiner()
{
    cout << endl;
    if (this->player1.stacksize() != 0 && this->player2.stacksize() != 0)
    {
        cout << "The game is not over yet" << endl;
    }
    else if (this->player1.cardesTaken() == this->player2.cardesTaken())
    {
        cout << "The game ended in a draw" << endl;
    }
    else if (this->player1.cardesTaken() > this->player2.cardesTaken())
    {
        cout << this->player1.getname() << " won the game" << endl;
    }
    else
    {
        cout << this->player2.getname() << " won the game" << endl;
    }
}

// This function prints the last turn of the game.
void Game::printLastTurn()
{
    string lastTurn="";
    getStrTurn(lastTurn);
    cout << endl << "----------- printLastTurn -----------";
    cout << endl << lastTurn;
    cout << endl <<  "-----------------------------------------"<< endl;


}

// This function returns the string representation of the last turn of the game.
void Game::getStrTurn(string& s)
{
    int numCardP1;
    int numCardP2;
    std::vector<Card>::size_type i= 0;
    for ( ; i < CTSp1.size(); i++) 
    {
        if(i%2==0){
            s=s+ "\nTurn number "+ to_string(severalTurns) + "\n";
            numCardP1=CTSp1[i].getNum();
            numCardP2=CTSp2[i].getNum();
            s=s+ this->player1.getname()+ " played ";
            s=s+ "(" + to_string(numCardP1) + " , " + to_string(CTSp1[i].getType()) + ") \n" ;
            s=s+ this->player2.getname() + " played ";
            s=s+ "(" + to_string(numCardP2) + " , " + to_string(CTSp2[i].getType()) + ") \n" ;
            if(numCardP1==numCardP2 && i < CTSp1.size()){
            s=s+ "DRAW \n";
            }
        }
    }
    if(numCardP1==numCardP2){
        s=s+ "DRAW \n";
    }
    if((numCardP1 > 2 && numCardP2 == 1) || (numCardP1 != 1 && numCardP1 < numCardP2)){
        s=s+ this->player2.getname() + " won \n";
    }else{
        s=s+ this->player1.getname() + " won \n";
    }

}


void Game::printLog()
{
    cout << endl << "----------- printLog -----------";
    cout << endl << this->log;
    cout << endl <<  "-------------------------------"<< endl;
}


void Game::printStats()
{

    double drawRate = 0.0;
    if(this->severalTurns!=0 && this->draws !=0) {
        drawRate =((this->draws/this->severalTurns)*100);
    }
    double percentageP1Won=0.0;
    if(this->severalTurns!=0 && this->player1.getnumberOfWins() !=0) {
        percentageP1Won=((this->player1.getnumberOfWins()/this->severalTurns)*100);
    }
    double percentageP2Won=0.0;
    if(this->severalTurns!=0 && this->player2.getnumberOfWins() !=0) {
        percentageP2Won=((this->player2.getnumberOfWins()/this->severalTurns)*100);
    }
    

    cout << endl << "----------- printStats -----------"<< endl;
    cout << "General data about the game:"<< endl ;
    cout << "There have been " << this->severalTurns << " turns in the game so far" << endl;
    cout << "draw rate: " << drawRate<< "%" << endl;
    cout << "mount of draws: " << this->draws << endl << endl;

    cout << "Player1 " << this->player1.getname() << ":" << endl;
    cout << "size of cardes taken is " << this->player1.cardesTaken() << endl;
    cout << "he won " << this->player1.getnumberOfWins() << " times, in percentages:" << percentageP1Won <<"% " << endl << endl;

    cout << "Player2 " << this->player2.getname() << ":" << endl;
    cout << "size of cardes taken is " << this->player2.cardesTaken() << endl;
    cout << "he won " << this->player2.getnumberOfWins() << " times, in percentages:" << percentageP2Won <<"% " << endl ;

    cout <<  "-------------------------------------"<< endl;

}

