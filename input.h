#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "./sprites.h"

int playerPosY = 0; /* The Y position of the player */
int playerPosX = 0; /* The X position of the player */
int currentDir = up; /* The current direction the player is facing */
int ammo = 30;

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
         if (playerPosY > 1) {
            erase_player(playerPosY, playerPosX, currentDir);
            playerPosY -= 1;
            currentDir = up;
            draw_player(playerPosY, playerPosX, currentDir);
         }

         else {
            erase_player(playerPosY, playerPosX, currentDir);
            currentDir = up;
            draw_player(playerPosY, playerPosX, currentDir);
         }
      }

      else if (input == 'd') {
         if (playerPosX < COLS -3) {
            erase_player(playerPosY, playerPosX, currentDir);
            playerPosX += 2;
            currentDir = right;
            draw_player(playerPosY, playerPosX, currentDir);
         }

         else {
            erase_player(playerPosY, playerPosX, currentDir);
            currentDir = right;
            draw_player(playerPosY, playerPosX, currentDir);
         }
      }

      else if (input == 'a') {
         if (playerPosX > 2) {
            erase_player(playerPosY, playerPosX, currentDir);
            playerPosX -= 2;
            currentDir = left;
            draw_player(playerPosY, playerPosX, currentDir);
         }

         else {
            erase_player(playerPosY, playerPosX, currentDir);
            currentDir = left;
            draw_player(playerPosY, playerPosX, currentDir);
         }
      }

      else if (input == 's') {
         if (playerPosY < LINES -3) {
            erase_player(playerPosY, playerPosX, currentDir);
            playerPosY += 1;
            currentDir = down;
            draw_player(playerPosY, playerPosX, currentDir);
         }

         else {
            erase_player(playerPosY, playerPosX, currentDir);
            currentDir = down;
            draw_player(playerPosY, playerPosX, currentDir);
         }
      }

      else if (input == 32 && ammo > 0) {
         int missilePosY = playerPosY;
         int missilePosX = playerPosX;
         char missileChar[7];

         switch (currentDir) {
            case up: missilePosY -= 2; strcpy(missileChar, "▗▖");
                     break;

            case right: missilePosX += 3;
                     break;

            case left: missilePosX -= 2;
                     break;

            case down: missilePosY += 3; strcpy(missileChar, "▝▘");
                     break;
         }

         if (currentDir == up) {
            move(missilePosY, missilePosX);

            for (; missilePosY > 0; missilePosY--) {
               move(missilePosY, missilePosX);
               printw(missileChar);
               refresh();
               system("sleep 0.001s");
               move(missilePosY, missilePosX);
               printw("  ");
            }
         }

         else if (currentDir == right) {
            for (; missilePosX < COLS; missilePosX += 2) {
               move(missilePosY, missilePosX);
               MISSILE_RIGHT(missilePosY, missilePosX);
               refresh();
               system("sleep 0.001s");
               move(missilePosY, missilePosX);
               MISSILE_RIGHT_ERASE(missilePosY, missilePosX);
            }
         }

         else if (currentDir == left) {
            for (; missilePosX > 0; missilePosX -= 2) {
               move(missilePosY, missilePosX);
               MISSILE_LEFT(missilePosY, missilePosX);
               refresh();               
               system("sleep 0.001s");
               move(missilePosY, missilePosX);
               MISSILE_LEFT_ERASE(missilePosY, missilePosX);
            }
         }

         else if (currentDir == down) {
            move(missilePosY, missilePosX);
            printw(missileChar);            

            for (; missilePosY < LINES; missilePosY++) {
               move(missilePosY, missilePosX);
               printw(missileChar);
               refresh();
               system("sleep 0.001s");
               move(missilePosY, missilePosX);
               printw("  ");
            }
         }

         ammo -= 1;
      }      

      if (ammo <= 0) {
         attrset(COLOR_PAIR(2));
         draw_player(playerPosY, playerPosX, currentDir);
         refresh();
      }
   }
}

#endif
