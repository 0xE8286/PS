#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) {
        return b;
    }
    return gcd(b, r);
}

int main(void) {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    int A, B;

    cin >> T;

    while (T--) {
        cin >> A >> B;
        cout << (A * B) / gcd(A, B) << "\n";
    }
    return 0;
}
