#include <math.h>
#include <stdio.h>

#define LEFT_WALL 0
#define RIGHT_WALL 79
#define UP_WALL 0
#define DOWN_WALL 24
#define CENTER_WALL 40

#define LHS_ROCKET_X 2
#define RHS_ROCKET_X 77
#define INITIAL_Y 12
#define INITIAL_BALL_X 30

void field_drawer(int lhs_racket_pos, int rhs_racket_pos, int ball_pos_x, int ball_pos_y, int lhs_points,
                  int rhs_points);               //функция отрисовки поля
int input_check(char key, char next);            //функция проверки ввода
int racket_changer(char direction, int racket);  //функция изменения положения ракетки
void print_result(int lhs_points);               //функция вывода результата

int main() {
    // main game code
    int lhs_points = 0, rhs_points = 0,
        who_score = 1;  // 0 - левый забил, 1 - правый забил //очки левого и правого игрока
    while (lhs_points != 21 && rhs_points != 21) {  //Новый раунд
        int lhs_racket_pos = INITIAL_Y, rhs_racket_pos = INITIAL_Y,
            ball_pos_y = INITIAL_Y;  //начальные положения правой и левой ракетки и мяча
        int ball_pos_x =
            who_score ? INITIAL_BALL_X
                      : RIGHT_WALL -
                            INITIAL_BALL_X;  //начальные положения мяча и его скорость в заивисимости от счета
        int velocity_x = who_score ? -1 : 1, velocity_y = who_score ? -1 : 1;
        field_drawer(lhs_racket_pos, rhs_racket_pos, ball_pos_x, ball_pos_y, lhs_points, rhs_points);
        while (ball_pos_x != LEFT_WALL && ball_pos_x != RIGHT_WALL) {  //Пока не гол
            char input = getchar(), next = ' ';
            if (input_check(input, next)) {
                printf("Неверный ввод!\n");
                continue;
            }
            //Изменение позиции рокетки
            if (input == 'A' || input == 'Z')
                lhs_racket_pos = racket_changer(input, lhs_racket_pos);
            else if (input == 'K' || input == 'M')
                rhs_racket_pos = racket_changer(input, rhs_racket_pos);
            //Смена координат мяча
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
                ball_pos_x -= 2 * velocity_x;  //эквивалентно x-=v_x; y-=v_y(возвращение назад);   v_x*=-1;
                                               // x+=v_x; y+=v_y (cдвиг)
                velocity_x *= -1;
            }
            //такт отрисовки поля
            field_drawer(lhs_racket_pos, rhs_racket_pos, ball_pos_x, ball_pos_y, lhs_points, rhs_points);
        }
    }

    print_result(lhs_points);
    return 0;
}

int input_check(char key, char next) {
    int err = 0;
    if (key == '\n')  //проверка на пустую строку
        ++err;
    else  //строка непустая
    {
        while ((next = getchar()) != '\n')  //чистка буфера
            ++err;
        //Проверка на ввод
        if (key != 'A' && key != 'Z' && key != 'K' && key != 'M' && key != ' ') ++err;
    }
    return err;
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
                putchar('@');
            else if (y == UP_WALL || y == DOWN_WALL || y == UP_WALL - 2)
                putchar('-');
            else if (x == CENTER_WALL || x == LEFT_WALL || x == RIGHT_WALL ||
                     (x == LHS_ROCKET_X &&
                      (y == lhs_racket_pos - 1 || y == lhs_racket_pos || y == lhs_racket_pos + 1)) ||
                     (x == RHS_ROCKET_X &&
                      (y == rhs_racket_pos - 1 || y == rhs_racket_pos || y == rhs_racket_pos + 1)))
                putchar('|');
            else if ((x == CENTER_WALL - 3 && y == UP_WALL - 1) ||
                     (x == CENTER_WALL + 2 && y == UP_WALL - 1)) {
                if (x == CENTER_WALL - 3)
                    printf("%.2d", lhs_points);
                else if (x == CENTER_WALL + 2)
                    printf("%.2d", rhs_points);
                ++x;
            } else
                putchar(' ');
        }
        putchar('\n');
    }
}
void print_result(int lhs_points) {
    printf("Congratulations!\n");
    if (lhs_points == 21) {
        printf("Left player won!");
    } else {
        printf("Right player won!");
    }
}