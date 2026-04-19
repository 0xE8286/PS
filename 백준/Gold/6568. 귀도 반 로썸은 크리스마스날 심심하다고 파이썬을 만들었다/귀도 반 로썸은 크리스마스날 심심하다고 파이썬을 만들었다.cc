#include <iostream>
#include <bitset>

using namespace std;

int mem[32];
string code;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> code) {
		mem[0] = bitset<8>(code).to_ulong();
		for (int i = 1; i < 32; i++) {
			cin >> code;
			mem[i] = bitset<8>(code).to_ulong();
		}

		int pc = 0;
		int acc = 0;

		while (true) {
			int cmd = mem[pc] >> 5;
			int x = mem[pc] & 31;

			pc += 1;
			pc %= 32;

			if (cmd == 0) {
				mem[x] = acc;
			}
			else if (cmd == 1) {
				acc = mem[x];
			}
			else if (cmd == 2) {
				if (acc == 0) {
					pc = x;
				}
			}
			else if (cmd == 3) {
				//아무 연산도 하지 않는다
			}
			else if (cmd == 4) {
				acc--;
				if (acc < 0) {
					acc = 255;
				}
			}
			else if (cmd == 5) {
				acc++;
				if (acc > 255) {
					acc = 0;
				}
			}
			else if (cmd == 6) {
				pc = x;
			}
			else if (cmd == 7) {
				break;
			}
		}
		cout << bitset<8>(acc) << '\n';
	}
	return 0;
}