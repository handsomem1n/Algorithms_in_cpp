#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long factorial(int n);
int countPositivePermutations(const string& s);

int main() {
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout << countPositivePermutations(str) << endl;
    }
    return 0;
}

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int countPositivePermutations(const string& s) {
    int n = s.size();
    int countNegative = 0;

    for (int i = 0; i < n; i++) {
        int diff = s[i] - 'a';
        int effectiveDiff = pow(-1, i) * diff;

        if (effectiveDiff < 0) {
            countNegative++;
        }
    }

    // 모든 문자가 양수 가중치 또는 모든 문자가 음수 가중치를 갖는 경우
    // 그 문자열의 모든 순열은 양의 가중치를 갖게 됩니다.
    if (countNegative == 0 || countNegative == n) {
        return factorial(n);
    }

    return 0;
}
