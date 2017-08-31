/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"

#include "gtest/gtest.h"

TEST( CardTest, SimpleConstructorTest ) {

    Card card;
    EXPECT_EQ( card.isValid(), false );
}
