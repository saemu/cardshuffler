/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(CardTest)

BOOST_AUTO_TEST_CASE(SimpleConstructorTest) {
    Card card;
    BOOST_TEST(card.isValid() == false);
}

BOOST_AUTO_TEST_CASE(ConstructorNoThrowTest) {
    BOOST_CHECK_NO_THROW(Card(Card::Suit::eSpades, Card::Rank::eAce));
}

BOOST_AUTO_TEST_CASE(ConstructorValidTest) {
    Card card(Card::Suit::eClubs, Card::Rank::eKing);
    BOOST_TEST(card.isValid() == true);
}

BOOST_AUTO_TEST_CASE(ConstructorInvalidSuitTest) {
    Card card(Card::Suit::eUnknown, Card::Rank::eQueen);
    BOOST_TEST(card.isValid() == false);
}

BOOST_AUTO_TEST_CASE(ConstructorInvalidRankTest) {
    Card card(Card::Suit::eClubs, Card::Rank::eUnknown);
    BOOST_TEST(card.isValid() == false);
}

BOOST_AUTO_TEST_CASE(CopyConstructorTest) {
    Card card(Card::Suit::eDiamonds, Card::Rank::eJack);
    BOOST_CHECK_NO_THROW((Card(card)));
    BOOST_TEST(card == Card(card));
}

BOOST_AUTO_TEST_CASE(AssignmentOperatorTest) {
    Card card(Card::Suit::eClubs, Card::Rank::eTen);
    BOOST_CHECK_NO_THROW(Card cardOne = card);
    Card cardTwo = card;
    BOOST_TEST(cardTwo == card);
}

BOOST_AUTO_TEST_CASE(MoveConstructorTest) {
    Card card(Card::Suit::eHearts, Card::Rank::eNine);
    BOOST_CHECK_NO_THROW(Card cardOne(std::move(card)));
}

BOOST_AUTO_TEST_CASE(MoveAssignmentOperatorTest) {
    Card card(Card::Suit::eHearts, Card::Rank::eEight);
    BOOST_CHECK_NO_THROW(Card cardOne = std::move(card));
}

BOOST_AUTO_TEST_CASE(EqualOpearatorTest) {
    BOOST_TEST(Card(Card::Suit::eHearts, Card::Rank::eNine) == Card(Card::Suit::eHearts, Card::Rank::eNine));
    BOOST_TEST(Card(Card::Suit::eHearts, Card::Rank::eSeven) == Card(Card::Suit::eHearts, Card::Rank::eSeven));
    BOOST_TEST(Card(Card::Suit::eSpades, Card::Rank::eNine) == Card(Card::Suit::eSpades, Card::Rank::eNine));
}

BOOST_AUTO_TEST_CASE(OutStreamOperatorTest) {
    std::ostringstream stream;
    Card card(Card::Suit::eSpades, Card::Rank::eKing);
    stream << card;
    BOOST_TEST( "King of Spades", stream.str());
}

BOOST_AUTO_TEST_SUITE_END()
