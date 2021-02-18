#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/ostream_sink.h>

#include <ApprovalTests.hpp>

#include "lib/DeckApplication.hpp"

using namespace ApprovalTests;

struct DeckApplicationTest : testing::Test {

    void SetUp() override {
        input.clear();
        output.clear();
        sink = std::make_shared<spdlog::sinks::ostream_sink_mt>(output);
        sink->set_pattern("%v");
        logger = std::make_shared<spdlog::logger>("testlogger", sink);
    }

    void TearDown() override  {
        spdlog::drop_all();
    }

    std::shared_ptr<spdlog::logger> logger = nullptr;
    std::shared_ptr<spdlog::sinks::sink> sink = nullptr;
    DeckApplication application;
    std::stringstream input;
    std::stringstream output;
};

TEST_F(DeckApplicationTest, ValidInput) {
    input << R"__(n
)__";
    application.run(input, *logger);
    Approvals::verify(output.str());
}

TEST_F(DeckApplicationTest, InvalidInput) {
    input << R"__(foo
)__";

    EXPECT_THROW(application.run(input, *logger), std::invalid_argument);
    Approvals::verify(output.str());
}
