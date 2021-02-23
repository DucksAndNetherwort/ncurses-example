#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>

#include "box_utils.hpp"

#ifndef CTRL
#define CTRL(x) ((x)&0x1f)
#endif

int main(int argc, char* argv[]) {
  BOX win;
  bool quit = false;

  init_box_params(&win);
  print_box_params(&win);

  initscr();
  raw();
  start_color();
  cbreak();

  keypad(stdscr, true);
  noecho();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

 
  attron(COLOR_PAIR(1));
  printw("Press Ctrl-C or Q to exit; h,j,k, and l to move the box.");
  refresh();
  attroff(COLOR_PAIR(1));

  create_box(&win, true);

  while (!quit) {
    int ch = getch();
    switch (ch) {
      case 'q':
        quit = true;
        break;
      case CTRL('c'):
        quit = true;
        break;
      case 'j':
        create_box(&win, false);
        ++win.starty;
        create_box(&win, true);
        break;
      case 'h':
        create_box(&win, false);
        --win.startx;
        create_box(&win, true);
        break;
      case 'l':
        create_box(&win, false);
        ++win.startx;
        create_box(&win, true);
        break;
      case 'k':
        create_box(&win, false);
        --win.starty;
        create_box(&win, true);
        break;
    }
  }
  endwin();
  return 0;
}
