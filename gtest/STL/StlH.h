#pragma once 
#include <vector>
#include <algorithm>
#include <stdlib.h> 

float division(int a, int b) {
	if (b == 0) { // тест
		throw std::logic_error("Error.Division on zero in function \"div\"!");
	}
	else if (a == 0 && b < 0) { // тест
		return 0;
	}
	else { // тест
		return a / b;
	}
}