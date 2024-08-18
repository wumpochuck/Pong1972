// ----------------Ping Pong------------------//
//     Compile by using this command:        //
// gcc -Wall -Werror -Wextra -std=c11 <file> //
//-------------------------------------------//

#include <stdio.h>

int sides_collision(int ball_change_y, int future_coord_y, int height);
int goal_check(int ball_x, int ball_y, int score1, int score2, int future_coord_x, int width);
void draw_field(int height, int width, int racket1_1, int racket1_2, int racket1_3, int racket2_1,
                int racket2_2, int racket2_3, int ball_x, int ball_y, int score1, int score2);
int rackets_collision(int ball_change_x, int future_coord_x, int future_coord_y, int racket1_1, int racket1_2,
                      int racket1_3, int racket2_1, int racket2_2, int racket2_3);
int input_check(int racket1_1, int racket1_3, int racket2_1, int racket2_3);

int main() {
    int width = 80, height = 25;
    int racket1_1 = 12, racket1_2 = 13, racket1_3 = 14;
    int racket2_1 = 12, racket2_2 = 13, racket2_3 = 14;
    int ball_change_x = 1, ball_change_y = 1, ball_x = 40, ball_y = 13;
    int score1 = 0, score2 = 0;
    char input;
    int flag = 1;
    while (flag) {
        int future_coord_x = ball_x + ball_change_x;
        int future_coord_y = ball_y + ball_change_y;
        int temp = sides_collision(ball_change_y, future_coord_y, height);
        ball_change_y = temp;
        temp = rackets_collision(ball_change_x, future_coord_x, future_coord_y, racket1_1, racket1_2,
                                 racket1_3, racket2_1, racket2_2, racket2_3);
        ball_change_x = temp;
        temp = goal_check(ball_x, ball_y, score1, score2, future_coord_x, width);
        if (temp == 0) break;
        ball_x = temp / 1000000;
        ball_y = temp % 1000000 / 10000;
        score1 = temp % 10000 / 100;
        score2 = temp % 100;
        ball_x += ball_change_x;
        ball_y += ball_change_y;
        draw_field(height, width, racket1_1, racket1_2, racket1_3, racket2_1, racket2_2, racket2_3, ball_x,
                   ball_y, score1, score2);
        while (scanf("%c", &input) && input != '\n') {
            if (input == 'a' && racket1_1 != 1) {
                racket1_1--;
                racket1_2--;
                racket1_3--;
            } else if (input == 'z' && racket1_3 != 23) {
                racket1_1++;
                racket1_2++;
                racket1_3++;
            } else if (input == 'k' && racket2_1 != 1) {
                racket2_1--;
                racket2_2--;
                racket2_3--;
            } else if (input == 'm' && racket2_3 != 23) {
                racket2_1++;
                racket2_2++;
                racket2_3++;
            } else if (input == 'q')
                flag = 0;
        }
        printf("\e[1;1H\e[2J");
    }
    return 0;
}

int sides_collision(int ball_change_y, int future_coord_y, int height) {
    if (future_coord_y == 0) {
        ball_change_y = 1;
    }

    else if (future_coord_y == height - 1) {
        ball_change_y = -1;
    }

    return ball_change_y;
}

int rackets_collision(int ball_change_x, int future_coord_x, int future_coord_y, int racket1_1, int racket1_2,
                      int racket1_3, int racket2_1, int racket2_2, int racket2_3) {
    if (future_coord_x == 3 &&
        (future_coord_y == racket1_1 || future_coord_y == racket1_2 || future_coord_y == racket1_3)) {
        ball_change_x = 1;
    }

    else if (future_coord_x == 76 &&
             (future_coord_y == racket2_1 || future_coord_y == racket2_2 || future_coord_y == racket2_3)) {
        ball_change_x = -1;
    }

    return ball_change_x;
}

int goal_check(int ball_x, int ball_y, int score1, int score2, int future_coord_x, int width) {
    int temp;

    if (future_coord_x == 0) {
        score2++;
        ball_x = 40;
        ball_y = 13;
    }

    if (future_coord_x == width - 1) {
        score1++;
        ball_x = 40;
        ball_y = 13;
    }

    temp = ball_x * 1000000 + ball_y * 10000 + score1 * 100 + score2;

    if (score1 == 21 || score2 == 21) {
        if (score1 > score2) {
            printf("Player 1 wins!\n");
            temp = 0;
        } else {
            printf("Player 2 wins!\n");
            temp = 0;
        }
    }

    return temp;
}

void draw_field(int height, int width, int racket1_1, int racket1_2, int racket1_3, int racket2_1,
                int racket2_2, int racket2_3, int ball_x, int ball_y, int score1, int score2) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == height - 1) {
                printf("_");
            } else if (j == 0 || j == width - 1) {
                printf("|");
            } else if ((i == racket1_1 || i == racket1_2 || i == racket1_3) && j == 3) {
                printf("[");
            } else if ((i == racket2_1 || i == racket2_2 || i == racket2_3) && j == 76) {
                printf("]");
            } else if (j == ball_x && i == ball_y) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Player 1 %23c Score %02d : %02d %23c Player 2\n", ' ', score1, score2, ' ');
}