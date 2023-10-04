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

   initPos();
   draw_player(playerPosY, playerPosX, currentDir);
   move_player();

   endwin();
   return 0;
}
