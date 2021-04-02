//
// Created by Erica on 10/12/2020.
//

#ifndef POKERANALYSIS_CARDHAND_H
#define POKERANALYSIS_CARDHAND_H
#include "Card.h"
#include <vector>

class CardHand
{
public:
    void addCardtoHand(Card& newCard);
    CardHand();
    friend std::ostream& operator<<(std::ostream& out, CardHand& theHand);
    Card getCardHandAt(int index) const;
    //Author: Erica Carballo
    void sort();
    int getRankOfCard(int index);
    int getSuitOfCard(int index) const;
    void sortByRank();
private:
    std::vector<Card> cardsInHand;
};


#endif //POKERANALYSIS_CARDHAND_H
