#include <iostream>
#include "sort/sort.hpp"
#include "sort/utils.hpp"

namespace sort{

	void selectionSort(float* A, int n){
		int smallest = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < n - 1; i++){
			smallest = i;
			for (j = i + 1; j < n; j++){
				if (A[j] < A[smallest]){
					smallest = j;
				}
			}
			swap(A,i,smallest);
		}
	}

	int split_qs(float* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(float* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}

	int  k_smallest(float* A, int i, int j, int k){
		int p = split_qs(A, i, j);
		int val = 0;
		if (k == p){
			val = A[p];
		}
		else if (k < p){
			val = k_smallest(A, i, p-1, k);
		}
		else{
			val = k_smallest(A, p+1, j, k);
		}
		return val;
	}

	int  k_smallest(float* A, int n, int k){
		return k_smallest(A, 0, n-1, k);
	}

	void merge(float* A, int i, int j, int k){
		int A_aux[j - 1 + 1];
		int q = 0;
		int p1 = i;
		int p2 = k+1;
		while(p1 <= k && p2 <= j){
			if(A[p1] <= A[p2]){
				A_aux[q] = A[p1];
				p1++;
			}
			else{
				A_aux[q] = A[p2];
				p2++;
			}
			q++;
		}
		while(p1 <= k){
			A_aux[q] = A[p1];
			p1++;
			q++;
		}
		while(p2 <= j){
			A_aux[q] = A[p2];
			p2++;
			q++;
		}
		for(int n = 0; n < j-i+1; n++){
			A[n+i] = A_aux[n];
		}
	}

	void mergeSort(float *A, int i, int j){
		int k = ((i + j)/2);
		if(i < j){
			mergeSort(A, i, k);
			mergeSort(A, k + 1, j);
			merge(A, i, j, k);
		}
	}

	void mergeSort(float *A, int n){
		mergeSort(A, 0, n-1);
	}

	void insertSort(float *A, int n){
		int i = 0;
    	int j = 0;
    	float elem = 0;
    	for (i = 1; i < n; i++){
			elem = A[i];
			j = i-1;
			while ((j >= 0) && (elem < A[j])){
				A[j+1] = A[j];
				j = j - 1;
			}
			A[j+1] = elem;
    	}
	}

// RadixSort obtenida de fuente externa
// link: https://www.geeksforgeeks.org/radix-sort/
	int max_value(int *A, int n){
		int max = 0;
		for(int i = 0; i < n; i++){
			if(max < A[i]) 
				max = A[i];
		}
		return max;
	}

	void countSort(int *A, int n, int x){
		int output[n]; 
		int count[10] = {0};

		for(int i = 0; i < n; i++){
			count[(A[i] / x) % 10] ++;
		}

		for(int i = 1; i < 10; i++){
			count[i] += count[i-1];
		}

		for(int i = n - 1; i >= 0; i-- ){
			output[(count[(A[i] / x) % 10] - 1)] = A[i];
			count[(A[i] / x) % 10] --;
		}

		for(int i = 0; i < n; i++){
			A[i] = output[i];
		}
	}

	void radixSort(int *A, int n){
		int max = max_value(A, n);

		for(int x = 1; max / x > 0; x *= 10){
			countSort(A, n, x);
		}
	}
}