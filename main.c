#include <ncurses.h>
#include <locale.h>
#include "./sprites.h"
#include "./input.h"
#include "enemy.h"

int main()
{
   setlocale(LC_ALL, "");
   initscr();
   curs_set(0);
   noecho();

   start_color();
   init_pair(1, COLOR_WHITE, COLOR_BLACK);
   init_pair(2, COLOR_RED, COLOR_BLACK);
   init_pair(3, COLOR_BLUE, COLOR_BLACK);
   attrset(DEFAULT_COLOR);

   move(LINES -1, 1);
   printw("  ");
   move(LINES -1, 1);
   printw("%d", ammo);

   init_pos();
   draw_enemy(enemy1.posY, enemy1.posX);
   draw_enemy(enemy2.posY, enemy2.posX);
   draw_player(playerPosY, playerPosX, currentDir);
   move_player();

   endwin();
   return 0;
}
