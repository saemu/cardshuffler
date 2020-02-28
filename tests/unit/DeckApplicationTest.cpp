/*
 * Copyright 2019, Samuel Brand
 */

#include "lib/DeckApplication.hpp"
#include "spdlog/sinks/null_sink.h"

#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

auto logger = spdlog::create<spdlog::sinks::null_sink_st>("null_logger");

TEST(DeckApplicationTest, YesNoTest) {
    std::string testValues = R"__(yes
no
)__";
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(input, *logger));
}

TEST(DeckApplicationTest, ShortTermTest) {
    std::string testValues = R"__(y
n
)__";
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(input, *logger));
}

TEST(DeckApplicationTest, WhiteSpaceTest) {
    std::string testValues = R"__(y e s
 n o
)__";
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(input, *logger));
}

TEST(DeckApplicationTest, InvalidValuesTest) {
    std::string testValues = R"__(yes
y
exit
)__";
    std::istringstream input(testValues);
    EXPECT_THROW(DeckApplication::run(input, *logger), std::invalid_argument);
}
