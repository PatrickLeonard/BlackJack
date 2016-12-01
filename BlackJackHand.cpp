#include "BlackJackHand.h"
using namespace std;

//Default constructor, initialize member values to 0 or NULL
BlackJackHand::BlackJackHand()
    {
        for(int i = 0; i <= SIZE; i++)
            {
                hand[i] = NULL;
            }
    }

//Overloaded constructor, assign cardCount to two
//Initialize pointer array to NULL
//Assign first two pointer array elements to pointer args.
BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2)
    {
        for(int i = 0; i <= SIZE; i++)
            {
                hand[i] = NULL;
            }

        hand[0] = c1;
        hand[1] = c2;
    }

//Increments card count, and adds card pointer to array
bool BlackJackHand::addCard(PlayingCard *card)
    {

        if(canTakeCard())
            {
                hand[getCardCount()] = card;
                return true;
            }
        else
            {
                cout << "\n--Warning, cannot add card--\n";
                return false;
            }
    }

//Returns the number of cards in the current hand.
int BlackJackHand::getCardCount()
    {
        int cardCount = 0;

        for(int i = 0; i < SIZE; i++)
            {
                if(hand[i] != NULL)
                    {
                        cardCount++;
                    }
            }

        return cardCount;
    }


//Returns the current hand score with first Ace counted as 11.
int BlackJackHand::getHighScore()
    {
        int highScore = 0;
        bool firstAce = false;
        for(int i = 0; i < getCardCount(); i++)
            {
                if((hand[i]->getValue() == 'T') ||
                   (hand[i]->getValue() == 'J') ||
                   (hand[i]->getValue() == 'Q') ||
                   (hand[i]->getValue() == 'K'))
                   {
                       highScore += 10; //Royal Card value
                   }
                else if(hand[i]->getValue() == 'A' && !firstAce)
                    {
                        highScore += 11; //High Ace value
                        firstAce = true;
                    }
                else if(hand[i]->getValue() == 'A' && firstAce)
                    {
                        highScore += 1; //Low Ace value

                    }
                else
                    {
                        highScore += (hand[i]->getValue() - '0');
                    }
            }

        return highScore;
    }

//Returns current hand score with all Aces valued at 1.
int BlackJackHand::getLowScore()
    {
        int lowScore = 0;

        for(int i = 0; i < getCardCount(); i++)
            {
                if((hand[i]->getValue() == 'T') ||
                   (hand[i]->getValue() == 'J') ||
                   (hand[i]->getValue() == 'Q') ||
                   (hand[i]->getValue() == 'K'))
                   {
                       lowScore += 10; //Royal card values
                   }
                else if(hand[i]->getValue() == 'A')
                    {
                        lowScore += 1; //Low Ace value
                    }
                else
                    {
                        lowScore += (hand[i]->getValue() - '0');
                    }
            }

        return lowScore;
    }

//Resets cardCount to zero, and deletes new array pointers.
void BlackJackHand::clearHand()
    {
        for(int i = 0; i < SIZE; i++)
            {
                delete hand[i];
            }

        for(int i = 0; i <= SIZE; i++)
            {
                hand[i] = NULL;
            }

    }

//Returns true if hand is busted.
bool BlackJackHand::isBust()
    {
        return (getLowScore() > WIN);
    }

//Returns true if hand has five cards in it.
bool BlackJackHand::isFull()
    {
        return (getCardCount() == SIZE);
    }

//Returns true if hand is able to accept another card.
bool BlackJackHand::canTakeCard()
    {
        return ((!isBust() && !isFull()) && (getLowScore() != WIN));
    }

bool BlackJackHand::isBlackJack()
    {
        if(getCardCount() == 2)
            {
                return ((hand[0]->getValue() == 'A') &&
                       ((hand[1]->getValue() == 'T') ||
                        (hand[1]->getValue() == 'K') ||
                        (hand[1]->getValue() == 'Q') ||
                        (hand[1]->getValue() == 'J'))
                                    ||
                       ((hand[1]->getValue() == 'A') &&
                       ((hand[0]->getValue() == 'T') ||
                        (hand[0]->getValue() == 'K') ||
                        (hand[0]->getValue() == 'Q') ||
                        (hand[0]->getValue() == 'J'))));
            }
        else
            {
                return false;
            }
    }

//Returns a string listing all the cards in the hand.
string BlackJackHand::getAllCardCodes()
    {
        string handCode = "";

        for(int i = 0; i < getCardCount(); i++)
            {
                handCode += hand[i]->getCardCode() + " ";
            }

        return handCode;
    }
