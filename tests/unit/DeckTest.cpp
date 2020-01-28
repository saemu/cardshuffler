/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"
#include "lib/Deck.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(DeckTest)

BOOST_AUTO_TEST_CASE(ConstructorTest) {
    BOOST_CHECK_NO_THROW(Deck deck);
}

BOOST_AUTO_TEST_CASE(hasNextText) {
    Deck deck;
    BOOST_TEST(deck.hasNext());
}

BOOST_AUTO_TEST_CASE(shuffleTest) {
    Deck deck;
    BOOST_CHECK_NO_THROW(deck.shuffle());
}

BOOST_AUTO_TEST_CASE(drawCardTest) {
    Deck deck;
    BOOST_CHECK_NO_THROW(deck.drawNextCard());
    auto card = deck.drawNextCard();
    BOOST_TEST(card.isValid());
}

BOOST_AUTO_TEST_CASE(drawAllTest) {
    Deck deck;
    while (deck.hasNext()) {
        BOOST_CHECK_NO_THROW(deck.drawNextCard());
    }
}

BOOST_AUTO_TEST_SUITE_END()
