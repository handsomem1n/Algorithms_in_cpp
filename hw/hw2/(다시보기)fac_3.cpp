/*
팩토리얼을 계산하는 재귀함수를 구현하시오.
단, 그 값은 마지막에 나타나는 연속적인 모든 0 을 제외한 마지막 세자리만 출력한다. 예를 들어 10!인 경우에는 그 값이
10! = 3628800 이므로 288 을 출력한다.
*/
#include <iostream>

using namespace std;

const int mod = 1000000; //  계산 도중에 값이 너무 커지는 것을 방지 -> mod가 1000일 경우, 연산의 결과는 항상 0에서 999 사이의 값이 됨.

int fac(int n) {
    if (n <= 1){
        return 1;
    }

    int result = (n * fac(n - 1)) % mod; // % mod를 하여 결과 값이 mod 이상으로 커지는 것 방지.

    // 10의 배수가 아닐 때까지 2로 나누어 5의 배수와 균형을 맞춤
    while (result % 10 == 0) {
        result /= 10;
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << fac(n) % 1000 << endl;  // 마지막 3자리 출력
    }
    return 0;
}
