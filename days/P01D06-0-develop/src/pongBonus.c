// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 82
#define HEIGHT 27
#define HEIGHT_SCOPE 3
#define ROCKET1_START_Y 19
#define ROCKET2_START_Y 5
#define ROCKET1_DEFAULT_X 2
#define ROCKET2_DEFAULT_X (WIDTH - 3)
#define BALL_START_X (WIDTH / 2)
#define BALL_START_Y (HEIGHT / 2)
#define START_INPUT_EXIT 5
#define START_INPUT_SCORE 15
#define NUMBER_SCORE_CHARACTERS 57
#define WINSCORE 21
#define TRUE 1
#define FALSE 0
#define SPEED 100 * 1000000  // microsec

void moveRocket(int *rocket_1_Y, int *rocket_2_Y, char key);
void moveBall(int *ball1_x, int *ball1_y, int *d_X, int *d_Y, const int *rocket_1_Y, const int *rocket_2_Y);
void screenDraw(const int *rocket_1_Y, const int *rocket_2_Y, const int *ball1_x, const int *ball1_y,
                int *scPlayer1, int *scPlayer2);
int checkScore(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y);
void clearScreen(void);

int main(void) {
    int rocket_1_Y = ROCKET1_START_Y;
    int rocket_2_Y = ROCKET2_START_Y;

    int ball_X = BALL_START_X;
    int ball_Y = BALL_START_Y;
    int d_X = -1;
    int d_Y = 1;

    int score_Player_1 = 0;
    int score_Player_2 = 0;
    char input_key;
    struct timespec tim1, tim2;
    tim1.tv_sec = 0;
    tim1.tv_nsec = SPEED;

    initscr();
    noecho();
    timeout(0);
    clearScreen();
    while (TRUE) {
        screenDraw(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_Player_1, &score_Player_2);
        system("/bin/stty raw");
        input_key = getch();
        system("/bin/stty cooked");
        if ((input_key = getchar()) == 'a' || input_key == 'z' || input_key == 'k' || input_key == 'm') {
            printf("\e[1;1H\e[2J\e[3J");  // clear stdin
            moveRocket(&rocket_1_Y, &rocket_2_Y, input_key);
            moveBall(&ball_X, &ball_Y, &d_X, &d_Y, &rocket_1_Y, &rocket_2_Y);
        }
        if (input_key == 'Q') {
            break;
        }
        if (checkScore(&score_Player_1, &score_Player_2, &ball_X, &ball_Y)) {
            break;
        }
        nanosleep(&tim1, &tim2);
        endwin();
    }
    return 0;
}

void moveRocket(int *rocket_1_Y, int *rocket_2_Y, char key) {
    switch (key) {
        case 'a':
            ((*rocket_1_Y - 2) != 0) ? (*rocket_1_Y -= 1) : *rocket_1_Y;
            break;
        case 'z':
            ((*rocket_1_Y + 2) != HEIGHT - 1) ? (*rocket_1_Y += 1) : *rocket_1_Y;
            break;
        case 'k':
            ((*rocket_2_Y - 2) != 0) ? (*rocket_2_Y -= 1) : *rocket_2_Y;
            break;
        case 'm':
            ((*rocket_2_Y + 2) != HEIGHT - 1) ? (*rocket_2_Y += 1) : *rocket_2_Y;
            break;
    }
}

void screenDraw(const int *rocket_1_Y, const int *rocket_2_Y, const int *ball1_x, const int *ball1_y,
                int *scPlayer1, int *scPlayer2) {
    for (int y = 0; y < HEIGHT_SCOPE; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((y == 0 || y == HEIGHT_SCOPE - 1) && (x != 0 && x != WIDTH - 1)) {
                printf("-");
            } else if (x == 0 || x == WIDTH - 1) {
                printf("|");
            } else if (x == START_INPUT_EXIT) {
                printf("Press \'Q\' to exit          ");
            } else if (x == START_INPUT_SCORE) {
                printf("Player one: %02d | Player two: %02d", *scPlayer1, *scPlayer2);
            } else if (y == 1 && x < WIDTH - NUMBER_SCORE_CHARACTERS) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((x == ROCKET1_DEFAULT_X &&
                 (y == *rocket_1_Y - 1 || y == *rocket_1_Y || y == *rocket_1_Y + 1)) ||
                (x == ROCKET2_DEFAULT_X &&
                 (y == *rocket_2_Y - 1 || y == *rocket_2_Y || y == *rocket_2_Y + 1)) ||
                ((x == 0 || x == WIDTH - 1 || x == WIDTH / 2) && (y != 0 && y != HEIGHT - 1))) {
                printf("|");
            } else if (x == *ball1_x && y == *ball1_y) {
                printf("o");
            } else if ((y == 0 || y == HEIGHT - 1) && x != 0 && x != WIDTH - 1) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void moveBall(int *ball1_x, int *ball1_y, int *d_X, int *d_Y, const int *rocket_1_Y, const int *rocket_2_Y) {
    if (*ball1_y == 1 || *ball1_y == HEIGHT - 2) {
        *d_Y = -(*d_Y);
    }
    if (*ball1_x == ROCKET1_DEFAULT_X + 1 &&
        (*ball1_y == *rocket_1_Y - 1 || *ball1_y == *rocket_1_Y || *ball1_y == *rocket_1_Y + 1)) {
        *d_X = -(*d_X);
    }
    if (*ball1_x == ROCKET2_DEFAULT_X - 1 &&
        (*ball1_y == *rocket_2_Y - 1 || *ball1_y == *rocket_2_Y || *ball1_y == *rocket_2_Y + 1)) {
        *d_X = -*(d_X);
    }

    *ball1_y += *d_Y;
    *ball1_x += *d_X;
}

int checkScore(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y) {
    if (*ball1_x < 2) {
        *scPlayer2 += 1;
        *ball1_x = BALL_START_X;
        *ball1_y = BALL_START_Y;
    }
    if (*ball1_x > WIDTH - 3) {
        *scPlayer1 += 1;
        *ball1_x = BALL_START_X;
        *ball1_y = BALL_START_Y;
    }
    if (*scPlayer1 == WINSCORE) {
        printf("\n\tCONGRATULATION!!! PLAYER ONE IS WON BY %d TO %d!", *scPlayer1, *scPlayer2);
        return TRUE;
    } else if (*scPlayer2 == WINSCORE) {
        printf("\n\tCONGRATULATION!!! PLAYER TWO IS WON BY %d TO %d!", *scPlayer2, *scPlayer1);
        return TRUE;
    }
    return FALSE;
}

void clearScreen(void) { printf("\33c\e[3J"); }