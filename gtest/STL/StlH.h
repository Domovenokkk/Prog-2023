#pragma once 
#include <vector>
#include <algorithm>
#include <stdlib.h> 
#include <list>

void FillVector(std::vector<int>& v) {
	if (v.size() != 0) { v.clear(); }
	for (int i = 0; i < 20; i++) {
		v.push_back(0);
	}
};

void RandVector(std::vector<int>& v) {
	v.clear();
	for (int i = 0; i < v.size(); i++) {
		int randN = (rand() % 200 + 1 - 100);
		v.push_back(randN);
		std::cout << v[i];
	}
}

int MaxElem(std::vector<int> v) {
	int max = *max_element(v.begin(), v.end());
	return max;
}

int MinElem(std::vector<int> v) {
	int min = *min_element(v.begin(), v.end());
	return min;
}

void AddFromArray(std::vector<int>& v, int array[], int size) {
	for (int i = 0; i < size; i++) {
		v.push_back(array[i]);
	}
	sort(v.begin(), v.end());
}

void ReplacementWithZero(std::vector<int>& v, int n) {
	std::replace_if(v.begin(), v.end(), [n](int& i) {
		return i < n;
		}, 0);
}

std::vector<int> NewVector(std::vector<int> v, int n) {
	std::vector<int> res;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > n) {
			res.push_back(v[i]);
		}
	}
	return res;
}

void RandomShuffle(std::vector<int> v) {
	std::random_shuffle(v.begin(), v.end());
}

void erasevector(std::vector<int>& v) {
	v.clear();
}


