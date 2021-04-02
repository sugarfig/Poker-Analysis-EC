//
// Created by Erica on 10/12/2020.
//

#include "Card.h"

Card::Card(suits suit, ranks rank) : suit(suit) , value(rank)
{

}

Card::Card() : Card(HEARTS, ACE)
{

}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    Card temp;

    out << temp.getRank(card.value);
    out << " of ";
    out << temp.getSuit(card.suit);

    return out;
}

bool operator==(const Card& card1, const Card& card2)
{
    if ((card1.suit == card2.suit) && (card1.value == card2.value))
    {
        return true;
    }

    return false;
}

bool operator>=(const Card& card1, const Card& card2)
{
    if ((card1.suit >= card2.suit) && (card1.value >= card2.value))
    {
        return true;
    }

    return false;
}

std::string Card::getSuit()
{
    switch(suit)
    {
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        case SPADES:
            return "Spades";
        default:
            exit(7);
    }
}
//Author: Erica Carballo
std::string Card::getSuit(int index)
{
    switch(index)
    {
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        case SPADES:
            return "Spades";
        default:
            exit(8);
    }
}

int Card::getIntSuit() const
{
    switch(suit)
    {
        case HEARTS:
            return 0;
        case DIAMONDS:
            return 1;
        case CLUBS:
            return 2;
        case SPADES:
            return 3;
        default:
            exit(9);

    }
}

std::string Card::getRank()
{
    switch (value)
    {
        case ACE:
            return "Ace";
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default:
            exit(10);
    }
}

std::string Card::getRank(int index)
{
    switch (index)
    {
        case ACE:
            return "Ace";
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default:
            exit(11);
    }
}

int Card::getIntRank()
{
    switch (value)
    {
        case ACE:
            return 0;
        case TWO:
            return 1;
        case THREE:
            return 2;
        case FOUR:
            return 3;
        case FIVE:
            return 4;
        case SIX:
            return 5;
        case SEVEN:
            return 6;
        case EIGHT:
            return 7;
        case NINE:
            return 8;
        case TEN:
            return 9;
        case JACK:
            return 10;
        case QUEEN:
            return 11;
        case KING:
            return 12;
        default:
            exit(12);
    }
}

void Card::setSuit(suits suit)
{
    this-> suit = suit;
}

void Card::setRank(ranks value)
{
    this-> value = value;
}

void Card::setSuit(int suitNumber)
{
    suit = suitNumber;
}

void Card::setRank(int rankNumber)
{
    value = rankNumber;
}