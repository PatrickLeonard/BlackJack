#ifndef PLAYINGCARDDECK_H_INCLUDED
#define PLAYINGCARDDECK_H_INCLUDED

#include "PlayingCard.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class PlayingCardDeck
{
        private:

        static const int SIZE = 52;

        PlayingCard* deck[SIZE];

        //Creates an unshuffled deck
        void deckCreation();

        public:

        /*Default constructor. Creates an unshuffled deck of 52 playing cards.
        These playing cards are to be implemented as pointers to PlayingCards.
        Remember, since this uses pointers, the PlayingCard objects are
        dynamically allocated and must be managed as such.*/
        PlayingCardDeck();


        /*Overloaded constructor. In addition to what is described for the default
        constructor, this constructor shuffles the deck numShuffles times.*/
        PlayingCardDeck(int numShuffles);


        /*Destructor. This is necessary because of the dynamic memory allocation.
        When a deck is deleted, the cards remaining in the deck must be deleted.*/
        ~PlayingCardDeck();


        /*Returns a pointer to a PlayingCard object taken from "the top" of the deck.
        If there are no more cards in the deck, it returns a null pointer (i.e. 0)
        and displays a warning.*/
        PlayingCard* dealCard();

        /*Shuffle should only shuffle if no cards have been dealt from the deck.
        If one or more cards has been dealt, then the function should return false
        and no shuffling should be done.*/
        bool shuffle(int numShuffles);

        /*Resets the deck to a full deck of 52 unshuffled cards. Remember that when
        you do this, you must manage the dynamically allocated cards in the deck.*/
        void reset();

        /*Returns a string containing all the value and suit codes for the deck.
        If there have been cards dealt from the deck, those cards will not be displayed.
        The cards should be displayed with a single space between each card and a line
         break after the 13th, 26th, 39th, and 52nd cards from the original deck.*/
        string getAllCardCodes();

        /*Returns the number of cards already dealt from the deck.*/
        int getCountUsed();

        /*Returns the number of cards remaining in the deck.*/
        int getCountRemain();


};
#endif // PLAYINGCARDDECK_H_INCLUDED
