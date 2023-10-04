/* constains functions that draws sprites to screen */
#ifndef SPRITES_H
#define SPRITES_H

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

#endif