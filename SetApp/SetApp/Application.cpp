#include <Set.h>
#include <iostream>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool flag = 1;
	TSet A(1);
	TSet B(1);
	std::string title = ("-------Множества-------\n\n");
	const std::string menu = " 1.Задать множество A\n 2.Задать множество B\n 3.Найти объединение множества A + B\n 4.Найти разность множества A - B\n 5.Найти пересечение множества A * B\n 6.Найти дополнение множества\n 7.Запустить демонстрационный пример\n 8.Выход\n";
	const std::string in = " Выбор: ";
	while (flag) 
	{
		std::cout << title;
		std::cout << menu;
		std::cout << in;
		int x;
		std::cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
		{
			int power;
			std::cout << "Введите мощность множества A: ";
			std::cin >> power;
			TSet ts(power);
			std::cout << "Задать поле: ";
			std::cin >> ts;
			A = ts;
			std::cout << A;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int power;
			std::cout << "Введите мощность множества B: ";
			std::cin >> power;
			TSet ts(power);
			std::cout << "Задать поле: ";
			std::cin >> ts;
			B = ts;
			std::cout << A;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			TSet ts(A + B);
			std::cout << ts;
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			TSet ts(A * (~B));
			std::cout << ts;
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			TSet ts(A * B);
			std::cout << ts;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			std::cout << "Дополнение множества А: " << ~A;
			std::cout << "Дополнение множества B: " << ~B;
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			flag = 0;
		}
		}
	}
}