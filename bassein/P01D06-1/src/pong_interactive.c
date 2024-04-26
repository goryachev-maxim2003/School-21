#include <math.h>
#include <ncurses.h>
#include <unistd.h>

#define LEFT_WALL 0
#define RIGHT_WALL 79
#define UP_WALL 0
#define DOWN_WALL 24
#define CENTER_WALL 40
#define WIN_SCORE 21

#define LHS_ROCKET_X 2
#define RHS_ROCKET_X 77
#define INITIAL_Y 12
#define INITIAL_BALL_X 30

void field_drawer(int lhs_racket_pos, int rhs_racket_pos, int ball_pos_x, int ball_pos_y, int lhs_points,
                  int rhs_points);               //функция отрисовки поля
int racket_changer(char direction, int racket);  //функция изменения положения ракетки
void print_result(int lhs_points);               //функция вывода результата

int main() {
    // main game code
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, 1);
    int lhs_points = 0, rhs_points = 0,
        who_score = 1;  // 0 - левый забил, 1 - правый забил //очки левого и правого игрока
    while (lhs_points != WIN_SCORE && rhs_points != WIN_SCORE) {  //Новый раунд
        //начальные положения правой и левой ракетки и мяча
        int lhs_racket_pos = INITIAL_Y, rhs_racket_pos = INITIAL_Y, ball_pos_y = INITIAL_Y;
        //начальные положения мяча и его скорость в заивисимости от счета
        int ball_pos_x = who_score ? INITIAL_BALL_X : RIGHT_WALL - INITIAL_BALL_X;
        int velocity_x = who_score ? -1 : 1, velocity_y = who_score ? -1 : 1;
        int ticks = 0;
        do {
            field_drawer(lhs_racket_pos, rhs_racket_pos, ball_pos_x, ball_pos_y, lhs_points, rhs_points);
            char input = getch();
            ++ticks;
            //Изменение позиции рокетки
            if (input == 'A' || input == 'Z')
                lhs_racket_pos = racket_changer(input, lhs_racket_pos);
            else if (input == 'K' || input == 'M')
                rhs_racket_pos = racket_changer(input, rhs_racket_pos);
            //Смена координат мяча
            if (ticks % 10 == 0) {
                ball_pos_x += velocity_x;
                ball_pos_y += velocity_y;
                if (ball_pos_x == RIGHT_WALL) {  //Левый забил
                    lhs_points++;
                    who_score = 0;
                } else if (ball_pos_x == LEFT_WALL) {  //Правый забил
                    rhs_points++;
                    who_score = 1;
                } else if (ball_pos_y == UP_WALL + 1 || ball_pos_y == DOWN_WALL - 1)  //Стена
                {
                    velocity_y *= -1;
                }
                //Отбилось от рокетки (Если наслоение, то возвращаем мяч обратно + меняем velocity)
                else if ((ball_pos_x == LHS_ROCKET_X && ball_pos_y >= lhs_racket_pos - 1 &&
                          ball_pos_y <= lhs_racket_pos + 1) ||
                         (ball_pos_x == RHS_ROCKET_X && ball_pos_y >= rhs_racket_pos - 1 &&
                          ball_pos_y <= rhs_racket_pos + 1)) {
                    //Возврачаем мяч обратно и сдвигаем в нужном направлении
                    ball_pos_x -= 2 * velocity_x;  //эквивалентно x-=v_x; y-=v_y(возвращение назад); v_x*=-1
                                                   // x+=v_x; y+=v_y (cдвиг)
                    velocity_x *= -1;
                }
            }
            usleep(10000);
        } while (ball_pos_x != LEFT_WALL && ball_pos_x != RIGHT_WALL);  //Пока не гол
    }

    print_result(lhs_points);
    halfdelay(60);
    getch();
    endwin();
    return 0;
}

int racket_changer(char direction, int racket) {
    if ((direction == 'A' || direction == 'K') && racket > 2)
        --racket;
    else if ((direction == 'Z' || direction == 'M') && racket < 22)
        ++racket;
    return racket;
}

void field_drawer(int lhs_racket_pos, int rhs_racket_pos, int ball_pos_x, int ball_pos_y, int lhs_points,
                  int rhs_points) {
    //отрисовка основного поля
    for (int y = UP_WALL - 2; y < DOWN_WALL + 1; ++y) {
        for (int x = LEFT_WALL; x < RIGHT_WALL + 1; ++x) {
            if (x == ball_pos_x && y == ball_pos_y)
                mvaddch(y + 2, x, '@');
            else if (y == UP_WALL || y == DOWN_WALL || y == UP_WALL - 2)
                mvaddch(y + 2, x, '-');
            else if (x == CENTER_WALL || x == LEFT_WALL || x == RIGHT_WALL ||
                     (x == LHS_ROCKET_X &&
                      (y == lhs_racket_pos - 1 || y == lhs_racket_pos || y == lhs_racket_pos + 1)) ||
                     (x == RHS_ROCKET_X &&
                      (y == rhs_racket_pos - 1 || y == rhs_racket_pos || y == rhs_racket_pos + 1)))
                mvaddch(y + 2, x, '|');
            else if ((x == CENTER_WALL - 3 && y == UP_WALL - 1) ||
                     (x == CENTER_WALL + 2 && y == UP_WALL - 1)) {
                if (x == CENTER_WALL - 3)
                    printw("%.2d", lhs_points);
                else if (x == CENTER_WALL + 2)
                    printw("%.2d", rhs_points);
                ++x;
            } else
                mvaddch(y + 2, x, ' ');
        }
    }
}
void print_result(int lhs_points) {
    clear();
    printw("\nCongratulations!\n");
    if (lhs_points == WIN_SCORE) {
        printw("Left player won!");
    } else {
        printw("Right player won!");
    }
    refresh();
}