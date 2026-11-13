#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "Random.h"

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int drawCard()
{
    return Random::get(1, 11);
}

int getValidInput()
{
    while (true)
    {
        std::cout << "What's your choice? (1 = Hit, 2 = Stand, 3 = Surrender): ";
        int choice {};
        std::cin >> choice;

        if (!std::cin)
        {
            if (std::cin.eof()) // If the stream was closed
            {
                std::exit(0); // Shut down the program now
            }
            std::cout << "That's not a valid input\n";
            std::cin.clear();
            ignoreLine();
            continue;
        }

        if (hasUnextractedInput())
        {
            ignoreLine();
            continue;
        }

        return choice;
    }
}

void blackJack()
{
    std::cout << "Welcome to your new gambling addiction... Blackjack!\n"
             "You're going to be given two cards and then a choice of Hit,"
             " Stand or Surrender\n";

    constexpr int maxNum { 21 };
    int playerTotal {drawCard() + drawCard()};
    int dealerTotal {drawCard() + drawCard()};

    std::cout << "You have been given two cards with the total value of " << playerTotal << '\n';

    bool playerContinue { true };
    while (playerContinue)
    {
        switch(int choice {getValidInput()}; choice)
        {
            case 1:
                std::cout << "You chose Hit!\n";
                playerTotal += drawCard();

                if (playerTotal > maxNum)
                {
                    std::cout << "You bust! Your total is " << playerTotal  << ". You lose!\n";
                    return;
                }
                break;
            case 2:
                std::cout << "You chose Stand!\n";
                playerContinue = false;
                break;
            case 3:
                std::cout << "You chose Surrender!\n";
                return;
            default:
                std::cout << "You entered an invalid option! Try again!\n";
                break;
        }

        std::cout << "Your total is " << playerTotal << ".\n";
    }

    std::cout << "Now the dealer's turn, the dealer currently has a total of " << dealerTotal << ".\n";

    bool dealerContinue { true };
    while (dealerContinue)
    {
        if (dealerTotal < 17)
        {
            dealerTotal += drawCard();
            std::cout << "The dealer draws another card and now has a total of " << dealerTotal << ".\n";
        }

        if (dealerTotal >= 17)
        {
            dealerContinue = false;
        }
    }

    if (dealerTotal > maxNum)
    {
        std::cout << "The dealer bust! You win!\n";
    }
    else if (playerTotal == dealerTotal)
    {
        std::cout << "Both you and the dealer have the same value. It's a draw!\n";
    }
    else if (playerTotal > dealerTotal)
    {
        std::cout << "You have more than the dealer, you win!\n";
    }
    else
    {
        std::cout << "You have less than the dealer, you lose!\n";
    }

}

bool playAgain()
{
    while (true)
    {
        std::cout << "Would you like to play again? (y/n): ";
        std::string answer{};
        std::cin >> answer;
        
        if (answer == "y")
        {
            return true;
        } else if (answer == "n")
        {
            return false;
        }
    }
}


int main()
{
    do
    {
        blackJack();
    } while (playAgain());

    std::cout << "Thanks for playing!\n";

    return 0;
}
