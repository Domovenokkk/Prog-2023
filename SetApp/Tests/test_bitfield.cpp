#include <../gtest/gtestt.h>
#include <climits>
#include "../BitField/BitField.h"

TEST(TBitField, can_get_length) {
	// Arrange & Act
	TBitField bf(5);

	// Assert
	EXPECT_EQ(5, bf.size());
}

TEST(TBitField, can_create_bitfield_with_positive_length) {
	// Arrange & Act & Assert
	ASSERT_NO_THROW(TBitField bf(5));
}

TEST(TBitField, can_create_too_large_bitfield) {
	// Arrange & Act
	TBitField bf(INT_MAX);

	// Assert
	EXPECT_EQ(INT_MAX, bf.size());
}

TEST(TBitField, new_bitfield_is_set_to_zero) {
	// Arrange & Act
	TBitField bf(100);

	// Assert
	int sum = 0;
	for (int i = 0; i < bf.size(); i++) sum += bf.test(i);
	EXPECT_EQ(0, sum);
}
