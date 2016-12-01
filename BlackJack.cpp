#include "BlackJack.h"
#include <iomanip>

//Creates new dealer and player objects.
BlackJack::BlackJack()
{
    dealer = new BlackJackDealer;
    player = new BlackJackPlayer;
}

//Creates new dealer and player objects using the overloaded
//constructor for the player with a string parameter.
BlackJack::BlackJack(std::string n)
{
    dealer = new BlackJackDealer;
    player = new BlackJackPlayer(n, dealer->dealCard(), dealer->dealCard());
}

//Deletes the objects created with new operator.
BlackJack::~BlackJack()
{
    delete dealer;
    delete player;
}

//Checks if the deck needs to be reset and deals
//cards as needed.
void BlackJack::newHand()
{
    dealer->resetCheck();

    if(dealer->hand->getCardCount() == 0)
        {
            dealer->hit(dealer->dealCard());
            dealer->hit(dealer->dealCard());
            player->hit(dealer->dealCard());
            player->hit(dealer->dealCard());
        }

}

//Returns player object's chipstack.
int BlackJack::getChipStack()
{
    return player->getChipStack();
}

//Sets player object's wager variable.
void BlackJack::makeBet(int bet)
{
    player->setWager(bet);
}

//Displays both hands without out showing dealer's hole card.
void BlackJack::showHoleHand()
{
    cout << "\n\n---->DEALER<----\n";
    cout << "Hand: " << setw(15) << left << dealer->holeCardHand() << "\n\n";

    cout << "\n\n---->PLAYER<----\n";
    cout << "Hand: " << setw(15) << left << player->showHand() << "\n\n";
}

//Displays both hands in their entirety.
void BlackJack::showBothHand()
{
    cout << "\n\n---->DEALER<----\n";
    cout << "Hand: " << setw(15) << left << dealer->showHand() << "\n\n";

    cout << "\n\n---->PLAYER<----\n";
    cout << "Hand: " << setw(15) << left << player->showHand() << "\n\n";
}

//Returns the bool for if player has blackjack.
bool BlackJack::getPlayerBlackJack()
{
    return player->hand->isBlackJack();
}

//Returns the bool for if dealer has blackjack.
bool BlackJack::getDealerBlackJack()
{
    return dealer->hand->isBlackJack();
}

//Adds a card to the player's hand.
void BlackJack::playerHit()
{
    player->hit(dealer->dealCard());
}

//Adds a card to the dealer's hand.
void BlackJack::dealerHit()
{
    dealer->hit(dealer->dealCard());
}

//Returns a bool for if the player's hand is bust.
bool BlackJack::getIsPlayerBust()
{
    return player->hand->isBust();
}

//Returns a bool for if the dealer can take a card.
bool BlackJack::canDealerHit()
{
    return (dealer->hand->canTakeCard())&& (dealer->canTakeHit());
}

//Returns a bool for if the player can take a card.
bool BlackJack::canPlayerHit()
{
    return player->hand->canTakeCard();
}

//Displays and impliments the proper outcome of the game.
void BlackJack::outcomes()
{
     //if player doesn't have Blackjack and dealer does, the player loses.
    if(!(player->hand->isBlackJack()) && (dealer->hand->isBlackJack()))
    {
        cout << "Dealer's hand is BLACKJACK!\n";
        cout << "You lose. $" << player->getWager() << " has been subtracted from your chip stack.\n";
        player->handOutcome("lose");
        cout << "Your current chip stack is: " << player->getChipStack() << ".\n";
    }
    //If the player has Blackjack and the dealer does not the outcome is "blackjack".
    else if((player->hand->isBlackJack()) && !(dealer->hand->isBlackJack()))
        {
            cout << "BLACKJACK!. You win triple your bet of " << player->getWager() << ".\n";
            player->handOutcome("blackjack");
            cout << "Your current chip stack is: $" << player->getChipStack() << ".\n";
        }
    //if both the player and dealer have blackjack, it's a push.
    else if((player->hand->isBlackJack()) && (dealer->hand->isBlackJack()))
        {
            cout << "\n\nThe game is a 'push.'\n\n";
            cout << "Your current chip stack is: $" << player->getChipStack() << ".\n";
        }
    //If the dealer's hand is > the player's hand, and neither are bust, the player loses.
    else if((dealer->stay() > player->stay()) && !(player->hand->isBust()) && !(dealer->hand->isBust()))
        {
            cout << "Dealer's hand is winner!\n";
            cout << "You lose. $" << player->getWager() << " has been subtracted from your chip stack.\n";
            player->handOutcome("lose");
            cout << "Your current chip stack is: $" << player->getChipStack() << ".\n";
        }
    //If the player's hand is greater than the dealer's and neither are busted the player wins.
    else if((dealer->stay() < player->stay()) && !(player->hand->isBust()) && !(dealer->hand->isBust())
            && !(player->hand->isBlackJack()))
        {
            cout << "Player's hand is winner!\n";
            cout << "You win! $" << player->getWager() << " has been added to your chip stack.\n";
            player->handOutcome("win");
            cout << "Your current chip stack is: $" << player->getChipStack() << ".\n";
        }
    //If the dealer's hand busted then the player wins.
    else if(!(player->hand->isBust()) && (dealer->hand->isBust()))
        {
            cout << "Dealer's hand BUSTED!\n";
            cout << "You win! $" << player->getWager() << " has been added to your chip stack.\n";
            player->handOutcome("win");
            cout << "Your current chip stack is: $" << player->getChipStack() << ".\n";
        }
    //If the player's hand is busted, the player loses.
    else if(player->hand->isBust())
        {
            cout << "Player's hand BUSTED!\n";
            cout << "You lose. $" << player->getWager() << " has been subtracted from your chip stack.\n";
            player->handOutcome("lose");
            cout << "Your current chip stack is: " << player->getChipStack() << ".\n";
        }
    //If the player and dealer's score are equal the game is a push.
    else if(dealer->stay() == player->stay())
        {
            cout << "\n\nThe game is a 'push.'\n\n";
            cout << "Your current chip stack is: $" << player->getChipStack() << ".\n";
        }
}

//Clears the blackjackhands of cards.
void BlackJack::clearHands()
{
    dealer->hand->clearHand();
    player->hand->clearHand();
}
