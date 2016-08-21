/* Sprite.h
   =========
   Author: cs70 and Lee Norgaard
   Interface definition for the Sprite class.

*/

#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED 1;

#include <fstream>
#include <iostream>
#include <string>

/**
 * \class Sprite
 * \brief Holds the contents of a single sprite
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, along
 * with the sprite's top-left corner.
 *
 * \remarks
 * The implemented code works for any size sprite.
 *
 */
class Sprite {
public:
  /**
   * \brief Default constructor
   * 
   * \details
   * Takes in an image file, two size_t's representing the Sprite's 
   * top-left corner row and column, and a bool representing whether
   * the Sprite should scroll
   */
  Sprite(const std::string& imageFile, size_t topLeftCornerRow, 
    size_t topLeftCornerCol, const bool shouldScroll);  
  
   /**
   * \brief Deconstructor
   */
   ~Sprite();
  
   /* 
   * \brief A char* that points to the char that represent the sprite
   */
   char* spriteStored_;

   /*
   * \brief Return the Sprite's top-left corner row
   */
   size_t getTopLeftRow();
   
   /*
   * \brief Return the Sprite's top-left corner column
   */
   size_t getTopLeftCol();
   
   /*
   * \brief Get the character at the desired spot
   *
   * \details
   * Returns the col-th character in the row-th row of the Sprite’s 
   * character array
   */
   char getCharAt(const size_t row, const size_t col);
   
   /*
   * \brief Gets the value of the shouldScroll_ data member
   */
   bool getScrolling();

   /*
   * \brief Changes the shouldScroll_ data member
   */
   void setScrolling(bool shouldScroll);
   
   /*
   * \brief moves the sprite to the right
   *
   * \details
   * moves the sprite one column to the right every time
   * it's called regardless of whether the shouldScroll_
   * data member is set
   */
   void moveRight();
   
   /*
   * \brief moves the bird up
   */
   void moveUp();

   /*
   * \brief moves the bird down
   */
   void moveDown();

   /**
    * \brief returns the height of the sprite
    */
   size_t getHeight();
   
   /**
    * \brief returns the width of the sprite
    */
   size_t getWidth();

   /**
   * \brief Changes the sprite file
   */
   void setString(const std::string& imageFile);
   
   
private:
   /*
   * \details
   * A boolean data member that is true when the sprite should scroll
   * and false otherwise
   */
   bool shouldScroll_;
   
   /* 
   * These two variables save the coordinates of the sprite
   * (the location of the top left corner of the sprite on
   * the image)
   */
   size_t topLeftCornerRow_;
   size_t topLeftCornerColumn_;
   
   // These variables store the height and width of the sprite, in characters
   size_t spriteHeight_;
   size_t spriteWidth_;

};

#endif // ifndef SPRITE_H_INCLUDED
