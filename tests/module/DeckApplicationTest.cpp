#include <gtest/gtest.h>
#include <spdlog/sinks/ostream_sink.h>
#include <spdlog/spdlog.h>

#include <ApprovalTests.hpp>

#include "DeckApplication.hpp"

using namespace ApprovalTests;

struct DeckApplicationTest : testing::Test {
    void SetUp() override {
        input.clear();
        output.clear();
        sink = std::make_shared<spdlog::sinks::ostream_sink_mt>(output);
        sink->set_pattern("%v");
        logger = std::make_shared<spdlog::logger>("testlogger", sink);
    }

    void TearDown() override {
        spdlog::drop_all();
    }

    std::shared_ptr<spdlog::logger> logger = nullptr;
    std::shared_ptr<spdlog::sinks::sink> sink = nullptr;
    std::stringstream input;
    std::stringstream output;
};

TEST_F(DeckApplicationTest, ValidInput) {
    input << R"__(n
)__";
    DeckApplication::run(0U, input, *logger);
    Approvals::verify(output.str());
}

TEST_F(DeckApplicationTest, InvalidInput) {
    input << R"__(foo
)__";

    EXPECT_THROW(DeckApplication::run(0U, input, *logger), std::invalid_argument);
    Approvals::verify(output.str());
}
