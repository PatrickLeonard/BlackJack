#include "BlackJackPlayer.h"

//Set defaults for member variables for the player.
BlackJackPlayer::BlackJackPlayer()
{
    name = "Player";

    chipStack = 500;

    hand = new BlackJackHand;
}

//Creates a BlackJackPlayer object with the name input and dealing two cards to the hand.
BlackJackPlayer::BlackJackPlayer(std::string n, PlayingCard *c1, PlayingCard *c2)
{
    name = n;

    chipStack = 500;

    hand = new BlackJackHand(c1, c2);
}

//Delete's the DMA hand when BJP is destroyed.
BlackJackPlayer::~BlackJackPlayer()
{
    delete hand;
}

//Returns the BJP objects name member variable.
std::string BlackJackPlayer::getName()
{
    return name;
}

//Returns the chipStack member variable.
int BlackJackPlayer::getChipStack()
{
    return chipStack;
}

//Sets the wager member variable.
void BlackJackPlayer::setWager(int w)
{
    wager = w;
}

//Returns the wager member variable.
int BlackJackPlayer::getWager()
{
    return wager;
}

//Takes in a string to adjust chipStack
//by the appropriate amount.
void BlackJackPlayer::handOutcome(std::string outcome)
{
    if(outcome == "win")
        {
            chipStack += wager;
        }
    else if(outcome == "lose")
        {
            chipStack -= wager;
        }
    else if(outcome == "blackjack")
        {
            chipStack += (wager * 3);  //3:1 odds for Black Jack
        }
    else
        {
            cout << "~--Outcome error!!--~";
        }
}

//Takes a pointer to a playingCard and
//places it into the player's hand.
void BlackJackPlayer::hit(PlayingCard *h)
{
    hand->addCard(h);
}

//Returns the 'best' score for the player's hand.
int BlackJackPlayer::stay()
{
    if(hand->getHighScore() <= WIN_NUM)
        {
            return hand->getHighScore();
        }
    else
        {
            return hand->getLowScore();
        }
}

//Returns a string of the codes for player's hand.
std::string BlackJackPlayer::showHand()
    {
        return hand->getAllCardCodes();
    }


//DEALER BEGINS HERE

//Creates a shuffled card deck and
//adds two cards to the dealer's hand
BlackJackDealer::BlackJackDealer()
{
    deck = new PlayingCardDeck(SHUFFLE_NUM);

    hand->addCard(dealCard());

    hand->addCard(dealCard());

}

//Deletes the dealer's deck object.
BlackJackDealer::~BlackJackDealer()
{
    delete deck;
}

//Returns a pointer to a playingCard
//to be added to the dealer and player's hand.
PlayingCard* BlackJackDealer::dealCard()
{
    return deck->dealCard();
}

//Determine if the dealer can take another card
//true it the dealer can, and false if not.
bool BlackJackDealer::canTakeHit()
{
    //If the highscore is within the dealer num and win num then dealer cannot take a card
    if((hand->getHighScore() >= DEALER_NUM) && hand->getHighScore() <= WIN_NUM)
        {
            return false;
        }
    //If the lowscore is below the dealer num then dealer can take a card.
    else if(hand->getLowScore() < DEALER_NUM)
        {
            return true;
        }
}

//Returns the 'best' score for the dealer.
int BlackJackDealer::stay()
{
    if(hand->getLowScore() >= DEALER_NUM)
        {
            return hand->getLowScore();
        }
    else
        {
            return hand->getHighScore();
        }
}

//Determines if the deck needs to be reset.
//If so the deck's reset() and shuffle() are called.
void BlackJackDealer::resetCheck()
{
    if(deck->getCountRemain() <= 10) //10 is specified in instructions to reset the deck.
        {
            deck->reset();
            deck->shuffle(SHUFFLE_NUM);
        }
}

//Returns a string where the first cardCodes
//of the hand are removed and replaced with
//XX to represent the hole card.
string BlackJackDealer::holeCardHand()
{
    string holeCard = "XX";

    string tempHand = hand->getAllCardCodes();

    tempHand.erase(0,2);

    tempHand.insert(0,holeCard);

    return tempHand;
}
