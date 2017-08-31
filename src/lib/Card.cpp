/*
 * Copyright 2016, Samuel Brand
 */

#include "Card.h"

#include <map>

namespace
{
    static const std::map< Card::Rank, std::string > RankStrings { { Card::Rank::eAce, "Ace" },
                                                                   { Card::Rank::eKing, "King" },
                                                                   { Card::Rank::eQueen, "Queen" },
                                                                   { Card::Rank::eJack, "Jack" },
                                                                   { Card::Rank::eTen,  "Ten" },
                                                                   { Card::Rank::eNine,  "Nine" },
                                                                   { Card::Rank::eEight,  "Eight" },
                                                                   { Card::Rank::eSeven,  "Seven" },
                                                                   { Card::Rank::eSix,  "Six" }, };

    static const std::map< Card::Suit, std::string > SuitStrings { { Card::Suit::eClubs, "Clubs" },
                                                                   { Card::Suit::eDiamonds, "Diamonds" },
                                                                   { Card::Suit::eHearts, "Hearts" },
                                                                   { Card::Suit::eSpades, "Spades" }, };


   std::ostream& operator<<( std::ostream& pOut, const Card::Rank& pRank )
   {
       auto rankString = RankStrings.find( pRank );
       if( rankString == std::end( RankStrings ) ) {
           throw std::invalid_argument( "Given Rank is invalid" );
       }

       pOut << rankString->second;

       return  pOut;
   }

   std::ostream& operator<<( std::ostream& pOut, const Card::Suit pSuit )
   {
       auto suitString = SuitStrings.find( pSuit  );
       if( suitString == std::end( SuitStrings ) ) {
           throw std::invalid_argument( "Given Suit is invalid" );
       }

       pOut << suitString->second;

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
