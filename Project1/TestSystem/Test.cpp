#include <iostream>
#include <time.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"


int maximum(int x, int y) {
	bool isXMore = (abs(x - y) + (x - y));
	return isXMore * x + (1 - isXMore) * y;
}

int switchVars(int& x, int& y) {
	x = x + y;
	y = x - y;
	x = x - y;
	return x;
}

enum Status { FAILED = 0, PASSED = 1 };

template<typename T, typename TP>
class Test {
	std::string name;
	T param1, param2;
	T expected;
	T real;
	Status status;
	time_t timer;
	T(*func)(TP, TP);
	//friend class Tests;
public:
	Test(std::string _nametest, T(*_func)(TP, TP), TP fir, TP sec, T exp) : name(_nametest) {
		func = _func;
		param1 = fir;
		param2 = sec;
		expected = exp;
		timer = clock();
		real = func(param1, param2);
		timer = clock() - timer;
		status = (expected == real) ? PASSED : FAILED;
	}
	std::string getName() {
		return name;
	}
	Status getStatus() {
		return status;
	}
	time_t getTime() {
		return timer;
	}
	T getExp() {
		return expected;
	}
	T getFnc() {
		return real;
	}
};

template<typename T, typename TP>
class Tests {
	std::string name;
	Test<T, TP>** all;
	size_t size;
	size_t count;
public:
	Tests(std::string _name, size_t _size) : name(_name), size(_size), count(0) {
		all = new Test<T, TP>*[size];
	}

	void createTest(std::string _nametest, T(*func)(TP, TP), TP fir, TP sec, T exp) {
		if (count < size) {
			Test <T, TP>* new_test = new Test <T, TP>(_nametest, func, fir, sec, exp);
			all[count++] = new_test;
		}
		else {
			std::cout << RED << "[   ERROR   ] " << RESET << "_not_enough_space" << std::endl;
		}
	}

	void runALL() {
		std::cout << GREEN << "[ ========== ] " << RESET << "Running " << count << " tests from " << name << std::endl;
		std::cout << GREEN << "[ ---------- ] " << RESET << std::endl;
		for (int i = 0; i < count; i++) {
			std::cout << GREEN << "[  RUN       ] " << RESET << (*all[i]).getName() << std::endl;
			if ((*all[i]).getStatus() == PASSED) {
				std::cout << GREEN << "[        OK  ] " << RESET << (*all[i]).getName() << " (" << (*all[i]).getTime() << " ms)" << std::endl;
			}
			else {
				std::cout << RED << "[   FAILED   ] " << RESET << std::endl;
				std::cout << "Expected value : " << (*all[i]).getExp() << std::endl;
				std::cout << "Witch is :       " << (*all[i]).getFnc() << std::endl;
			}
		}
		std::cout << GREEN << "[ ========== ] " << RESET << count << " tests from ran " << std::endl;
		int passed = 0;
		for (int i = 0; i < count; i++) { passed += ((*all[i]).getStatus() == PASSED) ? 1 : 0; }
		std::cout << GREEN << "[   PASSED   ] " << RESET << passed << " tests" << std::endl;
		if (count - passed != 0) {
			std::cout << RED << "[   FAILED   ] " << RESET << count - passed << " tests, listed below:" << std::endl;
		}
		for (int i = 0; i < count; i++) {
			if ((*all[i]).getStatus() == FAILED) {
				std::cout << (*all[i]).getName() << std::endl;
			}
		}
		std::cout << std::endl;
	}
};

void main() {
	std::string testsName = "MaxWithoutTempVar";
	Tests<int, int> tests(testsName, 4);
	tests.createTest("ok_than_first_is_bigger", maximum, 15, 8, 15);
	tests.createTest("ok_than_second_is_bigger", maximum, 8, 10, 10);
	tests.createTest("ok_than_are_equal", maximum, 5, 5, 5);
	tests.createTest("ok_with_negative_value", maximum, -10, -5, 10);
	tests.runALL();

	Tests<int, int&> tests_1("swap_swap", 1);
	int x, y;
	x = 1; y = 5;
	tests_1.createTest("test 1", switchVars, x, y, 5);
	tests_1.runALL();
}