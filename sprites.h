/* constains functions that draws sprites to screen */
#ifndef SPRITES_H
#define SPRITES_H

#define DEFAULT_COLOR  COLOR_PAIR(1)
#define WARNING_COLOR  COLOR_PAIR(2)
#define ENEMY_COLOR    COLOR_PAIR(3)

#define MISSILE_RIGHT(y, x) (move(y, x), printw("▖"), move(y +1, x), printw("▘")) /* Shoots missile to the right direction */
#define MISSILE_RIGHT_ERASE(y, x) (move(y, x), printw(" "), move(y +1, x), printw(" ")) 
#define MISSILE_LEFT(y, x) (move(y, x), printw("▗"), move(y +1, x), printw("▝")) /* Shoots missile to the left direction */
#define MISSILE_LEFT_ERASE(y, x) (move(y, x), printw(" "), move(y +1, x), printw(" "))

#include <ncurses.h>

enum directions {
   up = 0,
   right = 1,
   left = 2,
   down = 3
};

void draw_player(int y, int x, int direction)
{
      move(y, x);
      printw("██");
      
      move(y +1, x);
      printw("██");

      if (direction == up) {
         move(y -1, x);
         printw("▗");

         move(y -1, x +1);
         printw("▖");
      }

      else if (direction == right) {
         move(y, x +2);
         printw("▖");

         move(y +1, x +2);
         printw("▘");
      }

      else if (direction == left) {
         move(y, x -1);
         printw("▗");

         move(y +1, x -1);
         printw("▝");
      }

      else if (direction == down) {
         move(y +2, x);
         printw("▝");

         move(y +2, x +1);
         printw("▘");
      }
}

void erase_player(int y, int x, int direction)
{
      move(y, x);
      printw("  ");
      
      move(y +1, x);
      printw("  ");

      if (direction == up) {
         move(y -1, x);
         printw(" ");

         move(y -1, x +1);
         printw(" ");
      }

      else if (direction == right) {
         move(y, x +2);
         printw(" ");

         move(y +1, x +2);
         printw(" ");
      }

      else if (direction == left) {
         move(y, x -1);
         printw(" ");

         move(y +1, x -1);
         printw(" ");
      }

      else if (direction == down) {
         move(y +2, x);
         printw(" ");

         move(y +2, x +1);
         printw(" ");
      }
}

void draw_enemy(int y, int x)
{
   attrset(ENEMY_COLOR);
   move(y, x);
   printw("██");
   attrset(DEFAULT_COLOR);
}

void erase_enemy(int y, int x)
{
   move(y, x);
   printw("  ");
}

#endif
