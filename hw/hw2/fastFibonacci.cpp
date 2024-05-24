// basic fibonaa]cci보다 다른 점은, 아마도 fibo(n)의 값을 저장해두었다가, 필요한 경우 불러오는 식일 거 같음. 이로인해 이미 구했던 fibo에 대해서 중복 계산하는 일을 방지할 수 있음.
#include <iostream>

using namespace std;

const int mod = 1000;

int fastfibo(int n);

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fastfibo(n);
    }
}

int fastfibo(int n){
    if (n<= 1){
        return n;
    }
    else
}