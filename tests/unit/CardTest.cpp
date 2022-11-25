/*
 * Copyright 2019, Samuel Brand
 */

#include <gtest/gtest.h>

#include "Card.hpp"

TEST(CardTest, ConstructorNoThrowTest) {
    EXPECT_NO_THROW(Card(Card::Suit::eSpades, Card::Rank::eAce));
}

TEST(CardTest, ConstructorValidTest) {
    EXPECT_NO_THROW(Card Card(Card::Suit::eClubs, Card::Rank::eKing));
}

TEST(CardTest, CopyConstructorTest) {
    Card card(Card::Suit::eDiamonds, Card::Rank::eJack);
    EXPECT_NO_THROW((Card(card)));
    EXPECT_EQ(card, Card(card));
}

TEST(CardTest, AssignmentOperatorTest) {
    Card card(Card::Suit::eClubs, Card::Rank::eTen);
    EXPECT_NO_THROW(Card cardOne = card);
    Card cardTwo = card;
    EXPECT_EQ(cardTwo, card);
}

TEST(CardTest, MoveConstructorTest) {
    Card card(Card::Suit::eHearts, Card::Rank::eNine);
    EXPECT_NO_THROW(Card cardOne(std::move(card)));
}

TEST(CardTest, MoveAssignmentOperatorTest) {
    Card card(Card::Suit::eHearts, Card::Rank::eEight);
    EXPECT_NO_THROW(Card cardOne = std::move(card));
}

TEST(CardTest, EqualOpearatorTest) {
    EXPECT_EQ(Card(Card::Suit::eHearts, Card::Rank::eNine), Card(Card::Suit::eHearts, Card::Rank::eNine));
    EXPECT_EQ(Card(Card::Suit::eHearts, Card::Rank::eSeven), Card(Card::Suit::eHearts, Card::Rank::eSeven));
    EXPECT_EQ(Card(Card::Suit::eSpades, Card::Rank::eNine), Card(Card::Suit::eSpades, Card::Rank::eNine));
}

TEST(CardTest, OutStreamOperatorTest) {
    std::ostringstream stream;
    Card card(Card::Suit::eSpades, Card::Rank::eKing);
    stream << card;
    EXPECT_EQ("King of Spades", stream.str());
}

TEST(CardTest, InvalidRank) {
    std::ostringstream stream;
    constexpr auto InvalidRank = 1024U;
    Card card(Card::Suit::eSpades, static_cast<Card::Rank>(InvalidRank));
    EXPECT_THROW(stream << card, std::invalid_argument);
}

TEST(CardTest, InvalidSuit) {
    std::ostringstream stream;
    constexpr auto InvalidSuit = 1024U;
    Card card(static_cast<Card::Suit>(InvalidSuit), Card::Rank::eAce);
    EXPECT_THROW(stream << card, std::invalid_argument);
}
