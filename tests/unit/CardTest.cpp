/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"

#include "gtest/gtest.h"

void PrintTo(const Card& card, std::ostream* out) {
    *out << "Card=[" << card << "]";
}

TEST(CardTest, SimpleConstructorTest) {
    Card card;
    EXPECT_EQ(card.isValid(), false);
}

TEST(CardTest, ConstructorNoThrowTest) {
    EXPECT_NO_THROW(Card(Card::Suit::eSpades, Card::Rank::eAce));
}

TEST(CardTest, ConstructorValidTest) {
    Card card(Card::Suit::eClubs, Card::Rank::eKing);
    EXPECT_EQ(card.isValid(), true);
}

TEST(CardTest, ConstructorInvalidSuitTest) {
    Card card(Card::Suit::eUnknown, Card::Rank::eQueen);
    EXPECT_EQ(card.isValid(), false);
}

TEST(CardTest, ConstructorInvalidRankTest) {
    Card card(Card::Suit::eClubs, Card::Rank::eUnknown);
    EXPECT_EQ(card.isValid(), false);
}
