#include "../gtest/gtest.h"
#include "../STL/StlH.h"

TEST(test_division, throw_when_try_div_by_zero_test) {
	// Arrange
	int x = 6, y = 0;
	// Act & Assert
	ASSERT_ANY_THROW(division(x, y));
}
TEST(test_division, positive_zero_after_div_zero_on_negative_value_test) {
	// Arrange
	int x = 0, y = -5;
	// Act
	float res = division(x, y);
	// Assert
	EXPECT_EQ(res, 0);
}