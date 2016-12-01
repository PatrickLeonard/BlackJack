#ifndef PLAYINGCARD_H_INCLUDED
#define PLAYINGCARD_H_INCLUDED

#include <string>
using namespace std;

class PlayingCard
{
    private:

        char value,
             suit;

    public:

        PlayingCard();
        //Default constructor, sets value to '0', sets suit to '0'

        PlayingCard(char myValue, char mySuit);
        /*Overloaded constructor, checks for valid myValue and mySuit.
        If they are valid it sets value and suit to those values.
        If either of them is not valid, it sets them both to '0'. */

        bool setCard(char myValue, char mySuit);
        /*Checks for valid myValue and mySuit.
        If they are valid it sets value and suit to those values.
        If either of them is not valid, it returns false and does not change any values.*/

        char getValue();
        //Returns the card's value, one of A23456789TJQK (and Z if you are doing jokers).

        char getSuit();
        //Returns the card's suit, one of CHDS (and BR if you are doing jokers).

        string getCardCode();
        /*Returns a string containing the 2 characters associated with the card.
        For example for the 7 of spades it would return the string "7S".
        It does not include any spaces.*/

        bool isValid();
        //Returns true if the card is a valid card, false if it is not.

};

#endif // PLAYINGCARD_H_INCLUDED
