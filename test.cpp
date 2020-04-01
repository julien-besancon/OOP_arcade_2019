#include <ncurses.h>
#include <curses.h>
#include <string>

int menu_action()
{
    int i = 1;
    int command = getch();

    switch (command) {
    case KEY_UP: i++;
        break;
    case KEY_DOWN: i--;
        break; 
    }
    if (i < 1) 
        i = 1;
    if (i > 4)
        i = 4;
    switch (i) {
    case 1:
        mvprintw(20, 25, "-->");
        break;
    case 2:
        mvprintw(40, 25, "-->");
        break;
    case 3:
        mvprintw(60, 25, "-->");
        break;
    case 4:
        mvprintw(80, 25, "-->");
        break;
    }
    return (i);
}

void display_menu()
{
    mvprintw(20, 30, "RESUME");
    mvprintw(40, 30, "NEXT GAME");
    mvprintw(60, 30, "PREVIOUS GAME");
    mvprintw(80, 30, "EXIT");
    refresh();
}

int main(int ac, char **av)
{
    initscr();
    while (1) {
    int i = menu_action();
    if (i != 0)
        return i;
    display_menu();
    }
}
