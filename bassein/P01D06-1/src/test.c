#include <ncurses.h>

int main(void){
    
    int c;
    int y = 11, x = 11;
    initscr();
    keypad(stdscr,1);
    noecho();
    curs_set(0);
    do
    {
        clear();
        if (c == 65) y--; //A
        else if (c == 90) y++; //Z
        else if (c == 75) x--; //K
        else if (c == 77) x++; //M
        // if (c == KEY_UP) y--;
        // else if (c == KEY_DOWN) y++;
        // else if (c == KEY_LEFT) x--;
        // else if (c == KEY_RIGHT) x++;
        mvaddch(y,x,'@');
    } while ((c = getch()) != 27); //Esc

    
    endwin();
    
    return 0;
}