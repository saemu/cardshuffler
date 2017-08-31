/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"

#include "gtest/gtest.h"

TEST( CardTest, SimpleConstructorTest ) {

    Card card;
    EXPECT_EQ( card.isValid(), false );
}

TEST( CardTest, ConstructorTest ) {
    EXPECT_NO_THROW(Card(Card::eSpades, Card::Rank::eAce));
}
