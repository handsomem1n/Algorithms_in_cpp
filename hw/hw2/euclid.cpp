//두 정수의 최대공약수를 유클리드 알고리즘으로 계산하는 프로그램
#include <iostream>

using namespace std;

int gcd(int a, int b);
int main() {
    int t;
    cin >> t;
    while(t--){
        int a;
        int b;
        cin >> a >> b;
        gcd(a,b);

        cout << gcd(a,b) << endl;
    }   
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}