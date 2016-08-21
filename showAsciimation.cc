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
  
  // Create the first 4 moving obstacles 
  // (all middle height so user doesn't die on accident)
  Sprite Sprite1_("sprites/middle.txt", 10, 10, true);
  Sprite Sprite2_("sprites/middle.txt", 10, 30, true);
  Sprite Sprite3_("sprites/middle.txt", 10, 50, true);
  Sprite Sprite4_("sprites/middle.txt", 10, 70, true);

  // Create the bird (false because it shouldn't move)
  Sprite Bird_("sprites/bird.txt", 15, 60, false);
  
  // Create an Asciimation, add the sprites to the asciimation,
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
