//
// Created by Erica on 10/12/2020.
//

#include "Deck.h"
#include "time.h"

Card& Deck::dealCard()
{
    cardIndex++;
    return deck[cardIndex - 1];
}

Card Deck::getCardAt(int index)
{
    /*Card temp;

    temp.setSuit(deck[index - 1].getIntSuit());
    temp.setRank(deck[index - 1].getIntRank());

    return temp;*/


    return deck[index - 1]; // BETTER WAY OF DOING IT !!!
}

Deck::Deck()
{
    int index;
    index = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[index].setSuit(i);
            deck[index].setRank(j);
            index++;
        }

    }
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    for (int i = 0; i < 52; i++)
    {
        out << i + 1 << ": ";
        out << deck.deck[i];
        out << std::endl;
    }
}
//Author: Erica Carballo
void Deck::shuffle()
{
    Card temp[DECK_SIZE], nullCard;
    int index, i;
    srand(time(NULL));
    index = rand() % DECK_SIZE;
    i = 0;
    nullCard.setRank(14);
    nullCard.setSuit(5);

    while (i < 52)
    {
        if (deck[index] == nullCard)
        {
            index = rand() % 52;
        }
        else
        {
            temp[i] = deck[index];
            deck[index] = nullCard;
            index = rand() % DECK_SIZE;
            i++;
        }

    }

    for (int j = 0; j < DECK_SIZE; j++)
    {
        deck[j] = temp[j];
    }
    cardIndex = 0;
}

bool Deck::empty()
{
    Card nullCard;
    bool valid = false;
    nullCard.setSuit(5);
    nullCard.setRank(14);

    for (int i = 0; i < DECK_SIZE; i++)
    {
        if(deck[i] >= nullCard)
        {
            valid = true;
            exit(1);
        }
        else
        {
            valid = false;

        }
    }

    return valid;
}