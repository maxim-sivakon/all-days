
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#define FIELD_SIZE_Y 25
#define FIELD_SIZE_X 80

void InputStartMatrix(int matrix[][FIELD_SIZE_X]);
int StatusChanger(int matrix[][FIELD_SIZE_X], int y, int x);

void RenderingWindow(int matrix[][FIELD_SIZE_X], int speed);
void RewritingMatrix(int matrix[][FIELD_SIZE_X], int speed);
int main() {
    int matrix[FIELD_SIZE_Y][FIELD_SIZE_X];
    // Получаем стартовое поле
    InputStartMatrix(matrix);

    initscr();
    noecho();
    halfdelay(1);
    // Возвращаем возможность читать с клавиатуры
    clearerr(freopen("/dev/tty", "r", stdin));
    int delay = 200000;
    int speed = 3;
    char ch = getch();
    while (ch != 'q' && ch != 'Q') {
        usleep(delay);
        RewritingMatrix(matrix, speed);
        ch = getch();
        if ((ch == 'w' || ch == 'W') && speed < 5) {
            speed++;
            delay /= 2;
        }
        if ((ch == 's' || ch == 'S') && speed > 1) {
            speed--;
            delay *= 2;
        }
        clear();
    }
    endwin();
    return 0;
}
// Функция ввода начального положения игрового поля, либо из файла ( ./a.out <
// shape1.txt), либо из консоли ( как обычно )
void InputStartMatrix(int matrix[][FIELD_SIZE_X]) {
    for (int y = 0; y < FIELD_SIZE_Y; y++) {
        for (int x = 0; x < FIELD_SIZE_X; x++) {
            // Перебираем введенные элементы
            char ch = getchar();
            // Если текущий элемент - конец строки или пробел - переходим на чтение
            // новой строки
            if (ch == '\n' || ch == ' ') {
                x--;
                continue;
            }
            // Если ch == '1' что в инт == 49, то в матрицу записываем 1, если любой
            // другой элемент или мусор
            // - 0.
            int num = ch;
            if (num == 49) {
                matrix[y][x] = 1;
            } else {
                matrix[y][x] = 0;
            }
        }
    }
}
// Функция отрисовки игрового поля.
void RenderingWindow(int matrix[][FIELD_SIZE_X], int speed) {
    for (int y = 0; y < FIELD_SIZE_Y; y++) {
        for (int x = 0; x < FIELD_SIZE_X; x++) {
            if (matrix[y][x] == 1) {
                printw("@");
            } else if (matrix[y][x] == 0) {
                printw(" ");
            }
        }
        printw("\n");
    }

    printw(
        "\n               press s/S    <---   GAME SPEED : %d --->    press "
        "w/W\n",
        speed);
    printw("\n                          PRESS q/Q for left the game\n");
};

void RewritingMatrix(int matrix[][FIELD_SIZE_X], int speed) {
    // Отрисовываем матрицу
    RenderingWindow(matrix, speed);
    // Создаем буферную матрицу, которая будет содержать в себе статусы всех
    // клеток последующей итерации
    int bufferMatrix[FIELD_SIZE_Y][FIELD_SIZE_X];
    for (int y = 0; y < FIELD_SIZE_Y; y++) {
        for (int x = 0; x < FIELD_SIZE_X; x++) {
            // Перебераем клетки матрицы и для каждой просчитываем новое значение,
            // которое записываем в буферную матрицу
            bufferMatrix[y][x] = StatusChanger(matrix, y, x);
        }
    }
    // Передаем основной матрице новые значения из буферной матрицы.
    for (int y = 0; y < FIELD_SIZE_Y; y++) {
        for (int x = 0; x < FIELD_SIZE_X; x++) {
            matrix[y][x] = bufferMatrix[y][x];
        }
    }
}
int StatusChanger(int matrix[][FIELD_SIZE_X], int i, int j) {
    int result = 0;
    int newStatus;
    // Узнаем статус соседних клеток используя тернарный оператор, для
    // отслеживания их местоположения с учетом замкнутости поля на самом себе
    int r1 = matrix[((i - 1) >= 0 ? i - 1 : FIELD_SIZE_Y - 1)][((j - 1) >= 0 ? j - 1 : FIELD_SIZE_X - 1)];
    int r2 = matrix[((i - 1) >= 0 ? i - 1 : FIELD_SIZE_Y - 1)][j];
    int r3 = matrix[((i - 1) >= 0 ? i - 1 : FIELD_SIZE_Y - 1)][((j + 1) <= FIELD_SIZE_X - 1 ? j + 1 : 0)];
    int r4 = matrix[i][((j - 1 >= 0 ? j - 1 : FIELD_SIZE_X - 1))];
    int r5 = matrix[i][((j + 1 <= FIELD_SIZE_X - 1 ? j + 1 : 0))];
    int r6 = matrix[((i + 1) <= FIELD_SIZE_Y - 1 ? i + 1 : 0)][((j - 1) >= 0 ? j - 1 : FIELD_SIZE_X - 1)];
    int r7 = matrix[((i + 1) <= FIELD_SIZE_Y - 1 ? i + 1 : 0)][j];
    int r8 = matrix[((i + 1) <= FIELD_SIZE_Y - 1 ? i + 1 : 0)][((j + 1) <= FIELD_SIZE_X - 1 ? j + 1 : 0)];
    // Суммируем статусы соседних клеток
    result = r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8;
    // В зависимости от результата и начального состояния клетки, новое состояние
    // - жизнь = 1 / смерть = 0;
    if (matrix[i][j] == 0 && result == 3) {
        newStatus = 1;
    } else if (matrix[i][j] == 1 && (result == 2 || result == 3)) {
        newStatus = 1;
    } else {
        newStatus = 0;
    }
    //    Возвращаем статус клетки, и присваеваем его буферному значению.
    return newStatus;
}
