#include "../gtest/gtest.h"
#include "../STL/StlH.h"


TEST(test_fillvector, check_size) {
	// Arrange
	std::vector<int> v;
	// Act
	FillVector(v);
	int res = v.size();
	// Assert
	EXPECT_EQ(res, 20);
}

TEST(test_fillvector, check_fill) {
	std::vector<int> v;

	FillVector(v);
	int res = 0;
	for (int i = 0; i < 20; i++) {
		res += v[i];
	}
	EXPECT_EQ(res, 0);
}

///


TEST(test_minmax_out, checkmin) {
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	EXPECT_EQ(MinElem(v), 1);
}

TEST(test_minmax_out, checkmax) {
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	EXPECT_EQ(MaxElem(v), 5);
}

///

TEST(test_arrayaddtovec, check_size) {
	std::vector<int> v = { 6, 2 ,1 ,5 };
	int array[4] = { 5,2,6,9 };

	AddFromArray(v, array, 4);

	EXPECT_EQ(v.size(), 8);
}


TEST(test_cmptozero, check_vec) {
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	ReplacementWithZero(v, 3);

	EXPECT_EQ(v[3] + v[4], 9);

}

///

TEST(createvectorbiggerthancmp__, check_array) {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int> veccmp = NewVector(vec, 3);

	EXPECT_EQ(veccmp[3] == 4 && veccmp[4] == 5, 1);
}

TEST(erasevector_, check_erased) {
	std::vector<int> vec = { 1,2,3,4,5,6,7 };
	erasevector(vec);
	EXPECT_EQ(vec.size(), 0);
}

TEST(addelemsforarray, check_size) {
	std::list<int> l{ 1, 2, 3, 4, 5 };
	int array[4] = { 6,7,8,9 };
	AddElemsToList(l, array, 4);
	EXPECT_EQ(l.size(), 9);
}