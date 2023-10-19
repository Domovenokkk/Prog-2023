#include "Iterators.h"

int main() {
	TVector<int> v1(10);
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	system("pause");
	return 0;
}