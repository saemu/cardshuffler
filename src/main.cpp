/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"
#include "lib/Deck.hpp"

#include <map>
#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace {
bool readAnswer() {
    // clang-format off
    static const std::map<std::string, bool> validInputs{{"y",   true,},
                                                         {"yes", true,},
                                                         {"n",   false},
                                                         {"no",  false},};
    // clang-format on
    std::string quit;
    spdlog::info("new shuffle [y/n]: ");
    std::cin >> quit;
    auto answer = validInputs.find(quit);
    if (answer == std::end(validInputs)) {
        throw std::invalid_argument("your answer is wrong, exiting");
    }
    return answer->second;
}

}  // namespace

int main(int, char**) {
    try {
        spdlog::set_pattern("%v");
        Deck deck;
        bool running{true};
        do {
            deck.shuffle();
            do {
                const Card lCard = deck.drawNextCard();
                spdlog::info("Card {}", lCard);
            } while (deck.hasNext());
            running = readAnswer();
        } while (running);
    } catch (const std::logic_error& ex) {
        spdlog::error("Logical error: {}", ex.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
