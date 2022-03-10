/*
 * Copyright 2019, Samuel Brand
 */

#include "Card.hpp"
#include "Deck.hpp"

#include <gtest/gtest.h>

TEST(DeckTest, ConstructorTest) {
    EXPECT_NO_THROW(Deck deck);
}

TEST(DeckTest, hasNextText) {
    Deck deck;
    EXPECT_TRUE(deck.hasNext());
}

TEST(DeckTest, shuffleTest) {
    Deck deck;
    EXPECT_NO_THROW(deck.shuffle());
}

TEST(DeckTest, drawCardTest) {
    Deck deck;
    EXPECT_NO_THROW(deck.drawNextCard());
    EXPECT_NO_THROW(auto card = deck.drawNextCard());
}

TEST(DeckTest, drawAllTest) {
    Deck deck;
    while(deck.hasNext()) {
        EXPECT_NO_THROW(deck.drawNextCard());
    }
}
