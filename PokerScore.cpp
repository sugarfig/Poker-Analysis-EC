//
// Created by Erica on 10/12/2020.
//

#include "PokerScore.h"

void PokerScore::operator+=(const PokerScore::Scores& score)
{
    scores.push_back(score);
}

bool operator==(const PokerScore& p, PokerScore::Scores score)
{
    bool valid = false;
    for(int i = 0; i < p.size(); i++)
    {
        if(p.scores[i] == score)
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

int PokerScore::size() const
{
    return scores.size();
}

PokerScore::Scores& PokerScore::operator[](unsigned int index)
{
    return scores[index];
}

PokerScore::PokerScore()
{

}

int PokerScore::getRoyalFlushScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == ROYAL_FLUSH)
        {
            counter++;
        }
    }
    return counter;
}

int PokerScore::getStraightFlushScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == STRAIGHT_FLUSH)
        {
            counter++;
        }
    }
    return counter;

}

int PokerScore::getFourOfAKindScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == FOUR_OF_A_KIND)
        {
            counter++;
        }
    }
    return counter;

}

int PokerScore::getFullHouseScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == FULL_HOUSE)
        {
            counter++;
        }
    }
    return counter;
}

int PokerScore::getFlushScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == FLUSH)
        {
            counter++;
        }
    }

    return counter;
}
//Author: Erica Carballo
int PokerScore::getStraightScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == STRAIGHT)
        {
            counter++;
        }
    }

    return counter;
}

int PokerScore::getThreeOfAKindScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == THREE_OF_A_KIND)
        {
            counter++;
        }
    }

    return counter;
}

int PokerScore::getTwoPairScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == TWO_PAIR)
        {
            counter++;
        }
    }

    return counter;
}

int PokerScore::getOnePairScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == ONE_PAIR)
        {
            counter++;
        }
    }

    return counter;
}

int PokerScore::getHighCardsScore() const
{
    int counter;
    counter = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == HIGH_CARD)
        {
            counter++;
        }
    }

    return counter;
}

std::ostream& operator<<(std::ostream& outs, const PokerScore& score)
{
   outs << "Royal FLush: " << score.getRoyalFlushScore() << std::endl;
   outs << "Straight Flush: " << score.getStraightFlushScore() << std::endl;
   outs << "Four of a Kind: " << score.getFourOfAKindScore() << std::endl;
   outs << "Full House: " << score.getFullHouseScore() << std::endl;
   outs << "Flush: " << score.getFlushScore() << std::endl;
   outs << "Straight: " << score.getStraightScore() << std::endl;
   outs << "Three of a Kind: " << score.getThreeOfAKindScore() << std::endl;
   outs << "Two Pair: " << score.getTwoPairScore() << std::endl;
   outs << "One Pair: " << score.getOnePairScore() << std::endl;
   outs << "High Card: " << score.getHighCardsScore() << std::endl;

}

void PokerScore::operator+=(const PokerScore& score)
{
    for (int i = 0; i < score.getRoyalFlushScore(); i++)
    {
        scores.push_back(ROYAL_FLUSH);
    }

    for(int i = 0; i < score.getStraightFlushScore(); i++)
    {
        scores.push_back(STRAIGHT_FLUSH);
    }

    for(int i = 0; i < score.getFourOfAKindScore(); i++)
    {
        scores.push_back(FOUR_OF_A_KIND);
    }

    for(int i = 0; i < score.getFullHouseScore(); i++)
    {
        scores.push_back(FULL_HOUSE);
    }

    for(int i = 0; i < score.getFlushScore(); i++)
    {
        scores.push_back(FLUSH);
    }

    for(int i = 0; i < score.getStraightScore(); i++)
    {
        scores.push_back(STRAIGHT);
    }

    for(int i = 0; i < score.getThreeOfAKindScore(); i++)
    {
        scores.push_back(THREE_OF_A_KIND);
    }

    for(int i = 0; i < score.getTwoPairScore(); i++)
    {
        scores.push_back(TWO_PAIR);
    }

    for(int i = 0; i < score.getOnePairScore(); i++)
    {
        scores.push_back(ONE_PAIR);
    }

    for(int i = 0; i < score.getHighCardsScore(); i++)
    {
        scores.push_back(HIGH_CARD);
    }

}
