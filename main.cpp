#include <iostream>
#include "BlackJack.h"
#include <iomanip>

using namespace std;

int main()
    {
        //Required variabels for user input.
        string playerName = "";

        int bet = 0;

        char choice = 'x';
        char gameChoice = 'x';

        cout << "Welcome to the Black Jack Game!\n";
        cout << "-------------------------------";

        cout << "\nFor a complete list of the rules enter (R/r), enter (P/p) to play,\n";
        cout << "or enter (Q/q) to quit.\n";

        cin >> choice;

        //Input validations
        while((choice != 'R') && (choice != 'r') && (choice != 'P') &&
           (choice != 'p') && (choice != 'Q') && (choice != 'q'))
            {
                cout << "Invalid input.\n";
                cin >> choice;
            }
        //Display the rules if R/r is chosen.
        if((choice == 'R') || (choice == 'r'))
            {
                cout << "\nA user bets before the cards are dealt.\n\n";

                cout << "Two cards are dealt to the player, face up.\n\n";

                cout << "Two cards are dealt to the dealer, one face up, one face down.\n\n";

                cout << "The player may draw cards until:\n";

                cout << "1.The player no longer wants more cards.\n";

                cout << "2.The player's low score is greater than or equal to 21.\n\n";

                cout << "If the player busts, the house wins and the player loses the bet.\n\n";   cout << "\n";

                cout << "When the player is done, and not bust, the dealer reveals the face down card.\n";

                cout << "The dealer then takes cards as long as their score is not greater than 17.\n";

                cout << "If the dealer's high score would yield a non-bust score above 17, \n";
                cout << "the dealer stays.\n";

                cout << "If the dealer's high score would be bust, but their low score would be 17\n";
                cout << " or less, the dealer would take another card.\n";

                cout << "The deck will be reset after the hand in which the deck falls below 10 cards.\n\n";

                cout << "The game ends when the player decides to quit or runs out of money.\n\n";

                cout << "A player may not bet more money than she possesses.\n";

                cout << "\n\nEnter (P/p) to Play, or (Q/q) to Quit.\n";

                cin >> choice;

                while((choice != 'P') && (choice != 'p') && (choice != 'Q') && (choice != 'q'))
                    {
                        cout << "Invalid input.\n";
                        cin >> choice;
                    }
            }
        //Begin the game is P/p is chosen
        if((choice == 'P') || (choice == 'p'))
            {
                cout << "\n\nPlease enter your first name:";

                cin >> playerName;

                BlackJack* game = new BlackJack(playerName);


                cout << "Welcome " << playerName << "!\n";

                //Begin do loop for continued play.
                do
                {
                    game->newHand();

                    //Display chipStack and ask user for bet.
                    cout << "\n\nYou have $" << game->getChipStack() << " in chips.\n";
                    cout << "How much would you like to wager?\n";

                    cin >> bet;

                    //Input validation
                    while((bet <= 0 ) || (bet > game->getChipStack()))
                        {
                            cout << "Invalid input. Please enter a wager greater than zero,\n";
                            cout << "and less than your total chip stack.\n";

                            cin >> bet;
                        }

                    game->makeBet(bet);

                    game->showHoleHand();

                    //If player has Blackjack skip asking the player to hit or stay.
                    if(game->getPlayerBlackJack())
                        {
                            cout << "BLACKJACK!!\n";
                            system("Pause"); //To slow down the action
                            gameChoice = 's';
                        }
                    else //If player doesn't have Blackjack as if player wants to hit or stay.
                        {
                                do //Begin loop for player to continue to take cards.
                                     {
                                        cout << "Would you like to hit (H/h), or stay (S/s)? : ";

                                        cin >> gameChoice;

                                        //Input validation.
                                        while((gameChoice != 'H') && (gameChoice != 'h') && (gameChoice != 'S') && (gameChoice != 's'))
                                            {
                                                cout << "Ivalid input, please enter the first letter of either hit or stay.\n";

                                                cin >> gameChoice;
                                            }
                                        //If player chooses H/h allow player to take a card.
                                        if((gameChoice == 'H') || (gameChoice == 'h'))
                                            {
                                                game->playerHit();
                                                game->showHoleHand();

                                            }

                                        //After taking a card determine if the player's hand has busted
                                        //if so gameChoice is set to 's' to drop out of do loop.
                                        if(game->getIsPlayerBust())
                                            {
                                                cout << "\n--->BUST!!<---\n";
                                                gameChoice = 's';
                                                system("Pause"); //To slow down the action
                                            }

                                        //Continue the loop as long as the hand isn't busted and the player hasn't chosen to stay.
                                     }while(((gameChoice == 'H') || (gameChoice == 'h')) &&
                                            (game->canPlayerHit()));
                        }

                    //After player has chosen to say, the dealer shows the hole card.
                    cout << "\n\nDealer shows their hole card.\n";

                    game->showBothHand();

                    system("Pause"); //To slow down the action

                    //If the player hasn't busted and the dealer doesn't have Blackjack
                    //the dealer can possibly take cards
                    if(!game->getIsPlayerBust() && !game->getPlayerBlackJack())
                        {
                            //if the dealer's score is <17, has <5 cards then the dealer takes a card.
                            while(game->canDealerHit())
                                {
                                    cout << "\n\nDealer takes a card.";

                                    game->dealerHit();

                                    game->showBothHand();

                                    system("Pause"); //To slow the action down.
                                }
                        }

                    //Determine the outcome of the game.
                    game->outcomes();

                    //After the outcome is determined, the hands are cleared.
                    game->clearHands();

                    //If the player is out of chips, the game shuts down automatically.
                    if(game->getChipStack() <= 0)
                        {
                            cout << "You've run out of money! The game will now end.\n";
                            choice = 'q';
                        }
                    //If the player has chips ask if the player wants to continue playing.
                    else
                        {
                            cout << "Enter (Y/y) to continue playing, or (Q/q) to quit.\n";

                            cin >> choice;

                            while((choice != 'Y') && (choice != 'y') && (choice =! 'Q') && (choice != 'q'))
                                {
                                    cout << "Invalid input. (Y/y) to continue, or (Q/q) to quit.\n";
                                    cin >> choice;
                                }
                        }
                }while((choice == 'Y') || (choice == 'y'));

                //After the game is over delete the DMA game object.
                delete game;
            }


        return 0;
    }
