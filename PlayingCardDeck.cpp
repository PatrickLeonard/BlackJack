#include "PlayingCardDeck.h"
using namespace std;

PlayingCardDeck::PlayingCardDeck()
    {
        //seed random number generator with the time
        srand(time(0));

        deckCreation();
    }

PlayingCardDeck::PlayingCardDeck(int numShuffles)
    {
       srand(time(0));

       deckCreation();

       shuffle(numShuffles);
    }

PlayingCardDeck::~PlayingCardDeck()
    {
        //Delete all the playingcard objects
        for(int i = 0; i < SIZE; i++)
            {
                delete deck[i];
            }
    }

void PlayingCardDeck::deckCreation()
    {
        //char arrays for the suits and values of card objects
        char suits[] = {'D','C', 'H', 'S'};

        char values[] = {'A', '2', '3', '4',
                        '5', '6', '7', '8',
                        '9', 'T', 'J', 'Q',
                        'K'};

        //accumulator for DMA pointer to object array sub
        int i = 0;

        //create DMA PlayingCard objects with the proper suits and values
        for(int s = 0; s < (sizeof(suits)/sizeof(char)); s++)
            for(int v = 0; v < (sizeof(values)/sizeof(char)); v++)
                {
                    deck[i] = new PlayingCard(values[v], suits[s]);
                    i++;
                }
    }

PlayingCard* PlayingCardDeck::dealCard()
    {
        //temp pointer to hold the pointer being dealt
        PlayingCard* temp;

        //Assigns the sub number of pointer on top of deck
        int cardCount = 0;

        //Accounts for off by 1
        if(getCountUsed() == SIZE)
            {
                cardCount = (SIZE - 1);
            }
        else
            {
                cardCount = getCountUsed();
            }

        //If pointer to the card object exists
        if(deck[cardCount] != NULL)
            {
                //Assign the pointer to temp
                //Assign NULL to the pointer
                //and return temp
                temp = deck[cardCount];
                deck[cardCount] = NULL;
                return temp;
            }
        else
            {
                //Display warning if there are no cards left
                cout << "\n-Warning! No cards left in deck-\n";
                return NULL;
            }
    }

bool PlayingCardDeck::shuffle(int numShuffles)
    {
        //temp pointer to hold the pointer being swapped
        PlayingCard* temp;

        //Initialize and assign variable to hold randum number
        int randNum = 0;

        //Minimum amount to get a good random shuffle
        const int MIN_SHUFFLE = 200;

        //Ensures that no cards have been used before shuffling
        if(getCountUsed() == 0)
            {
                for(int i = 0; i < numShuffles * MIN_SHUFFLE; i++)
                    {
                        //Random bubble sort to shuffle
                        randNum = rand() % (SIZE - 1);
                        temp = deck[randNum];
                        deck[randNum] = deck[randNum + 1];
                        deck[randNum + 1] = temp;
                    }
                return true;
            }
        else
            {
                //Display an error if cards have been dealt and do not shuffle
                cout << "\n-Shuffle ERROR. Cannot not shuffle deck!.-\n";
                return false;
            }
    }

void PlayingCardDeck::reset()
    {
        //Delete all of the DMA playing card objects
        for(int i = 0; i < SIZE; i++)
            {
                delete deck[i];
            }

        deckCreation();
    }


//Creates and return a string of all cards codes left in the deck
string PlayingCardDeck::getAllCardCodes()
    {
        string allCardCodes = "";

        const int SUITS = 4, //Four suits
                  VALUES = 13; //Thirteen values for each suit

        int card = 0;

        for(int s = 0; s < SUITS; s++)
            {
                for(int v = 0; v < VALUES; v++)
                    {
                        if(deck[card] != NULL)
                            {
                                allCardCodes += deck[card]->getCardCode();
                                allCardCodes += "  ";
                                card++;
                            }
                        else
                            {
                                card++;
                            }
                    }
                allCardCodes += "\n";
            }

        return allCardCodes;

    }


//Search the deck array and count how many cards are NULL
int PlayingCardDeck::getCountUsed()
    {
        int cardsUsed = 0;

        for(int i = 0; i < SIZE; i++)
            {
                if(deck[i] == NULL)
                    {
                        cardsUsed++;
                    }
            }

        return cardsUsed;
    }


//Search the deck array and count how many cards are NOT NULL
int PlayingCardDeck::getCountRemain()
    {

        return SIZE - getCountUsed();
    }
