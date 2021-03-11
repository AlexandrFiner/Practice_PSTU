#include <iostream>

using namespace std;

#define IS_QUEEN -1

int board[8][8];

void reset_board();
void print_board();
bool try_queen(int i);
void set_queen(int i, int j);

int main()
{
    reset_board();
    try_queen(0); // Запускаем цикл
    print_board();
}

// Обнуляем поле
void reset_board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = 0;
}

void print_board() {
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == IS_QUEEN)
                cout << "[]"; // Ферзь
            else cout <<". "; // Пустая клетка
        }
        cout << endl;
    }
}

void set_queen(int i, int j) {
    for (int x = 0; x < 8; ++x)
    {
        board[x][j] += 1; // По вертикали
        board[i][x] += 1; // По горизонтали

        int foo;
        foo = j - i + x; // По диагонали
        if (foo >= 0 && foo < 8)
            board[x][foo] += 1;

        foo = j + i - x;

        if (foo >= 0 && foo < 8)
            board[x][foo] += 1;

        board[i][j] = IS_QUEEN; // Ставим ферзя
    }
}


void reset_queen(int i, int j) {

    for (int x = 0; x < 8; ++x)
    {
        board[x][j] -= 1; // По вертикали
        board[i][x] -= 1; // По горизонтали

        int foo;
        foo = j - i + x; // Далее по двум диагоналям
        if (foo >= 0 && foo < 8)
            board[x][foo] -= 1;

        foo = j + i - x;

        if (foo >= 0 && foo < 8)
            board[x][foo] -= 1;

        board[i][j] = 0; // Ставим ферзя
    }
}

bool try_queen(int i) { // Получаем номер строки
    bool result = false;

    for (int j = 0; j < 8; ++j) // итерирование по клеткам строки
    {
        if (board[i][j] == 0)
        {
            set_queen(i, j); // Ставим ферзь и метим клетки для боя

            if (i == 7) // Последняя строчка
                result = true;
            else if (!(result = try_queen(i + 1)))
                reset_queen(i, j);
        }


        if (result)
            break;
    }
    return result; // возвращение значения функции
}
