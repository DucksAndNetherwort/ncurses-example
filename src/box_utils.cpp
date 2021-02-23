#include "box_utils.hpp"

void create_box(BOX* p_win, bool flag) {
  int x = p_win->startx;
  int y = p_win->starty;
  int w = p_win->width;
  int h = p_win->height;

  if (flag == true) {
    mvaddch(y, x, p_win->border.tl);
    mvaddch(y, x + w, p_win->border.tr);
    mvaddch(y + h, x, p_win->border.bl);
    mvaddch(y + h, x + w, p_win->border.br);
    mvhline(y, x + 1, p_win->border.ts, w - 1);
    mvhline(y + h, x + 1, p_win->border.bs, w - 1);
    mvvline(y + 1, x, p_win->border.ls, h - 1);
    mvvline(y + 1, x + w, p_win->border.rs, h - 1);
  } else {
    for (int j = y; j <= y + h; ++j) {
      for (int i = x; i <= x + w; ++i) {
        mvaddch(j, i, ' ');
      }
    }
  }
  refresh();
}

void print_box_params(BOX* p_win) {
#ifdef _DEBUG
  mvprintw(25, 0, "%d %d %d %d", p_win->startx, p_win->starty, p_wni->width,
           p_win->height);

  refresh();
#endif
}

void init_box_params(BOX* p_win) {
  p_win->height = 2;
  p_win->width = 4;

/* 
 * This seems to be broken when started on repl.it. Box starts in top left corner, only partially visible.
  p_win->starty = (LINES - p_win->height) / 2;
  p_win->startx = (COLS - p_win->width) / 2;
*/
  p_win->starty = 3;
  p_win->startx = 3;


  p_win->border.ls = '|';
  p_win->border.rs = '|';
  p_win->border.ts = '-';
  p_win->border.bs = '-';
  p_win->border.tl = '+';
  p_win->border.tr = '+';
  p_win->border.bl = '+';
  p_win->border.br = '+';
}
