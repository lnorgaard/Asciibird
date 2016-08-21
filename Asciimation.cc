/**
 * \file Asciimation.cc
 * \author cs70 Provided Code and Lee Norgaard
 *
 * \brief Implements the Asciimation class
 *
 * \details Takes a sprite and shows the asciimation
 *
 */

#include "Asciimation.h"
#include "Sprite.h"

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <random>

using std::cout;
using std::endl;

/**
 * \brief shows the Asciimation
 * 
 * \details Initializes the screen for ncurses, then repeatedly 
 *      updates the screen until the user exits by pressing 'q'.
 */
void Asciimation::show() {

  const int PAUSE_TIME_IN_MICROSECONDS = 60000;

  // Initialize the screen
  initscr();

  // Don't echo characters entered by the user
  noecho();

  // Make the cursor invisible
  curs_set(0);

  // Tell ncurses not to block waiting for user input on getch() calls.
  nodelay(stdscr, TRUE);

  // We're not using the cursor, so tell ncurses to leave it wherever our
  // updates happen to put it.
  leaveok(stdscr, TRUE);

  // Leave the cursor on the bottom line of the screen instead of scrolling
  // if one of our updates would put it off-screen.
  scrollok(stdscr, FALSE);

  // Show the asciimation by refreshing the screen with new data, every so often
  bool weShouldContinueDisplaying = true;

  while (weShouldContinueDisplaying) {
    // Call the function to prepare new display contents
    prepareBufferForDisplay();

    // Call the function to copy display contents to ncurses
    copyBufferToNcurses();

    // Draw the screen with ncurses
    refresh();

    // Sleep between updates
    usleep(PAUSE_TIME_IN_MICROSECONDS);

    // Check to see if the user has entered 'q' to quit yet
    const char ch = getch();
    if (ch == 'q') {
      weShouldContinueDisplaying = false;
    }
  }

  // Put the cursor back to beginning of the last row of the terminal, where
  // we expect it to be when the program exits.
  mvcur(0, COLS - 1, LINES - 1, 0);

  // Restore the saved shell terminal before exiting.
  endwin();
}

/**
 * \brief adds a sprite
 * 
 * \details Takes in a reference to a sprite and stores it in the appropriate 
 *        data member of the Asciimation object
 */
void Asciimation::addSprite1(Sprite* oneSprite) {
  obstacles[0] = oneSprite;
}
void Asciimation::addSprite2(Sprite* twoSprite) {
  obstacles[1] = twoSprite;
}
void Asciimation::addSprite3(Sprite* threeSprite) {
  obstacles[2] = threeSprite;
}
void Asciimation::addSprite4(Sprite* fourSprite) {
  obstacles[3] = fourSprite;
}
void Asciimation::addBird(Sprite* flappy) {
  flappy_ = flappy;
}
void Asciimation::createLibrary(std::string mid, std::string low, std::string high) {
  obstacleLibrary[0] = mid;
  obstacleLibrary[1] = low;
  obstacleLibrary[2] = high;
}

/**
 * \brief returns the height of the sprite
 */
size_t Asciimation::getSpriteHeight(Sprite* aSprite) {
  return aSprite->getHeight();
}

/**
 * \brief returns the width of the sprite
 */
size_t Asciimation::getSpriteWidth(Sprite* aSprite) {
  return aSprite->getWidth();
}

/**
 * \brief places characters into the buffer
 * 
 * \details clears the Asciimation's character buffer, then copies characters
 *        from the stored Sprite to the character buffer using the Sprite's 
 *        getCharAt member function. It should place each character at the 
 *        right spot in the Asciimation's character buffer.
 */
void Asciimation::prepareBufferForDisplay() {
  
 if (obstacles[0]->getScrolling()) {
   obstacles[0]->moveRight();
 }

 if (obstacles[1]->getScrolling()) {
   obstacles[1]->moveRight();
 }

 if (obstacles[2]->getScrolling()) {
   obstacles[2]->moveRight();
 }

 if (obstacles[3]->getScrolling()) {
   obstacles[3]->moveRight();
 }
 
  // loop through screen and clear all of screen buffer
  for (size_t i = 0; i < SCREEN_AREA; ++i) {
    // replace with empty char
    screenStored_[i] = ' '; 
  }
  
  // use for loops to insert the sprite into the buffer
  for (size_t spriteRow = 0; spriteRow < getSpriteHeight(obstacles[0]); ++spriteRow) {
    for (size_t spriteCol = 0; spriteCol < getSpriteWidth(obstacles[0]); ++spriteCol) {
      for (size_t i = 0; i < 4; ++i) {
  
        const size_t screenColCheck = obstacles[i]->getTopLeftCol() % SCREEN_WIDTH;
        if (screenColCheck == 0) {
          // change the sprite
          std::random_device rd;
          std::mt19937 gen(rd());
          std::uniform_int_distribution<> dis(0, 2);
          obstacles[i]->setString(obstacleLibrary[dis(gen)]);
        }
        // do math to get index in screenStored_ (used % to wrap around the screen)
        const size_t screenRow = (spriteRow + obstacles[i]->getTopLeftRow()) % SCREEN_HEIGHT;
        const size_t screenCol = (spriteCol + obstacles[i]->getTopLeftCol()) % SCREEN_WIDTH;
        const size_t indexIntoScreenBuffer = screenRow * SCREEN_WIDTH + screenCol;
        
        // place the character in the spot using getCharAt
        screenStored_[indexIntoScreenBuffer] = obstacles[i]->getCharAt(spriteRow, spriteCol);
        
      }
    }
  }

  // use for loops to insert the sprite into the buffer
  for (size_t spriteRow = 0; spriteRow < getSpriteHeight(flappy_); ++spriteRow) {
    for (size_t spriteCol = 0; spriteCol < getSpriteWidth(flappy_); ++spriteCol) {

        // do math to get index in screenStored_ (used % to wrap around the screen)
        const size_t screenRow = (spriteRow + flappy_->getTopLeftRow()) % SCREEN_HEIGHT;
        const size_t screenCol = (spriteCol + flappy_->getTopLeftCol()) % SCREEN_WIDTH;
        const size_t indexIntoScreenBuffer = screenRow * SCREEN_WIDTH + screenCol;
        
        // place the character in the spot using getCharAt
        screenStored_[indexIntoScreenBuffer] = flappy_->getCharAt(spriteRow, spriteCol);
        
    }
  }
} 

/**
 * \brief copies the current buffer contents to ncurses
 * 
 * \details loop through all of the characters in the character buffer and
 *        copy them to the right place on the screen, using the ncurses
 *        function mvaddch. mvaddch(r, c, char) puts the character char at
 *        row r, column c of the screen.
 */
void Asciimation::copyBufferToNcurses() {
  
  for (size_t screenRow = 0; screenRow < SCREEN_HEIGHT; ++screenRow) {
    for (size_t screenCol = 0; screenCol < SCREEN_WIDTH; ++screenCol) {
      
      size_t currentIndex = screenRow * SCREEN_WIDTH + screenCol;
      
      // display character at currentIndex to screen
      mvaddch(screenRow, screenCol, screenStored_[currentIndex]);
    }
  }
  
}
