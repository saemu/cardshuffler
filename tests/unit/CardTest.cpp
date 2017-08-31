//
// Created by Samuel Brand on 29.11.16.
//


#include "lib/Card.h"

#include "gtest/gtest.h"

TEST( CardTest, ConstructorTest ) {

    Card card;
    EXPECT_EQ( card.isValid(), false );
}