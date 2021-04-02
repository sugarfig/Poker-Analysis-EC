//
// Created by Erica on 10/12/2020.
//

#include "CardHand.h"

void CardHand::addCardtoHand(Card& newCard)
{
    cardsInHand.push_back(newCard);
}

CardHand::CardHand()
{

}

std::ostream& operator<<(std::ostream& out, CardHand& theHand)
{
    for(int i = 0; i < 5; i++)
    {
        out << theHand.cardsInHand[i] << std::endl;
    }

    return out;
}

Card CardHand::getCardHandAt(int index) const
{
    return cardsInHand[index - 1];
}

void CardHand::sort()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4 - i; j++)
        {
            if(cardsInHand[j].getIntRank() > cardsInHand[j + 1].getIntRank())
            {
                Card temp;

                temp = cardsInHand[j];
                cardsInHand[j] = cardsInHand[j + 1];
                cardsInHand[j + 1] = temp;
            }

            if(cardsInHand[j].getIntSuit() > cardsInHand[j + 1].getIntSuit())
            {
                Card temp;

                temp = cardsInHand[j];
                cardsInHand[j] = cardsInHand[j + 1];
                cardsInHand[j + 1] = temp;
            }
        }
    }

}
//Author: Erica Carballo
void CardHand::sortByRank()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4 - i; j++)
        {
            if(cardsInHand[j].getIntRank() > cardsInHand[j + 1].getIntRank())
            {
                Card temp;

                temp = cardsInHand[j];
                cardsInHand[j] = cardsInHand[j + 1];
                cardsInHand[j + 1] = temp;
            }
        }
    }
}

int CardHand::getRankOfCard(int index)
{
    return cardsInHand[index].getIntRank();
}

int CardHand::getSuitOfCard(int index) const
{
    return cardsInHand[index].getIntSuit();
}