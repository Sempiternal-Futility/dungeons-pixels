#ifndef ENEMY_H
#define ENEMY_H

#include <stdlib.h>
#include "./sprites.h"

struct enemyPos {
   int posY;
   int posX;
};

struct enemyPos enemy1;
struct enemyPos enemy2;

void *move_enemy()
{
   while (playerPosY != enemy1.posY)
   {
      while (playerPosX != enemy1.posX)
      {
         erase_enemy(enemy1.posY, enemy1.posX);

         if (enemy1.posY < LINES -2 && enemy1.posY >= 3) {
            if (playerPosY > enemy1.posY) {
               enemy1.posY += 1;
            }

            else if (playerPosY < enemy1.posY) {
               enemy1.posY -= 1;
            }
         }

         if (enemy1.posX < COLS -2 && enemy1.posX >= 3) {
            if (playerPosX > enemy1.posX) {
               enemy1.posX += 1;
            }

            else if (playerPosX < enemy1.posX) {
               enemy1.posX -= 1;
            }
         }

         draw_enemy(enemy1.posY, enemy1.posX);
         refresh();

         if ((playerPosY == enemy1.posY && playerPosX == enemy1.posX)
         || (playerPosY == enemy1.posY && playerPosX +1 == enemy1.posX)
         || (playerPosY == enemy1.posY && playerPosX -1 == enemy1.posX)
         || (playerPosY == enemy1.posY && playerPosX +2 == enemy1.posX)
         || (playerPosY == enemy1.posY && playerPosX -2 == enemy1.posX))
         {
            gameover_scr();
            break;
         }
      }
   }

   return (void *) 0;
}

#endif
