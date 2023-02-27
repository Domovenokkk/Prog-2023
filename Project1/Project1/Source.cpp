#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

class Game {
    int cards[14];
    int count;

    Game() {
        count = 14;
        for (int i = 0; i < count; i += 2) {
            cards[i] = i;
            cards[i + 1] = cards[i];
        }
        for (int i = 0; i < count; i += 1) {
            swap(cards[i], cards[rand() % count]);
        }
    }
};
using namespace std;
int main() {

    int iKey = 67;
    int curPos = 0;
    int size = 6;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    for (int i = 0; i < size; i++) cout << "[   ]";
    cout << endl;
    for (int i = 0; i < size; i++)
        if (i == curPos) cout << "  ^  ";
        else cout << "     ";
    iKey = _getch();

    while (iKey != KEY_ENTER) {
        switch (iKey) {
        case KEY_ARROW_LEFT:
            curPos--;
            break;
        case KEY_ARROW_RIGHT:
            curPos++;
            break;
        }

        if (curPos < 0) { curPos = size - 1; }
        if (curPos > size - 1) { curPos = 0; }

        system("cls");

        for (int i = 0; i < size; i++) cout << "[   ]";
        cout << endl;
        for (int i = 0; i < size; i++)
            if (i == curPos) cout << "  ^  ";
            else cout << "     ";
        iKey = _getch();

    }
    for (int i = 0; i < size; i++) cout << "[   ]";
    for (int i = 0; i < size; i++)
        if (i == curPos) cout << "  ^  ";
        else cout << "     ";
    return 0;

};