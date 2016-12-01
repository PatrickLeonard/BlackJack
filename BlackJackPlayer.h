#ifndef BLACKJACKPLAYER_H_INCLUDED
#define BLACKJACKPLAYER_H_INCLUDED
#include <string>
#include "PlayingCard.h"
#include "BlackJackHand.h"
#include "PlayingCardDeck.h"

class BlackJackDealer;

class BlackJackPlayer
    {
        protected:

        //Player members to hold info of player attributes.
        std::string name;

        int chipStack;

        int wager;

        static const int WIN_NUM = 21;

        public:

        //Pointer to a hand object made public.
        BlackJackHand* hand;

        //Default constructor
        BlackJackPlayer();

        //Overloaded constructor
        BlackJackPlayer(std::string n, PlayingCard *c1, PlayingCard *c2);

        //Destructor
        ~BlackJackPlayer();

        //Returns the name of the player.
        string getName();

        //Returns the value of the chipStack variable.
        int getChipStack();

        //Set the wager to be bet.
        void setWager(int wager);

        //Returns the wager value.
        int getWager();

        //Adds a card to the player's hand and returns true
        //if the hand can take another card, or false if not.
        void hit(PlayingCard *h);

        //Returns the handScore of the player.
        int stay();

        //Returns the codes for the cards in the hand.
        std::string showHand();

        //Changes the chipstack value depend on the outcome.
        void handOutcome(std::string outcome);

    };

//Dealer subclass of players.
class BlackJackDealer:public BlackJackPlayer
    {
        private:

        //The dealer creates and manages the deck.
        PlayingCardDeck* deck;

        static const int DEALER_NUM = 17;

        static const int SHUFFLE_NUM = 20;

        public:

        //Default constructor.
        BlackJackDealer();

        //Destructor.
        ~BlackJackDealer();

        //Returns a pointer to a playingCard object
        //to be dealt to player/dealer's hand
        PlayingCard* dealCard();

        //Enforeces the rules for if the dealer
        //can take another card. Returns bool.
        bool canTakeHit();

        //Returns the 'best' score for the dealer.
        int stay();

        //Displays dealer's hand with the first card
        //as XX to represent the hole card.
        string holeCardHand();

        //Checks the amount of cards remaining in the deck
        //if there are <10 it calls the deck's reset function.
        void resetCheck();

    };

#endif // BLACKJACKPLAYER_H_INCLUDED
