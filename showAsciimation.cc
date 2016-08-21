/**
 * \file showAsciimation.cc
 * \author cs70 Provided Code and Lee Norgaard
 *
 * \brief Provides the main() function for running an asciimation
 *
 * \details An asciimation of awesome things that move to the right
 *
 *
 */

#include "Asciimation.h"
#include "Sprite.h"

int main() {
  
  // Create a Sprite object, have it load sprites/arbitrarySize_mystery2.txt,
  // set the location, and make it move.
  Sprite mysterySprite_("sprites/arbitrarySize_mystery2.txt", 10, 10, true);
  
  // Create an Asciimation, add the sprite to the asciimation,
  // and show the asciimation!
  Asciimation mysteryAsciimation_;
  mysteryAsciimation_.addSprite(&mysterySprite_);
  mysteryAsciimation_.show();
  
  return 0;
}
