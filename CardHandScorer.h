//
// Created by Erica on 10/12/2020.
//

#ifndef POKERANALYSIS_CARDHANDSCORER_H
#define POKERANALYSIS_CARDHANDSCORER_H
#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer
{
public:
    static PokerScore scorePokerHand(CardHand& theCardHand);

private:
    static bool checkRoyalFlush(const CardHand& theCardHand);
    static bool checkStraightFlush(const CardHand& theCardHand);
    static bool checkFourOfAKind(const CardHand& theCardHand);
    static bool checkFullHouse(const CardHand& theCardHand);
    //Author: Erica Carballo
    static bool checkFlush(const CardHand& theCardHand);
    static bool checkStraight(const CardHand& theCardHand);
    static bool checkThreeOfAKind(const CardHand& theCardHand);
    static bool checkTwoPair(const CardHand& theCardHand);
    static bool checkOnePair(const CardHand& theCardHand);
    static bool checkHighCard(const CardHand& theCardHand);
    static int getDuplicates(const CardHand& theCardHand);

};


#endif //POKERANALYSIS_CARDHANDSCORER_H
