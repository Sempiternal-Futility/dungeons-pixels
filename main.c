#include <ncurses.h>
#include <locale.h>
#include "./sprites.h"
#include "./input.h"

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


   initPos();
   draw_enemy(enemy1.enemyPosY, enemy1.enemyPosX);
   draw_enemy(enemy2.enemyPosY, enemy2.enemyPosX);
   draw_player(playerPosY, playerPosX, currentDir);
   move_player();

   endwin();
   return 0;
}
