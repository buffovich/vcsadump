#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(int argc, char **argv) {
  int fg, bg;

  struct {
    char *name;
    int color;
  } NC[] = {
    { "Bk", COLOR_BLACK },
    { "Rd", COLOR_RED },
    { "Gr", COLOR_GREEN },
    { "Ye", COLOR_YELLOW },
    { "Bl", COLOR_BLUE },
    { "Mg", COLOR_MAGENTA },
    { "Cy", COLOR_CYAN },
    { "Wh", COLOR_WHITE }
  };
  
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  for (bg=0; bg<16; bg++) {
    move(bg,0);
    for (fg=0; fg<16; fg++) {
      int attr;
      int c=((bg & 7) << 3) | (fg & 7);
      init_pair(c, NC[fg&7].color, NC[bg&7].color);
      attr=COLOR_PAIR(c);
      if (fg & 8) attr |= A_BOLD;
      if (bg & 8) attr |= A_UNDERLINE;
      wattron(stdscr, attr);
      waddstr(stdscr, NC[fg&7].name);
      waddstr(stdscr, NC[bg&7].name);
      wattroff(stdscr, attr);
    }
  }
  move(bg, 0);
  wrefresh(stdscr);

  getch();

  endwin();
  return 0;
}
