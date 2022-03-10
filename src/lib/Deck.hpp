/*
 * Copyright 2016, Samuel Brand
 */

#pragma once

#include "Card.hpp"

#include <vector>

class Deck {
public:
    Deck();
    void shuffle();
    Card drawNextCard();
    bool hasNext() const;

private:
    std::vector<Card> mCards{
        Card(Card::Suit::eSpades, Card::Rank::eAce),     Card(Card::Suit::eSpades, Card::Rank::eKing),    Card(Card::Suit::eSpades, Card::Rank::eQueen),
        Card(Card::Suit::eSpades, Card::Rank::eJack),    Card(Card::Suit::eSpades, Card::Rank::eTen),     Card(Card::Suit::eSpades, Card::Rank::eNine),
        Card(Card::Suit::eSpades, Card::Rank::eEight),   Card(Card::Suit::eSpades, Card::Rank::eSeven),   Card(Card::Suit::eSpades, Card::Rank::eSix),
        Card(Card::Suit::eHearts, Card::Rank::eAce),     Card(Card::Suit::eHearts, Card::Rank::eKing),    Card(Card::Suit::eHearts, Card::Rank::eQueen),
        Card(Card::Suit::eHearts, Card::Rank::eJack),    Card(Card::Suit::eHearts, Card::Rank::eTen),     Card(Card::Suit::eHearts, Card::Rank::eNine),
        Card(Card::Suit::eHearts, Card::Rank::eEight),   Card(Card::Suit::eHearts, Card::Rank::eSeven),   Card(Card::Suit::eHearts, Card::Rank::eSix),
        Card(Card::Suit::eDiamonds, Card::Rank::eAce),   Card(Card::Suit::eDiamonds, Card::Rank::eKing),  Card(Card::Suit::eDiamonds, Card::Rank::eQueen),
        Card(Card::Suit::eDiamonds, Card::Rank::eJack),  Card(Card::Suit::eDiamonds, Card::Rank::eTen),   Card(Card::Suit::eDiamonds, Card::Rank::eNine),
        Card(Card::Suit::eDiamonds, Card::Rank::eEight), Card(Card::Suit::eDiamonds, Card::Rank::eSeven), Card(Card::Suit::eDiamonds, Card::Rank::eSix),
        Card(Card::Suit::eClubs, Card::Rank::eAce),      Card(Card::Suit::eClubs, Card::Rank::eKing),     Card(Card::Suit::eClubs, Card::Rank::eQueen),
        Card(Card::Suit::eClubs, Card::Rank::eJack),     Card(Card::Suit::eClubs, Card::Rank::eTen),      Card(Card::Suit::eClubs, Card::Rank::eNine),
        Card(Card::Suit::eClubs, Card::Rank::eEight),    Card(Card::Suit::eClubs, Card::Rank::eSeven),    Card(Card::Suit::eClubs, Card::Rank::eSix)};
    std::vector<Card>::const_reverse_iterator mCurrent;
};
