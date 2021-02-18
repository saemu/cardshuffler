/*
 * Copyright 2016, Samuel Brand
 */

#include "Deck.hpp"

#include "Card.hpp"

#include <algorithm>
#include <random>

namespace {
#ifndef NDEBUG
constexpr auto seed() {
    return 1U;
}
#else
auto seed() {
    std::random_device device;
    return device();
}
#endif
}

Deck::Deck() : mCurrent(mCards.rbegin()) {}

void Deck::shuffle() {
    std::mt19937 randomEngine(seed());
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
