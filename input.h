#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>
#include "./sprites.h"

int playerPosY = 0; /* The Y position of the player */
int playerPosX = 0; /* The X position of the player */
int currentDir = up; /* The current direction the player is facing */

/* Sets the inital values for the global vars */
void initPos()
{
   playerPosX = COLS /2;
   playerPosY = LINES /2;
}

/* Handles player movement */
void move_player()
{
   char input = 0;

   while (input != 'q') {
      input = getch();

      if (input == 'w') {
         erase_player(playerPosY, playerPosX, currentDir);
         playerPosY -= 1;
         currentDir = up;
         draw_player(playerPosY, playerPosX, currentDir);
      }

      else if (input == 'd') {
         erase_player(playerPosY, playerPosX, currentDir);
         playerPosX += 2;
         currentDir = right;
         draw_player(playerPosY, playerPosX, currentDir);
      }

      else if (input == 'a') {
         erase_player(playerPosY, playerPosX, currentDir);
         playerPosX -= 2;
         currentDir = left;
         draw_player(playerPosY, playerPosX, currentDir);
      }

      else if (input == 's') {
         erase_player(playerPosY, playerPosX, currentDir);
         playerPosY += 1;
         currentDir = down;
         draw_player(playerPosY, playerPosX, currentDir);
      }
   }
}

#endif
