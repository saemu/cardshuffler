/*
 * Copyright 2016, Samuel Brand
 */

#include "Card.hpp"

#include <fmt/format.h>

#include <map>
#include <string>

namespace {
// clang-format off
const std::map<Card::Rank, std::string> RankStrings{{Card::Rank::eAce,   "Ace"},
                                                    {Card::Rank::eKing,  "King"},
                                                    {Card::Rank::eQueen, "Queen"},
                                                    {Card::Rank::eJack,  "Jack"},
                                                    {Card::Rank::eTen,   "Ten"},
                                                    {Card::Rank::eNine,  "Nine"},
                                                    {Card::Rank::eEight, "Eight"},
                                                    {Card::Rank::eSeven, "Seven"},
                                                    {Card::Rank::eSix,   "Six"}};

const std::map<Card::Suit, std::string> SuitStrings{{Card::Suit::eClubs,    "Clubs"},
                                                    {Card::Suit::eDiamonds, "Diamonds"},
                                                    {Card::Suit::eHearts,   "Hearts"},
                                                    {Card::Suit::eSpades,   "Spades"}};

// clang-format on
}  // namespace

template <>
struct fmt::formatter<Card::Suit> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(Card::Suit suit, FormatContext &context) {
        const auto suitString = SuitStrings.find(suit);
        if (suitString == std::cend(SuitStrings)) {
            throw std::invalid_argument("Given Suit is invalid");
        }
        return fmt::formatter<std::string>::format(suitString->second, context);
    }
};

template <>
struct fmt::formatter<Card::Rank> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(Card::Rank rank, FormatContext &context) {
        const auto rankString = RankStrings.find(rank);
        if (rankString == std::cend(RankStrings)) {
            throw std::invalid_argument("Given Rank is invalid");
        }
        return fmt::formatter<std::string>::format(rankString->second, context);
    }
};

std::ostream &operator<<(std::ostream &pOut, const Card &pCard) {
    pOut << static_cast<std::string>(pCard);
    return pOut;
}

bool operator==(const Card &left, const Card &right) noexcept {
    return left.mRank == right.mRank && left.mSuit == right.mSuit;
}

Card::operator std::string() const {
    return fmt::format(FMT_STRING("{} of {}"), mRank, mSuit);
}
