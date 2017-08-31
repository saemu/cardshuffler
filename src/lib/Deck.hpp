/*
 * Copyright 2016, Samuel Brand
 */

#pragma once

#include "lib/Card.hpp"

#include <vector>

class Card;

class Deck {
public:

    Deck();

    virtual ~Deck() = default;

    void shuffle();

    Card drawNextCard();

    bool hasNext() const;

private:

    std::vector<Card> mCards;

    std::vector<Card>::const_reverse_iterator mCurrent;

};
