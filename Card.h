//
// Created by Erica on 10/12/2020.
//

#ifndef POKERANALYSIS_CARD_H
#define POKERANALYSIS_CARD_H
#include <iostream>

class Card
{
public:
    enum suits
    {
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    };
    enum ranks
    {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK,
        QUEEN, KING, ACE
    };

    Card(suits suit, ranks rank);
    Card();
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    friend bool operator==(const Card& card1, const Card& card2);
    friend bool operator>=(const Card& card1, const Card& card2);
    std::string getSuit();
    std::string getSuit(int index);
    int getIntSuit() const;
    std::string getRank();
    //Author: Erica Carballo
    std::string getRank(int index);
    int getIntRank();
    void setSuit(suits suit);
    void setRank(ranks value);
    void setSuit(int suitNumber);
    void setRank(int rankNumber);


private:
    int suit;
    int value;



};


#endif //POKERANALYSIS_CARD_H
