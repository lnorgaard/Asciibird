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
  
  // Create a Sprite object, have it load high.txt, medium.txt, and low.txt,
  // set the location, and make it move.
  Sprite highSprite_("sprites/high.txt", 10, 10, true);
  Sprite mediumSprite_("sprites/medium.txt", 10, 16, true);
  Sprite lowSprite_("sprites/low.txt", 10, 22, true);
  
  // Create an Asciimation, add the sprite to the asciimation,
  // and show the asciimation!
  Asciimation mysteryAsciimation_;
  mysteryAsciimation_.addSprite(&highSprite_);
  mysteryAsciimation_.addSprite(&mediumSprite_);
  mysteryAsciimation_.addSprite(&lowSprite_);
  mysteryAsciimation_.show();
  
  return 0;
}
