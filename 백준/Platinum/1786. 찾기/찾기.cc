#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 10000000007;
const int BASE = 127;

vector<int> rabinKarp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> result;

    long long patternHash = 0;
    long long textHash = 0;
    long long basePow = 1;

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * BASE + pattern[i]) % MOD;
        textHash = (textHash * BASE + text[i]) % MOD;
        if (i > 0) {
            basePow = (basePow * BASE) % MOD;
        }
    }

    for (int i = 0; i <= n - m; i++) {
        // 현재 윈도우의 해시 값이 패턴의 해시 값과 같은지 확인
        if (textHash == patternHash) {
            result.push_back(i);
        }

        // 다음 윈도우의 해시 값을 업데이트
        if (i < n - m) {
            textHash = (textHash - text[i] * basePow) % MOD;  // 맨 앞 문자 제거
            if (textHash < 0) textHash += MOD;  // 음수일 경우 보정
            textHash = (textHash * BASE + text[i + m]) % MOD;  // 다음 문자 추가
        }
    }

    return result;
}

int main() {
    string text, pattern;

    getline(cin, text);
    getline(cin, pattern);

    vector<int> occurrences = rabinKarp(text, pattern);

    cout << occurrences.size() << '\n';
    
    for (int idx : occurrences) {
        cout << idx + 1 << " ";
    }

    return 0;
}
