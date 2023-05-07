#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "sys/stat.h"

using namespace std;

#define KEY_EXIT 27
#define KEY_ENTER 13

#define NONE_TITLE ""

#define MENU_SIZE 6

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

class Game {
public:
	int cards[14];
	int count;
	Game() {
		count = 6;
		for (int i = 0; i < count; i += 2) {
			cards[i] = 2 + i;
			cards[i + 1] = cards[i];
		}
		for (int i = 0; i < count; i++) {
			swap(cards[i], cards[rand() % count]);
		}
	}
};

void pr(int* openedcards, int count) {
	system("cls");
	for (int i = 0; i < count; i++) {
		if (openedcards[i] != -1)
			cout << "[" << openedcards[i] << "]";
		else
			cout << "[ ]";
	}
}

int main() {
	srand(time(0));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	SetConsoleTextAttribute(hStdOut, 10);

	system("cls");

	int iKey = 67;
	int menupos = 0;
	int count = 6;
	bool win = 0;

	Game game;

	int opencard[14];
	int opened = 0;
	char last = -1, past = -1;

	for (int i = 0; i < 14; i++) { opencard[i] = -1; }
	while (!win) {
		if (opened == count)
			break;
		int iKey = 67;
		while (iKey != KEY_ENTER) {
			switch (iKey) {
			case KEY_ARROW_LEFT:
				menupos--;
				break;
			case KEY_ARROW_RIGHT:
				menupos++;
				break;
			}

			if (menupos < 0) { menupos = MENU_SIZE - 1; }
			if (menupos > MENU_SIZE - 1) { menupos = 0; }
			pr(opencard, count);
			cout << endl << " ";
			for (int i = 0; i < menupos; i++) {
				cout << "   ";
			}
			cout << "^";

			iKey = _getch();
		}
		opened++;
		past = last;
		last = menupos;
		opencard[menupos] = game.cards[menupos];
		if (opened % 2 == 0) {
			if (opencard[past] != opencard[last]) {
				pr(opencard, count);
				Sleep(500);
				opened -= 2;
				opencard[past] = -1;
				opencard[last] = -1;
			}
		}
	}
	system("cls");
	cout << "Congratulations. You won!";
}

