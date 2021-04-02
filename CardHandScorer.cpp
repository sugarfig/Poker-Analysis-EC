//
// Created by Erica on 10/12/2020.
//

#include "CardHandScorer.h"


PokerScore CardHandScorer::scorePokerHand(CardHand& theCardHand)
{
    PokerScore theScore;

    if(checkRoyalFlush(theCardHand))
    {
        theScore += PokerScore::ROYAL_FLUSH;
        theScore += PokerScore::STRAIGHT;
        theScore += PokerScore::FLUSH;
        theScore += PokerScore::STRAIGHT_FLUSH;
    }

    if(checkStraightFlush(theCardHand))
    {
        theScore += PokerScore::STRAIGHT_FLUSH;
        theScore += PokerScore::FLUSH;
        theScore += PokerScore::STRAIGHT;
    }

    if(checkFourOfAKind(theCardHand))
    {
        theScore += PokerScore::FOUR_OF_A_KIND;
        theScore += PokerScore::THREE_OF_A_KIND;
        theScore += PokerScore::TWO_PAIR;
        theScore += PokerScore::ONE_PAIR;
    }

    if(checkFullHouse(theCardHand))
    {
        theScore += PokerScore::FULL_HOUSE;
        theScore += PokerScore::THREE_OF_A_KIND;
        theScore += PokerScore::TWO_PAIR;
        theScore += PokerScore::ONE_PAIR;
    }

    if(checkFlush(theCardHand))
    {
        theScore += PokerScore::FLUSH;
    }

    if(checkStraight(theCardHand))
    {
        theScore += PokerScore::STRAIGHT;
    }

    if(checkThreeOfAKind(theCardHand))
    {
        theScore += PokerScore::THREE_OF_A_KIND;
        theScore += PokerScore::ONE_PAIR;
    }

    if(checkTwoPair(theCardHand))
    {
        theScore += PokerScore::TWO_PAIR;
        theScore += PokerScore::ONE_PAIR;
    }

    if(checkOnePair(theCardHand))
    {
        theScore += PokerScore::ONE_PAIR;
    }

    if(checkHighCard(theCardHand))
    {
        theScore += PokerScore::HIGH_CARD;
    }

    return theScore;
}

bool CardHandScorer::checkRoyalFlush(const CardHand& theCardHand)//DONE I BELIEVE1
{
    bool valid = false;
    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();

    if(checkFlush(theCardHand))
    {
        int rank = Card::TEN;
      for (int i = 0; i < 5; i++)
      {
        if(temp.getRankOfCard(i) == rank)
          {
              valid = true;
          }
          else
          {
              return false;
          }
          rank++;
      }
    }

    return valid;
}

bool CardHandScorer::checkStraightFlush(const CardHand& theCardHand) //DONE I BELIEVE1
{
    CardHand temp;
    temp = theCardHand;
    temp.sort();

    if (checkFlush(temp) && checkStraight(temp))
    {
        return true;
    }

    return false;
}

bool CardHandScorer::checkFourOfAKind(const CardHand& theCardHand)//DONE I BELIEVE1
{

    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();

    if(getDuplicates(temp) == 4)
    {
        return true;
    }

    return false;

}

bool CardHandScorer::checkFullHouse(const CardHand& theCardHand) //DONE I BELIEVE1
{
    CardHand temp;
    temp = theCardHand;
    temp.sort();


    if(getDuplicates(temp) == 5)
    {
        return true;
    }


    return false;
}

bool CardHandScorer::checkFlush(const CardHand& theCardHand)
{
    int temp;
    bool valid;
    temp = theCardHand.getSuitOfCard(0);
    valid = false;

    for(int i = 1; i < 5; i++)
    {
        if(theCardHand.getSuitOfCard(i) == temp)
        {
            valid = true;
        }
        else
        {
            return false;
        }
    }

    return valid;
}
//Author: Erica Carballo
bool CardHandScorer::checkStraight(const CardHand& theCardHand)
{
    bool valid = false;
    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();

    int rank = temp.getRankOfCard(0);

    for(int i = 0; i < 5; i++)
    {
        if(temp.getRankOfCard(i) == rank)
        {
            valid = true;
        }
        else
        {
            return false;
        }

        rank++;
    }

    return valid;
}

bool CardHandScorer::checkThreeOfAKind(const CardHand& theCardHand)
{
    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();

    if(getDuplicates(temp) == 3)
    {
        return true;
    }

    return false;

}

bool CardHandScorer::checkTwoPair(const CardHand& theCardHand)
{
    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();;

    if(getDuplicates(temp) == 2)
    {
        return true;
    }

    return false;
}

bool CardHandScorer::checkOnePair(const CardHand& theCardHand)
{
    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();

    if(getDuplicates(temp) == 1)
    {
        return true;
    }

    return false;
}

bool CardHandScorer::checkHighCard(const CardHand& theCardHand)
{
    return true; //THERE WILL ALWAYS BE A HIGHEST CARD IN THE PLAYER'S HAND.
}

int CardHandScorer::getDuplicates(const CardHand& theCardHand)
{

    CardHand temp;
    temp = theCardHand;
    temp.sortByRank();


    int countEachRank[13];
    bool isTriple, isPair, isDoublePair;
    isTriple = false;
    isPair = false;
    isDoublePair = false;

    for(int i = 0; i < 13; i++)
    {
        countEachRank[i] = 0;
    }

    for(int i = 0; i < 5; i++)
    {
        countEachRank[temp.getRankOfCard(i)]++;
    }

    for(int i = 0; i < 13; i++)
    {
        if(countEachRank[i] == 4)
        {
            //FOUR OF A KIND
            return 4;
        }

        if(countEachRank[i] == 3)
        {
            isTriple = true;
        }

        if(countEachRank[i] == 2)
        {
            for(int j = i; j < 13; j++)
            {
                if(countEachRank[j] == 2)
                {
                    isDoublePair = true;
                }
            }
            isPair = true;
        }
    }


    if(isTriple)
    {
        if(isPair)
        {
            return 5;
        }
        return 3;
    }

    if(isDoublePair)
    {
        return 2;
    }

    if(isPair)
    {
        return 1;
    }

}
