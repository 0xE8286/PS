#include <iostream>

using namespace std;

struct User {
	int age;
	char name[101];
};
int N;
User temp[100000];
User users[100000];

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

void merge(User *list, int start, int mid, int end) {
	
	int left_i = start;
	int right_i = mid + 1;
	int temp_i = start;

	while (left_i <= mid && right_i <= end) {
		if (list[left_i].age <= list[right_i].age)
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

void divide(User *list, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		divide(list, start, mid);
		divide(list, mid + 1, end);
		merge(list, start, mid, end);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		char temp[4];
		cin >> temp >> users[i].name;
		users[i].age = atoi(temp);
	}
	divide(users, 0, N-1);

	for (int i = 0; i < N; i++) {
		cout << users[i].age << " " << users[i].name << "\n";
	}
}