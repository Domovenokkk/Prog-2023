#include <../gtest/gtestt.h>
#include <climits>
#include "../Set/Set.h"

TEST(TSet, can_combine_two_sets_of_equal_size)
{
	const int size = 5;
	TSet set1(size), set2(size), set3(size), expSet(size);
	// set1 = {1, 2, 4}
	set1.InsElem(1);
	set1.InsElem(2);
	set1.InsElem(4);
	// set2 = {0, 1, 2}
	set2.InsElem(0);
	set2.InsElem(1);
	set2.InsElem(2);
	set3 = set1 + set2;
	// expSet = {0, 1, 2, 4}
	expSet.InsElem(0);
	expSet.InsElem(1);
	expSet.InsElem(2);
	expSet.InsElem(4);

	EXPECT_EQ(expSet, set3);
}

TEST(TSet, check_negation_operator)
{
	const int size = 4;
	TSet set(size), set1(size), expSet(size);
	// set1 = {1, 3}
	set.InsElem(1);
	set.InsElem(3);
	set1 = ~set;
	// expSet = {0, 2}
	expSet.InsElem(0);
	expSet.InsElem(2);

	EXPECT_EQ(expSet, set1);
}