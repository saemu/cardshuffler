/*
 * Copyright 2016, Samuel Brand
 */

#include "Deck.hpp"

#include <algorithm>
#include <random>

#include "Card.hpp"

Deck::Deck(std::random_device::result_type seed) : seed_(seed), current_(cards_.rbegin()) {}

void Deck::shuffle() {
    std::mt19937 randomEngine(seed_);
    std::shuffle(std::begin(cards_), std::end(cards_), randomEngine);
    current_ = cards_.rbegin();
}

Card Deck::drawNextCard() {
    Card card(*current_);
    ++current_;
    return card;
}

bool Deck::hasNext() const {
    return current_ != cards_.rend();
}
