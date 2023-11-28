#include "../TVector/TVector.h"
#include "../gtest/gtestt.h"

TEST(TVector, can_create_vector_with_positive_length) {
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector) {
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_get_size) {
	TVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

TEST(TVector, can_set_and_get_element) {
	TVector<int> v(4);
	v[0] = 4;
	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_create_vector_with_negative_length) {
	ASSERT_ANY_THROW(TVector<int> v(-1));
}

TEST(TVector, throws_when_set_element_with_negative_index) {
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index) {
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[7]);
}

TEST(TVector, can_assign_vectors_of_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(3);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, cvectors_with_different_size_are_not_equal) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	EXPECT_EQ(0, v1 == v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	ASSERT_ANY_THROW(v1 + v2;);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	ASSERT_ANY_THROW(v1 - v2;);
}