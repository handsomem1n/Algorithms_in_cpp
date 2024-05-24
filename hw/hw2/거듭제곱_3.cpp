#include <iostream>

using namespace std;

const int mod = 1000;

int exponen(int a, int n);

int main() {
    int t;
    cin >> t;
    while(t--){
        int a, n;
        cin >> a >> n;
        cout << exponen(a, n) << endl;
    }
    return 0;
}

int exponen(int a, int n) {
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0) { // n이 짝수인 경우, 
        int half = exponen(a, n/2) % mod; // % mod는 천의 자리 이상으로 가지않게 하기 위함.
        return (half * half) % mod; // a^n은 (a^(n/2))^2와 같다.
    } else { // n이 홀수인 경우
        return (a * exponen(a, n-1)) % mod;
    }
}
