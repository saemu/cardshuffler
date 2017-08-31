/*
 * RUAG Schweiz AG
 * RUAG Aviation
 * Boenigstrasse 17
 * CH - 3812 Wilderswil - Switzerland
 *
 * Copyright (C) 2015, RUAG Schweiz AG, All rights reserved.
 *
 */

#pragma once

#include <iostream>

class Card
{
   public:

      friend std::ostream& operator<<( std::ostream& pOut, const Card& pCard );

      enum Suit
      {
         eUnknown,
         eSpades,
         eHearts,
         eDiamonds,
         eClubs
      };

      enum class Rank
      {
         eUnknown,
         eSix,
         eSeven,
         eEight,
         eNine,
         eTen,
         eJack,
         eQueen,
         eKing,
         eAce
      };

      Card() :
         mSuit( Suit::eUnknown ),
         mRank( Rank::eUnknown )
      {
      }

      Card( Suit pSuit, Rank pRank ) :
         mSuit( pSuit ),
         mRank( pRank )
      {
      }

      Card( const Card& pObject );
      Card( const Card&& pObject );

      virtual ~Card() = default;

      Card& operator=( const Card& pObject );
      Card& operator=( const Card&& pObject );

      bool isValid() const;

   private:

      Suit mSuit;
      Rank mRank;


};

