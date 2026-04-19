#include <iostream>

using namespace std;

struct Word {
	int cnt;
	char str[51];
};
int N;
Word temp[200000];
Word words[200000];

int strcmp(char *a, char *b) {
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] > b[i])
			return a[i] - b[i];
		else if (a[i] < b[i])
			return a[i] - b[i];
		i++;
	}
	return 0;
}

int atoi(char* a) {
	int value = 0;
	while (*a) {
		value = (value * 10) + *a - '0';
		a++;
	}
	return value;
}

bool isSmall(Word *list, int left_i, int right_i) {
	if (list[left_i].cnt < list[right_i].cnt) {
		return true;
	}
	else if (list[left_i].cnt == list[right_i].cnt) {
		if (strcmp(list[left_i].str, list[right_i].str) <= 0)
			return true;
		else
			return false;
	}
	else
		return false;
}

void merge(Word *list, int start, int mid, int end) {
	
	int left_i = start;
	int right_i = mid + 1;
	int temp_i = start;

	while (left_i <= mid && right_i <= end) {
		if (isSmall(list, left_i, right_i))
			temp[temp_i++] = list[left_i++];
		else
			temp[temp_i++] = list[right_i++];
	}
	while (left_i <= mid) {
		temp[temp_i++] = list[left_i++];
	}
	while (right_i <= end) {
		temp[temp_i++] = list[right_i++];
	}
	for (int i = start; i <= end; i++) {
		list[i] = temp[i];
	}
}

void divide(Word *list, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		divide(list, start, mid);
		divide(list, mid + 1, end);
		merge(list, start, mid, end);
	}
}

int strlen(char* str) {
	int i = 0;
	int cnt = 0;
	while (str[i] != '\0') {
		cnt++;
		i++;
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> words[i].str;
		words[i].cnt = strlen(words[i].str);
	}
	divide(words, 0, N-1);

	cout << words[0].str << "\n";

	for (int i = 1; i < N; i++) {
		if (strcmp(words[i-1].str, words[i].str) != 0)
			cout << words[i].str << "\n";
	}
}