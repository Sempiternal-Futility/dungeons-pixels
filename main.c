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
   attrset(COLOR_PAIR(1));

   move(LINES -1, 1);
   printw("  ");
   move(LINES -1, 1);
   printw("%d", ammo);

   initPos();
   draw_player(playerPosY, playerPosX, currentDir);
   move_player();

   endwin();
   return 0;
}
