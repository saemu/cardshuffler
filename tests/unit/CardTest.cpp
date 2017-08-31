/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"

#include "gtest/gtest.h"

TEST(CardTest, SimpleConstructorTest) {

    Card card;
    EXPECT_FALSE(card.isValid());
}

TEST(CardTest, ConstructorTest) {
    EXPECT_NO_THROW(Card(Card::Suit::eSpades, Card::Rank::eAce));

    {
        Card card(Card::Suit::eClubs, Card::Rank::eKing);
        EXPECT_TRUE(card.isValid());
    }

    {
        Card card(Card::Suit::eUnknown, Card::Rank::eQueen);
        EXPECT_FALSE(card.isValid());
    }

    {
        Card card(Card::Suit::eClubs, Card::Rank::eUnknown);
        EXPECT_FALSE(card.isValid());
    }
}
