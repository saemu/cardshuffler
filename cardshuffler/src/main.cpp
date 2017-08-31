/*
 * RUAG Schweiz AG
 * RUAG Aviation
 * Boenigstrasse 17
 * CH - 3812 Wilderswil - Switzerland
 *
 * Copyright (C) 2015, RUAG Schweiz AG, All rights reserved.
 *
 */

#include "lib/Card.h"
#include "lib/Deck.h"

#include <iostream>

int main( int argc, char* argv[] )
{
   static_cast< void >( argc );
   static_cast< void >( argv );

   Deck lDeck;

   bool lDoQuit = false;

   while( !lDoQuit )
   {
      lDeck.shuffle();

      do
      {
         Card lCard = lDeck.drawNextCard();
         std::cout << "Card " << lCard << std::endl;
      }
      while( lDeck.hasNext() );

      std::string lQuit;
      std::cout << "new shuffle [y/n]: ";
      std::cin >> lQuit;

      if( lQuit == "y" )
      {
         lDoQuit = false;
      }
      else if( lQuit == "n" )
      {
         lDoQuit = true;
      }
      else
      {
         std::cout << "you entered something wrong!" << std::endl;
         return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}
