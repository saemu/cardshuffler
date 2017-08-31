/*
 * RUAG Schweiz AG
 * RUAG Aviation
 * Boenigstrasse 17
 * CH - 3812 Wilderswil - Switzerland
 *
 * Copyright (C) 2015, RUAG Schweiz AG, All rights reserved.
 *
 */

#include "Card.h"

namespace
{
   std::ostream& operator<<( std::ostream& pOut, const Card::Rank& pRank )
   {
      switch ( pRank )
      {
         case Card::Rank::eAce:
            pOut << "Ace";
         break;

         case Card::Rank::eKing:
            pOut << "King";
         break;

         case Card::Rank::eQueen:
            pOut << "Queen";
         break;

         case Card::Rank::eJack:
            pOut << "Jack";
         break;

         case Card::Rank::eTen:
            pOut << "Ten";
         break;

         case Card::Rank::eNine:
            pOut << "Nine";
         break;

         case Card::Rank::eEight:
            pOut << "Eight";
         break;

         case Card::Rank::eSeven:
            pOut << "Seven";
         break;

         case Card::Rank::eSix:
            pOut << "Six";
         break;

         default:
         break;
      }

      return pOut;
   }

   std::ostream& operator<<( std::ostream& pOut, const Card::Suit pSuit )
   {
      switch ( pSuit )
      {
         case Card::Suit::eSpades:
            pOut << "Spades";
         break;

         case Card::Suit::eHearts:
            pOut << "Hearts";
         break;

         case Card::Suit::eDiamonds:
            pOut << "Diamonds";
         break;

         case Card::Suit::eClubs:
            pOut << "Clubs";
         break;

         default:
         break;
      }
      return pOut;
   }

} // namespace

std::ostream& operator<<( std::ostream& pOut, const Card& pCard )
{
   pOut << pCard.mRank << " of " << pCard.mSuit;
   return pOut;
}

Card::Card( const Card& pObject ) :
   mSuit( pObject.mSuit ),
   mRank( pObject.mRank )
{
}

Card::Card( const Card&& pObject ) :
   mSuit( std::move( pObject.mSuit ) ),
   mRank( std::move( pObject.mRank ) )
{
}

Card& Card::operator=( const Card& pObject )
{
   if( this != &pObject )
   {
      mSuit = pObject.mSuit;
      mRank = pObject.mRank;
   }
   return *this;
}

Card& Card::operator=( const Card&& pObject )
{
   if( this != &pObject )
   {
      mSuit = std::move( pObject.mSuit );
      mRank = std::move( pObject.mRank );
   }
   return *this;
}

bool Card::isValid() const
{
   return mSuit != Suit::eUnknown && mRank != Rank::eUnknown;

}
