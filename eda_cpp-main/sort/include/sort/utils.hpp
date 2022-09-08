#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

namespace sort{
	float* createArray(int n);
	int* createIntArray(int n);
	float* createRandomArray(int n);
	float* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	int* createRandomIntArrayReal(int n, int minVal, int maxVal);
	void deleteArray(float* A);
	void deleteIntArray(int* A);
	void printArray(float* A, int n);
	void printIntArray(int* A, int n);
	void setAll(float* A, int n, float value);
	void swap(float* A, int i, int j);
	int getRandomInt(int min, int max);
	int* linspace(int max, int n_parts);
}

#endif
