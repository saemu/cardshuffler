/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/DeckApplication.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main(int /*argc*/, char*[] /*argv*/) {
    try {
        auto logger = spdlog::stdout_color_mt("console");
        DeckApplication::run(std::cin, *logger);
    } catch (const std::invalid_argument& ex) {
        spdlog::error("invalid_argument exception: {}", ex.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
