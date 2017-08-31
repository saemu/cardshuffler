/*
 * RUAG Schweiz AG
 * RUAG Aviation
 * Boenigstrasse 17
 * CH - 3812 Wilderswil - Switzerland
 *
 * Copyright (C) 2015, RUAG Schweiz AG, All rights reserved.
 *
 */

#include "Deck.h"

#include "Card.h"

#include <chrono>
#include <random>

using cRank = Card::Rank;
using cSuit = Card::Suit;

Deck::Deck() :
   mCards { Card( cSuit::eSpades, cRank::eAce ),
            Card( cSuit::eSpades, cRank::eKing ),
            Card( cSuit::eSpades, cRank::eQueen ),
            Card( cSuit::eSpades, cRank::eJack ),
            Card( cSuit::eSpades, cRank::eTen ),
            Card( cSuit::eSpades, cRank::eNine ),
            Card( cSuit::eSpades, cRank::eEight ),
            Card( cSuit::eSpades, cRank::eSeven ),
            Card( cSuit::eSpades, cRank::eSix ),
            Card( cSuit::eHearts, cRank::eAce ),
            Card( cSuit::eHearts, cRank::eKing ),
            Card( cSuit::eHearts, cRank::eQueen ),
            Card( cSuit::eHearts, cRank::eJack ),
            Card( cSuit::eHearts, cRank::eTen ),
            Card( cSuit::eHearts, cRank::eNine ),
            Card( cSuit::eHearts, cRank::eEight ),
            Card( cSuit::eHearts, cRank::eSeven ),
            Card( cSuit::eHearts, cRank::eSix ),
            Card( cSuit::eDiamonds, cRank::eAce ),
            Card( cSuit::eDiamonds, cRank::eKing ),
            Card( cSuit::eDiamonds, cRank::eQueen ),
            Card( cSuit::eDiamonds, cRank::eJack ),
            Card( cSuit::eDiamonds, cRank::eTen ),
            Card( cSuit::eDiamonds, cRank::eNine ),
            Card( cSuit::eDiamonds, cRank::eEight ),
            Card( cSuit::eDiamonds, cRank::eSeven ),
            Card( cSuit::eDiamonds, cRank::eSix ),
            Card( cSuit::eClubs, cRank::eAce ),
            Card( cSuit::eClubs, cRank::eKing ),
            Card( cSuit::eClubs, cRank::eQueen ),
            Card( cSuit::eClubs, cRank::eJack ),
            Card( cSuit::eClubs, cRank::eTen ),
            Card( cSuit::eClubs, cRank::eNine ),
            Card( cSuit::eClubs, cRank::eEight ),
            Card( cSuit::eClubs, cRank::eSeven ),
            Card( cSuit::eClubs, cRank::eSix ) }
{
}

void Deck::shuffle()
{
   auto lSeed = std::chrono::system_clock::now().time_since_epoch().count();
   std::shuffle( std::begin( mCards ), std::end( mCards ), std::default_random_engine( lSeed ) );
   mCurrent = mCards.rbegin();
}

Card Deck::drawNextCard()
{
   Card lReturn( *mCurrent );
   ++mCurrent;
   return lReturn;
}

bool Deck::hasNext() const
{
   return mCurrent != mCards.rend();
}

