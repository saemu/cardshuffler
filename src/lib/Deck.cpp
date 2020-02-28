/*
 * Copyright 2016, Samuel Brand
 */

#include "Deck.hpp"

#include "Card.hpp"

#include <algorithm>
#include <random>

Deck::Deck() : mCurrent(mCards.rbegin()) {}

void Deck::shuffle() {
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::shuffle(std::begin(mCards), std::end(mCards), randomEngine);
    mCurrent = mCards.rbegin();
}

Card Deck::drawNextCard() {
    Card card(*mCurrent);
    ++mCurrent;
    return card;
}

bool Deck::hasNext() const {
    return mCurrent != mCards.rend();
}
