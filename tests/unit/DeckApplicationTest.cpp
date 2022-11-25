/*
 * Copyright 2019, Samuel Brand
 */

#include <gtest/gtest.h>
#include <spdlog/sinks/ostream_sink.h>
#include <spdlog/spdlog.h>

#include "DeckApplication.hpp"
#include "spdlog/sinks/null_sink.h"

struct DeckApplicationTest : testing::Test {
    void SetUp() override {
        logger = spdlog::create<spdlog::sinks::null_sink_st>("null_logger");
    }

    void TearDown() override {
        spdlog::drop_all();
    }

    std::shared_ptr<spdlog::logger> logger = nullptr;
};

TEST_F(DeckApplicationTest, NoTest) {
    std::istringstream input("no");
    EXPECT_NO_THROW(DeckApplication::run(0U, input, *logger));
}

TEST_F(DeckApplicationTest, YesNoTest) {
    std::string testValues = R"__(yes
no
)__";
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(0U, input, *logger));
}

TEST_F(DeckApplicationTest, ShortTermTest) {
    std::string testValues = R"__(y
n
)__";
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(0U, input, *logger));
}

TEST_F(DeckApplicationTest, WhiteSpaceTest) {
    std::string testValues = R"__(y e s
 n o
)__";
    std::istringstream input(testValues);
    EXPECT_NO_THROW(DeckApplication::run(0U, input, *logger));
}

TEST_F(DeckApplicationTest, InvalidValuesTest) {
    std::string testValues = R"__(yes
y
exit
)__";
    std::istringstream input(testValues);
    EXPECT_THROW(DeckApplication::run(0U, input, *logger), std::invalid_argument);
}

TEST_F(DeckApplicationTest, RepeatableTest) {
    auto run = [&]() {
        std::istringstream input("no");
        std::ostringstream output;
        auto sink = std::make_shared<spdlog::sinks::ostream_sink_mt>(output);
        spdlog::logger textLogger("deckapplicationtest", sink);
        EXPECT_NO_THROW(DeckApplication::run(0U, input, textLogger));
        return output.str();
    };
    const auto first = run();
    const auto second = run();
    EXPECT_EQ(first, second);
}
