#include <ncurses.h>
#include <locale.h>
#include <pthread.h>
#include "./sprites.h"
#include "./input.h"
#include "./enemy.h"

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

   init_pos();
   update_hud(ammo, kills);

   pthread_t enemyThread;
   pthread_create(&enemyThread, NULL, move_enemy, NULL);

   system("sleep 0.2s");

   draw_enemy(enemy1.posY, enemy1.posX);
   draw_enemy(enemy2.posY, enemy2.posX);
   draw_player(playerPosY, playerPosX, currentDir);
   system("xset r rate 1 20");
   move_player();

   system("xset r rate");
   endwin();
   return 0;
}
