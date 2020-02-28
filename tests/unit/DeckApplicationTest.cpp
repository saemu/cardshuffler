/*
 * Copyright 2019, Samuel Brand
 */

#include "lib/DeckApplication.hpp"

#include <gtest/gtest.h>

TEST(DeckApplicationTest, YesNoTest) {
    std::string testValues = R"__(yes
no
)__";
    std::ostringstream output;
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(input, output));
}

TEST(DeckApplicationTest, ShortTermTest) {
    std::string testValues = R"__(y
n
)__";
    std::ostringstream output;
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(input, output));
}

TEST(DeckApplicationTest, WhiteSpaceTest) {
    std::string testValues = R"__(y e s
 n o
)__";
    std::ostringstream output;
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(input, output));
}

TEST(DeckApplicationTest, InvalidValuesTest) {
    std::string testValues = R"__(yes
y
exit
)__";
    std::ostringstream output;
    std::istringstream input(testValues);
    EXPECT_THROW(DeckApplication::run(input, output), std::invalid_argument);
}
