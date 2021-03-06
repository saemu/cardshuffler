/*
 * Copyright 2016, Samuel Brand
 */

#pragma once

#include <iostream>

class Card {
public:
    friend std::ostream& operator<<(std::ostream& pOut, const Card& pCard);
    friend bool operator==(const Card& left, const Card& right) noexcept;

    enum class Suit { eSpades, eHearts, eDiamonds, eClubs };

    enum class Rank { eSix, eSeven, eEight, eNine, eTen, eJack, eQueen, eKing, eAce };

    Card() = delete;

    Card(Suit pSuit, Rank pRank) : mSuit(pSuit), mRank(pRank) {}

    explicit operator std::string() const;

private:
    Suit mSuit = Suit::eHearts;
    Rank mRank = Rank::eQueen;
};
