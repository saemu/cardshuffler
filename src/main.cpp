/*
 * Copyright 2016, Samuel Brand
 */

#include "lib/Card.hpp"
#include "lib/Deck.hpp"

#include <map>
#include <string>

namespace {

    // clang-format off
    const std::map<std::string, bool> validInputs{{"y",   true,},
                                                  {"yes", true,},
                                                  {"n",   false},
                                                  {"no",  false},};
    // clang-format on

bool readAnswer() {
    std::string lQuit;
    std::cout << "new shuffle [y/n]: ";
    std::cin >> lQuit;

    auto answer = validInputs.find(lQuit);
    if (answer == std::end(validInputs)) {
        throw std::invalid_argument("your answer is wrong, exiting");
    }

    return answer->second;
}

}  // namespace

int main(int, char**) {
    try {
        Deck lDeck;

        bool running{true};

        do {
            lDeck.shuffle();
            do {
                Card lCard = lDeck.drawNextCard();
                std::cout << "Card " << lCard << std::endl;
            } while (lDeck.hasNext());

            running = readAnswer();

        } while (running);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
