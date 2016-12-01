#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED
#include "BlackJackPlayer.h"
#include "PlayingCard.h"
#include "BlackJackHand.h"
#include "PlayingCardDeck.h"

class BlackJack
    {
        protected:

        //Pointers to Player and Dealer Objects.
        BlackJackPlayer* player;
        BlackJackDealer* dealer;

        public:

        //Default Constructor
        BlackJack();

        //Overloaded Constructor
        BlackJack(std::string name);

        //Destructor
        ~BlackJack();

        //Checks for if the deck needs to be reset
        //and deals cards to empty hands as needed.
        void newHand();

        //Returns the player objects chipstack total.
        int getChipStack();

        //sets the player objects wager member variable.
        void makeBet(int bet);

        //Displays both hands with the dealer's hole card
        //down.
        void showHoleHand();

        //Displays both hands showing the dealer's hold card.
        void showBothHand();

        //Returns bool for if player has blackjack.
        bool getPlayerBlackJack();

        //Returns bool for if dealer has blackjack.
        bool getDealerBlackJack();

        //Adds a card to the player's blackjackhand.
        void playerHit();

        //Adds a card to the dealer's blackjackhand.
        void dealerHit();

        //Returns a bool for if the player has bust.
        bool getIsPlayerBust();

        //Returns a bool for if the dealer can take
        //a card.
        bool canDealerHit();

        //Returns a bool for if the dealer can takk
        //a card.
        bool canPlayerHit();

        //Displays and impliments the proper outcome
        //of the game.
        void outcomes();

        //Clears the player and dealer's hands.
        void clearHands();
    };


#endif // BLACKJACK_H_INCLUDED
