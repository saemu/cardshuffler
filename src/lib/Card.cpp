/*
 * Copyright 2016, Samuel Brand
 */

#include "Card.hpp"

#include <map>

namespace {
    const std::map<Card::Rank, std::string> RankStrings{{Card::Rank::eAce,   "Ace"},
                                                        {Card::Rank::eKing,  "King"},
                                                        {Card::Rank::eQueen, "Queen"},
                                                        {Card::Rank::eJack,  "Jack"},
                                                        {Card::Rank::eTen,   "Ten"},
                                                        {Card::Rank::eNine,  "Nine"},
                                                        {Card::Rank::eEight, "Eight"},
                                                        {Card::Rank::eSeven, "Seven"},
                                                        {Card::Rank::eSix,   "Six"},};

    const std::map<Card::Suit, std::string> SuitStrings{{Card::Suit::eClubs,    "Clubs"},
                                                        {Card::Suit::eDiamonds, "Diamonds"},
                                                        {Card::Suit::eHearts,   "Hearts"},
                                                        {Card::Suit::eSpades,   "Spades"},};


    std::ostream& operator<<(std::ostream& pOut, const Card::Rank& pRank) {
        auto rankString = RankStrings.find(pRank);
        if (rankString == std::end(RankStrings)) {
            throw std::invalid_argument("Given Rank is invalid");
        }

        pOut << rankString->second;

        return pOut;
    }

    std::ostream& operator<<(std::ostream& pOut, const Card::Suit pSuit) {
        auto suitString = SuitStrings.find(pSuit);
        if (suitString == std::end(SuitStrings)) {
            throw std::invalid_argument("Given Suit is invalid");
        }

        pOut << suitString->second;

        return pOut;
    }

} // namespace

std::ostream& operator<<(std::ostream& pOut, const Card& pCard) {
    pOut << pCard.mRank << " of " << pCard.mSuit;
    return pOut;
}

bool operator==(const Card& left, const Card& right) noexcept {
    return left.mRank == right.mRank && left.mSuit == right.mSuit;
}

bool Card::isValid() const {
    return mSuit != Suit::eUnknown && mRank != Rank::eUnknown;

}
