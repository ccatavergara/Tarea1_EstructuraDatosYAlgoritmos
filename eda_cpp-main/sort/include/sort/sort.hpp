#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort {
	void selectionSort(float* A, int n);
	int split_qs(float* A, int i, int j);
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	int  k_smallest(float* A, int i, int j, int k);
	int  k_smallest(float* A, int n, int k);
	void merge(float *A, int i, int j);
	void mergeSort(float *A, int i, int j);
	void mergeSort(float *A, int n);
	void insertSort(float *A, int n);
	int max_value(int *A, int n);
	void countSort(int *A, int n, int x);
	void radixSort(int *A, int n);
}

#endif
