/*
자연수 𝑎와 음수가 아닌 정수 𝑛이 주어졌을 때, 𝑎의 𝑛거듭제곱을 재귀함수로 계산하시오. 단,
거듭제곱은 매우 큰 수가 될 수 있으므로 그 수의 마지막 세 자리수만 계산한다.
*/

#include <iostream>

using namespace std;

const int mod = 1000;

int exponen(int a, int n);

int main() {
    int t;
    cin >> t;
    while(t--){
        int a;
        int n;
        cin >> a >> n;
        exponen( a, n);
        cout << exponen( a, n) % 1000 << endl;
    }
}

int exponen(int a, int n){
    if(n ==0){
        return 1;
    }
    int result = (a * exponen(a, n-1)) % mod;

    return result;
}