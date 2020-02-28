/*
 * Copyright 2020, Samuel Brand
 */

#pragma once

#include "lib/Deck.hpp"

namespace spdlog {
class logger;
}

class DeckApplication {
public:
    static void run(std::istream& input, spdlog::logger& output);
};
