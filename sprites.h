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

#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

int playerPosY = 0; /* The Y position of the player */
int playerPosX = 0; /* The X position of the player */
bool game_over = false; /* If the player dies, this becomes true */

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

/* Draws the enemy sprite */
void draw_enemy(int y, int x)
{
   attrset(ENEMY_COLOR);
   move(y, x);
   printw("██");
   attrset(DEFAULT_COLOR);
   system("sleep 0.1s");
}

/* Erases the enemy sprite */
void erase_enemy(int y, int x)
{
   move(y, x);
   printw("  ");
}

/* Refreshes and draws the HUD */
void update_hud(int ammo, int kills)
{
      move(LINES -1, 1);
      printw("   ");
      move(LINES -1, 1);
      printw("%d", ammo);

      move(LINES -1, COLS -1);
      printw("   ");
      move(LINES -1, COLS -3);
      printw("%d", kills);
}

void gameover_scr()
{
   clear();
   move(LINES /2, (COLS /2) -4);
   printw("GAME OVER");
   game_over = true;
}

#endif
