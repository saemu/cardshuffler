/*
 * Copyright 2020, Samuel Brand
 */

#include "DeckApplication.hpp"

#include "lib/Card.hpp"

#include <algorithm>
#include <map>
#include <string>

namespace {
std::string readInput(std::istream& input, std::ostream& output) {
    std::string quit;
    output << "new shuffle [y/n]: ";
    if (std::getline(input, quit)) {
        quit.erase(std::remove_if(quit.begin(), quit.end(), ::isspace), quit.end());
    }
    return quit;
}

bool validateInput(const std::string& input, const std::map<std::string, bool>& validInputs) {
    auto const answer = validInputs.find(input);
    if (answer == std::cend(validInputs)) {
        throw std::invalid_argument("your answer is wrong, exiting");
    }
    return answer->second;
}

bool readAnswer(std::istream& input, std::ostream& output) {
    // clang-format off
    static const std::map<std::string, bool> validInputs{{"y",   true,},
                                                         {"yes", true,},
                                                         {"n",   false},
                                                         {"no",  false},};
    // clang-format on
    std::string answer = readInput(input, output);
    return validateInput(answer, validInputs);
}

}  // namespace

void DeckApplication::run(std::istream& input, std::ostream& output) {
    bool running{true};
    Deck deck;
    do {
        deck.shuffle();
        do {
            const Card card = deck.drawNextCard();
            output << "Card" << card << '\n';
        } while (deck.hasNext());
        running = readAnswer(input, output);
    } while (running);
}
