// 정수 type 을 64-bit “unsigned long long int” 을 사용
// k 번째로 옮겨질 원반의 source 기둥 번호와 target 기둥 번호를 출력
#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, unsigned long long k, int& source, int& target, int from = 1, int mid = 2, int to = 3) {
    if (n == 1) {
        source = from;
        target = to;
        return;
    }

    unsigned long long half = pow(2, n - 1);
    if (k == half) {
        source = from;
        target = to;
    } else if (k < half) {
        hanoi(n - 1, k, source, target, from, to, mid);
    } else {
        hanoi(n - 1, k - half, source, target, mid, from, to);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        unsigned long long k;
        int source, target;

        cin >> n;
        cin >> k;

        hanoi(n, k, source, target);
        cout << source << ' ' << target << endl;
    }
    return 0;
}
