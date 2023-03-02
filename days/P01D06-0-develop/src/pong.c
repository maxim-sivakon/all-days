#include <stdio.h>

void moveRocket(int *rocket_1_Y, int *rocket_2_Y, char key);
void moveBall(int *ball1_x, int *ball1_y, int *d_X, int *d_Y, const int *rocket_1_Y, const int *rocket_2_Y);
void screenDraw(const int *rocket_1_Y, const int *rocket_2_Y, const int *ball1_x, const int *ball1_y,
                int *scPlayer1, int *scPlayer2);
int checkScore(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y);
void clearScreen(void);

int main(void) {
    int rocket_1_Y = 19;
    int rocket_2_Y = 5;

    int ball_X = 41;
    int ball_Y = 13;
    int d_X = -1;
    int d_Y = 1;

    int score_Player_1 = 0;
    int score_Player_2 = 0;
    char input_key;

    while (1) {
        clearScreen();
        screenDraw(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_Player_1, &score_Player_2);

        if ((input_key = getchar()) == 'a' || input_key == 'z' || input_key == 'k' || input_key == 'm' ||
            input_key == ' ') {
            moveRocket(&rocket_1_Y, &rocket_2_Y, input_key);
            moveBall(&ball_X, &ball_Y, &d_X, &d_Y, &rocket_1_Y, &rocket_2_Y);
            if (checkScore(&score_Player_1, &score_Player_2, &ball_X, &ball_Y)) {
                break;
            }
        }
    }
    return 0;
}

void moveRocket(int *rocket_1_Y, int *rocket_2_Y, char key) {
    switch (key) {
        case 'a':
            ((*rocket_1_Y - 2) != 0) ? (*rocket_1_Y -= 1) : *rocket_1_Y;
            break;
        case 'z':
            ((*rocket_1_Y + 2) != 27 - 1) ? (*rocket_1_Y += 1) : *rocket_1_Y;
            break;
        case 'k':
            ((*rocket_2_Y - 2) != 0) ? (*rocket_2_Y -= 1) : *rocket_2_Y;
            break;
        case 'm':
            ((*rocket_2_Y + 2) != 27 - 1) ? (*rocket_2_Y += 1) : *rocket_2_Y;
            break;
    }
}

void screenDraw(const int *rocket_1_Y, const int *rocket_2_Y, const int *ball1_x, const int *ball1_y,
                int *scPlayer1, int *scPlayer2) {
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 82; ++x) {
            if ((y == 0 || y == 3 - 1) && (x != 0 && x != 82 - 1)) {
                printf("-");
            } else if (x == 0 || x == 82 - 1) {
                printf("|");
            } else if (x == 5) {
                printf("Press \'Control + c\' to exit");
            } else if (x == 15) {
                printf("Player one: %02d | Player two: %02d", *scPlayer1, *scPlayer2);
            } else if (y == 1 && x < 82 - 57) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < 27; ++y) {
        for (int x = 0; x < 82; ++x) {
            if ((x == 2 && (y == *rocket_1_Y - 1 || y == *rocket_1_Y || y == *rocket_1_Y + 1)) ||
                (x == 79 && (y == *rocket_2_Y - 1 || y == *rocket_2_Y || y == *rocket_2_Y + 1)) ||
                ((x == 0 || x == 82 - 1 || x == 82 / 2) && (y != 0 && y != 27 - 1))) {
                printf("|");
            } else if (x == *ball1_x && y == *ball1_y) {
                printf("o");
            } else if ((y == 0 || y == 27 - 1) && x != 0 && x != 82 - 1) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void moveBall(int *ball1_x, int *ball1_y, int *d_X, int *d_Y, const int *rocket_1_Y, const int *rocket_2_Y) {
    if (*ball1_y == 1 || *ball1_y == 27 - 2) {
        *d_Y = -(*d_Y);
    }
    if (*ball1_x == 2 + 1 &&
        (*ball1_y == *rocket_1_Y - 1 || *ball1_y == *rocket_1_Y || *ball1_y == *rocket_1_Y + 1)) {
        *d_X = -(*d_X);
    }
    if (*ball1_x == 79 - 1 &&
        (*ball1_y == *rocket_2_Y - 1 || *ball1_y == *rocket_2_Y || *ball1_y == *rocket_2_Y + 1)) {
        *d_X = -*(d_X);
    }

    *ball1_y += *d_Y;
    *ball1_x += *d_X;
}

int checkScore(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y) {
    if (*ball1_x < 2) {
        *scPlayer2 += 1;
        *ball1_x = 41;
        *ball1_y = 13;
    }
    if (*ball1_x > 82 - 3) {
        *scPlayer1 += 1;
        *ball1_x = 41;
        *ball1_y = 13;
    }
    if (*scPlayer1 == 21) {
        printf("\n\tCONGRATULATION!!! PLAYER ONE IS WON BY %d TO %d!", *scPlayer1, *scPlayer2);
        return 1;
    } else if (*scPlayer2 == 21) {
        printf("\n\tCONGRATULATION!!! PLAYER TWO IS WON BY %d TO %d!", *scPlayer2, *scPlayer1);
        return 1;
    }
    return 0;
}

void clearScreen(void) { printf("\33c\e[3J"); }