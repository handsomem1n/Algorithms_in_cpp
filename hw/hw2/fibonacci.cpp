// 점화식(recursive equation)을 이용하여 피보나치(Fibonacci) 수를 계산하는 재귀함수를 구현
// 오름차순이 맞는 거 같음
/*
fibo(9) = fibo(8) + fibo(7)
fibo(8) = fibo(7) + fibo(6)
fibo(7) = fibo(6) + fibo(5)
fibo(6) = fibo(5) + fibo(4)
*/ 

/*
f0 = 0
f1 = 1
f2 = f1 + f0
f3 = f2 + f1
*/

#include <iostream>

// #define n_max 30

using namespace std;

int fibo(int n);

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;   
        fibo(n);
        // int result = fibo(n);
        // int result = 0;
        // for(int i = n ; i<2; i--){
        //     result  = fibo(i-1)+ fibo(i-2);
        // }
        cout << fibo(n) << endl;
    }
    return 0;
}

int fibo(int n){
    // int result = 0;
    // if(n =0){
    //     result = 0;
    // }
    // else if(n =1){
    //     result = 1;
    // }
    // else if (n>1){
    //         int fibo(0) = 0;
    //         int fibo(1) = 1;
    //     for(int i = 2 ; i<=n-2; i++){
    //         int fibo(i) = int fibo(i-1) + int fibo(i-2);
    //     }
    // }

    if (n<=1){
        return n;
    }
    // else if (n>1){ - else
        // return fibo(n-1) + fibo(n-2);
    // }
    else{ // else if (n>1)라고 할 경우 warning: non-void function does not return a value in all control paths [-Wreturn-type] 발생
        return fibo(n-1) + fibo(n-2);
    }
}


// 0 1 1 2 3 5