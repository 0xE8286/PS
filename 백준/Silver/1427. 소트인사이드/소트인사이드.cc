#include<iostream>
using namespace std;

void merge(int* num, int start, int mid, int end) {
    int left_i = start;
    int temp_i = start;
    int right_i = mid + 1;
    int temp[11] = { 0, };

    while (left_i <= mid && right_i <= end) {
        if (num[left_i] > num[right_i])
            temp[temp_i++] = num[left_i++];
        else
            temp[temp_i++] = num[right_i++];
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
	char ch_num[11];
    int num[11] = { 0, };
	int i = 0;
	
    cin >> ch_num;
	while (ch_num[i] != '\0') {
		num[i] = ch_num[i] - 48;
		i++;
	}
    merge_sort(num, 0, i-1);

    for (int j = 0; j < i; j++) {
        cout << num[j];
    }

	return 0;
}