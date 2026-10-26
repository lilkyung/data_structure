
#include <stdio.h>

#define Size 50000

int* merge_sort(int *,int);
int* merge(int *, int *, int);

int* sortArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	nums = merge_sort(nums,numsSize);
	return nums;
}


int* merge_sort(int *arr, int size){
	if(size <= 1) return arr;
	int *left, *right;
	int next_size = size - size/2;
	
	left = merge_sort(arr,next_size);
	right = merge_sort(arr + next_size, size/2);
	return merge(left, right, size);
}

int* merge(int* left, int* right, int size){
	int sorted_arr[size];
	int lidx, ridx, idx;
	lidx = ridx = idx = 0;
	while(lidx < size - size/2 && ridx < size/2){
		if(left[lidx] > right[ridx]){
			sorted_arr[idx++] = right[ridx++];
		}
		else{
			sorted_arr[idx++] = left[lidx++];
		}
	}
	while(lidx < size - size/2) sorted_arr[idx++] = left[lidx++];
	while(ridx < size/2) sorted_arr[idx++] = right[ridx++];
	for(int i=0; i<size; i++) left[i] = sorted_arr[i];
	return left;
}

