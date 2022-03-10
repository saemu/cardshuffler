/*
 * Copyright 2016, Samuel Brand
 */

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "lib/DeckApplication.hpp"

int main(int /*argc*/, char*[] /*argv*/) try {
    auto logger = spdlog::stdout_color_mt("console");
    DeckApplication::run(std::cin, *logger);
    return EXIT_SUCCESS;
} catch (const std::invalid_argument& ex) {
    spdlog::error("invalid_argument exception: {}", ex.what());
    return EXIT_FAILURE;
}
