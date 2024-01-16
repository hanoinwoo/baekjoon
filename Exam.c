#define _CRT_SECURE_NO_WARNINGS
#define MAX_COUNT 5
#include <stdio.h>
#include <string.h>
#include <malloc.h>


int merge(int* arr1, int* arr2,int l_arr1,int l_arr2,int* result) {
	int cnt1 = 0, cnt2 = 0,cnt3=0;
	while (cnt1 < l_arr1 && cnt2 < l_arr2) {
		if (*(arr1+cnt1) < *(arr2+cnt2)) {
			*(result + cnt3) = *(arr1 + cnt1);
			cnt1++;
			cnt3++;
		}
		else {
			*(result + cnt3) = *(arr2 + cnt2);
			cnt2++;
			cnt3++;
		}
	}
	if (cnt1 < l_arr1) {
		for (int i = 0; i < l_arr1 - cnt1; i++) {
			*(result + cnt3) = *(arr1 + cnt1 + i);
			cnt3++;
		}
	}
	else {
		for (int i = 0; i < l_arr2 - cnt2; i++) {
			*(result + cnt3) = *(arr2 + cnt2 + i);
			cnt3++;
		}
	}
	return 0;
}


int *merge_sort(int* arr, int N) {
	int* result = (int*)malloc(sizeof(int) * N);
	if (N == 1) {
		*result = *arr;
		return result;
	}
	int l_len = (N / 2);
	int r_len = N - l_len;
	int* l_arr = arr;
	int* r_arr = arr + l_len;
	int* l_sorted = merge_sort(l_arr, l_len);
	int* r_sorted = merge_sort(r_arr, r_len);
	merge(l_sorted, r_sorted, l_len, r_len, result);
	free(l_sorted);
	free(r_sorted);
	return result;
}


int main() {
	int N;
	scanf("%d", &N);
	int* p = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", p+i);
	}
	int* final = merge_sort(p, N);
	free(p);
	for (int j = 0; j < N; j++) {
		printf("%d\n", *(final + j));
	}
	free(final);
}