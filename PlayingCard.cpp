#include "PlayingCard.h"
using namespace std;

PlayingCard::PlayingCard()
    {
        value = '0';
        suit = '0';
    }

PlayingCard::PlayingCard(char myValue, char mySuit)
    {
        value = myValue;
        suit = mySuit;

        if(!isValid())
            {
                value = '0';
                suit = '0';
            }
    }

bool PlayingCard::setCard(char myValue, char mySuit)
    {
        value = myValue;
        suit = mySuit;

        if(isValid())
            {
                return true;
            }
        else
            {
                value = '0';
                suit = '0';
                return false;
            }

    }

char PlayingCard::getValue()
    {
        return value;
    }

char PlayingCard::getSuit()
    {
        return suit;
    }

string PlayingCard::getCardCode()
    {
        string cardCode = "";

        cardCode += value;

        cardCode += suit;

        return cardCode;
    }

bool PlayingCard::isValid()
    {
        return (((value >= 50) && (value <= 57)) || (value == 'T') || (value == 'A') || (value == 'J') || (value == 'Q') || (value == 'K'))
                        && ((suit == 'C') || (suit == 'H') || (suit == 'S') || (suit == 'D'));
    }
