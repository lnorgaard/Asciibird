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
  Sprite Sprite1_("sprites/high.txt", 10, 10, true);
  Sprite Sprite2_("sprites/low.txt", 10, 30, true);
  Sprite Sprite3_("sprites/middle.txt", 10, 50, true);
  Sprite Sprite4_("sprites/low.txt", 10, 70, true);
  Sprite Bird_("sprites/bird.txt", 15, 60, false);
  
  // Create an Asciimation, add the sprite to the asciimation,
  // and show the asciimation!
  Asciimation mysteryAsciimation_;
  mysteryAsciimation_.createLibrary("sprites/middle.txt", "sprites/low.txt", "sprites/high.txt");
  mysteryAsciimation_.addSprite1(&Sprite1_);
  mysteryAsciimation_.addSprite2(&Sprite2_);
  mysteryAsciimation_.addSprite3(&Sprite3_);
  mysteryAsciimation_.addSprite4(&Sprite4_);
  mysteryAsciimation_.addBird(&Bird_);
  mysteryAsciimation_.show();
  
  return 0;
}
