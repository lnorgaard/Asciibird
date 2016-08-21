/* Asciimation.h
   =========
   Written/Edited: cs70 and Lee Norgaard
   Interface definition for the Asciimation class, which handles the main screen
   and coordination of an asciimation.
*/

#ifndef ASCIIMATION_H_INCLUDED
#define ASCIIMATION_H_INCLUDED = 1;

#include "Sprite.h"

/**
 * \class Asciimation
 * 
 * \brief Holds the contents of an ASCIImation
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, and
 * a Sprite that will be added to the screen.
 *
 */
class Asciimation {
public:
  static const size_t SCREEN_WIDTH = 80;
  static const size_t SCREEN_HEIGHT = 40;
  static const size_t SCREEN_AREA = SCREEN_WIDTH * SCREEN_HEIGHT;

  /**
   * \brief Displays a sprite on the screen until the user enters "q"
   * 
   * \post The screen is destroyed.
   */
  void show();
  
  /**
   * \brief Returns the height of the sprite
   */
   size_t getSpriteHeight();
   
  /**
   * \brief Returns the width of the sprite
   */
   size_t getSpriteWidth();
  
  /**
   * \brief places characters into the buffer
   * 
   * \details
   * Clears the Asciimation's character buffer, then copies characters
   * from the stored Sprite to the character buffer using the Sprite's 
   * getCharAt member function. It should place each character at the 
   * right spot in the Asciimation's character buffer.
   * 
   * \post Asciimation object is updated desired characters
   */
  void prepareBufferForDisplay(); 

  /**
   * \brief Copies the current buffer contents to ncurses
   * \post No change to the Asciimation object
   */
  void copyBufferToNcurses();
  
  /*
  * \brief adds a sprite
  *
  * \details
  * Takes in a reference to a Sprite and stores it in the appropriate 
  * data member of the Asciimation object
  */
  void addSprite(Sprite* oneSprite);

private:

   /*
   * \brief data member that holds the characters
   *
   * \details
   * A buffer of characters of length SCREEN_WIDTH * SCREEN_HEIGHT 
   * that holds all of the currently-displayed characters for the 
   * entire screen.
   */
   char screenStored_[SCREEN_AREA];

   /*
   * \brief A Sprite object that will be drawn to the screen.
   */
   Sprite* sprite_;

};

#endif // ifndef ASCIIMATION_H_INCLUDED
