/*
 * Copyright 2016, Samuel Brand
 */

#pragma once

#include <iostream>

class Card {
public:
    friend std::ostream& operator<<(std::ostream& pOut, const Card& pCard);
    friend bool operator==(const Card& left, const Card& right) noexcept;

    enum class Suit { eUnknown, eSpades, eHearts, eDiamonds, eClubs };

    enum class Rank { eUnknown, eSix, eSeven, eEight, eNine, eTen, eJack, eQueen, eKing, eAce };

    Card() = default;

    Card(Suit pSuit, Rank pRank) : mSuit(pSuit), mRank(pRank) {}

    Card(const Card& pObject) = default;

    Card(Card&& pObject) noexcept = default;

    virtual ~Card() = default;

    Card& operator=(const Card& pObject) = default;

    Card& operator=(Card&& pObject) noexcept = default;

    explicit operator std::string() const;

    bool isValid() const;

private:
    Suit mSuit = Suit::eUnknown;
    Rank mRank = Rank::eUnknown;
};
