#include<iostream>
using namespace std;

#define MAX_N 500000

long long result = 0;
int nums[MAX_N]; 
int temp[MAX_N];

void merge(int* num, int start, int mid, int end) {
    int left_i = start;
    int temp_i = start;
    int right_i = mid + 1;
    

    while (left_i <= mid && right_i <= end) {
        if (num[left_i] <= num[right_i]) {
            temp[temp_i++] = num[left_i++];
        }
        else {
            temp[temp_i++] = num[right_i++];
            result += (mid + 1 - left_i);
        }
    }
    if (left_i <= mid) {
        for (int i = left_i; i <= mid; i++)
            temp[temp_i++] = num[i];
    }
    else {
        for (int i = right_i; i <= end; i++) {
            temp[temp_i++] = num[i];
        }
    }
    for (int i = start; i <= end; i++) {
        num[i] = temp[i];
    }
}

void merge_sort(int* num, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(num, start, mid);
        merge_sort(num, mid + 1, end);
        merge(num, start, mid, end);
    }
}

int main(void) {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    merge_sort(nums, 0, N - 1);
    cout << result;

	return 0;
}