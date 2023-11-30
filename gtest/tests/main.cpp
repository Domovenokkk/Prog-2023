#include "gtest.h"
#include <stdlib.h> 
#include <time.h>

int main(int argc, char** argv) {
	srand(time(NULL));
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}