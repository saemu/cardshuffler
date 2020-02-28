/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/DeckApplication.hpp"

#include <spdlog/spdlog.h>

int main(int /*argc*/, char*[] /*argv*/) {
    try {
        DeckApplication::run(std::cin, std::cout);
    } catch (const std::invalid_argument& ex) {
        spdlog::error("invalid_argument exception: {}", ex.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
