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

#include "lib/Card.h"

#include <vector>

class Card;

class Deck
{
   public:

      Deck();
      virtual ~Deck() = default;

      void shuffle();

      Card drawNextCard();

      bool hasNext() const;

   private:

      std::vector< Card > mCards;

      std::vector< Card >::reverse_iterator mCurrent;

};
