//
// Created by Erica on 10/12/2020.
//

#ifndef POKERANALYSIS_POKERSCORE_H
#define POKERANALYSIS_POKERSCORE_H
#include <vector>
#include <iostream>

class PokerScore
{
public:
    enum Scores
    {
        ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT,
        THREE_OF_A_KIND, TWO_PAIR, ONE_PAIR, HIGH_CARD
    };


    void operator+=(const Scores& score);
    void operator+=(const PokerScore& score);
    friend bool operator==(const PokerScore& p, Scores score);
    int size() const;
    Scores& operator[](unsigned int index);
    PokerScore();
    int getRoyalFlushScore() const;
    int getStraightFlushScore() const;
    int getFourOfAKindScore() const;
    //Author: Erica Carballo
    int getFullHouseScore() const;
    int getFlushScore() const;
    int getStraightScore() const;
    int getThreeOfAKindScore() const;
    int getTwoPairScore() const;
    int getOnePairScore() const;
    int getHighCardsScore() const;
    friend std::ostream& operator<<(std::ostream& outs, const PokerScore& score);


private:
    std::vector<Scores> scores;
    int scoreCounter[10];
};


#endif //POKERANALYSIS_POKERSCORE_H
