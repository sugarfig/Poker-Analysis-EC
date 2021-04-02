//Author: Erica Carballo
//Project name: Poker Analysis
//Description: Program that creates a card deck and analyzes the cards given to a hand.
//Last Changed: October 18, 2020

#include <iostream>
#include "Deck.h"
//#include "Card.h"
#include "CardHand.h"
#include "CardHandScorer.h"

int main()
{
    //Card a(Card::suits::DIAMONDS, Card::ranks::FOUR);
    Deck d;
    CardHand ch, ch1, ch2, ch3, ch4;

    std::cout << "This is the deck of cards: " << std::endl;
    std::cout << d << std::endl;

    d.shuffle();

    std::cout << "This is after shuffled:" << std::endl;
    std::cout << d << std::endl;

    std::cout << "Check if the deck is empty:" << std::endl;
    std::cout << d.empty() << std::endl << std::endl;

    std::cout << "Get the card at position 12:" << std::endl;
    std::cout << d.getCardAt(12) << std::endl << std::endl;

    std::cout << "Dealing cards:" << std::endl;
    std::cout << d.dealCard() << std::endl;
    std::cout << d.dealCard() << std::endl;
    std::cout << d.dealCard() << std::endl;

    std::cout << std::endl;

    std::cout << "Adding card to a hand:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        ch.addCardtoHand(d.dealCard());
    }


    std::cout << ch << std::endl;

    std::cout << "This is a card at a certain index 2:" << std::endl;
    std::cout << ch.getCardHandAt(2) << std::endl << std::endl;

    std::cout << "This is sorting the card hand: " << std::endl;
    ch.sort();
    std::cout << ch << std::endl << std::endl;

    std::cout << "Testing Poker Score: " << std::endl;
    PokerScore pokerScore = CardHandScorer::scorePokerHand(ch);

    pokerScore += PokerScore::FULL_HOUSE;
    pokerScore += PokerScore::STRAIGHT_FLUSH;
    pokerScore += PokerScore:: FOUR_OF_A_KIND;
    pokerScore += PokerScore:: FULL_HOUSE;
    pokerScore += PokerScore::FLUSH;
    pokerScore += PokerScore::STRAIGHT;
    pokerScore += PokerScore:: THREE_OF_A_KIND;
    pokerScore += PokerScore:: TWO_PAIR;
    pokerScore += PokerScore:: ONE_PAIR;
    pokerScore += PokerScore::HIGH_CARD;
    pokerScore += PokerScore::FLUSH;
    pokerScore += PokerScore::ROYAL_FLUSH;

    std::cout << pokerScore << std::endl << std::endl;

    std::cout << "Analyzing the Poker Hands: " << std::endl;
    PokerScore ps;
    for(int i = 0; i < 1000; i++)
    {

        CardHand ch, ch1, ch2, ch3, ch4;
        d.shuffle();
        for (int j = 0; j < 5; j++)
        {

            ch.addCardtoHand(d.dealCard());
            ch1.addCardtoHand(d.dealCard());
            ch2.addCardtoHand(d.dealCard());
            ch3.addCardtoHand(d.dealCard());
            ch4.addCardtoHand(d.dealCard());
        }

        ch.sort();

        ps += CardHandScorer::scorePokerHand(ch);
    }
    std::cout << ps;



    return 0;
}
