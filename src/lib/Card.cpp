/*
 * Copyright 2016, Samuel Brand
 */

#include "Card.hpp"

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

std::ostream &operator<<(std::ostream &pOut, const Card::Rank &pRank) {
    auto rankString = RankStrings.find(pRank);
    pOut << rankString->second;
    return pOut;
}

std::ostream &operator<<(std::ostream &pOut, const Card::Suit pSuit) {
    auto suitString = SuitStrings.find(pSuit);
    pOut << suitString->second;
    return pOut;
}

}  // namespace

std::ostream &operator<<(std::ostream &pOut, const Card &pCard) {
    pOut << pCard.mRank << " of " << pCard.mSuit;
    return pOut;
}

bool operator==(const Card &left, const Card &right) noexcept {
    return left.mRank == right.mRank && left.mSuit == right.mSuit;
}
