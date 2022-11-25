/*
 * Copyright 2019, Samuel Brand
 */

#include <gtest/gtest.h>

#include "Card.hpp"
#include "Deck.hpp"

namespace {
struct DeckTest : testing::Test {
    std::random_device device{};
};
}  // namespace

TEST_F(DeckTest, ConstructorTest) {
    EXPECT_NO_THROW(Deck deck{device()});
}

TEST_F(DeckTest, hasNextText) {
    Deck deck{device()};
    EXPECT_TRUE(deck.hasNext());
}

TEST_F(DeckTest, shuffleTest) {
    Deck deck{device()};
    EXPECT_NO_THROW(deck.shuffle());
}

TEST_F(DeckTest, drawCardTest) {
    Deck deck{device()};
    EXPECT_NO_THROW(deck.drawNextCard());
    EXPECT_NO_THROW(auto card = deck.drawNextCard());
}

TEST_F(DeckTest, drawAllTest) {
    Deck deck{device()};
    while (deck.hasNext()) {
        EXPECT_NO_THROW(deck.drawNextCard());
    }
}
