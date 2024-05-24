/*
첫 원소가 가장 작은 최장 연속 부분 수열의 size
총 반복 : index가 start to end까지
재귀 : 앞 >= 뒤 시 start index는 (앞+1 ~ 끝)으로 index업데이트해서 길이구하는 함수 재귀호출

함수 종류 : 1개 (길이 구하는 함수)
key point : 재귀함수를 작성할 때 return할 시 함수가 종료되니 유의하여 사용하자
*/

#include <iostream>
#include <algorithm>  // max()

using namespace std;

#define MAXSIZE 100


int sequencelength(int a[], int start, int end);

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int a[MAXSIZE];
        for(int i = 0 ; i< n ; i ++){
            cin >> a[i];
        }
        int start = 0;
        int end = n-1;

        cout << sequencelength(a, start, end) << endl;

    }
    return 0;
}

int sequencelength(int a[], int start, int end){
    if (start >= end){
        return 1;
    }
    int len=1;
    int i;

    for(i = start ; i < end; i++ ){ // int i = 0 ; i < n-1로 두면 재귀호출 시 적용불가하므로 다음과 같이 써야함 + i를 반복문 밖에서 initializing해야 반복문밖에 있는 재귀함수에 전달 가능.
        if(a[i] <= a[i+1]){
            len++;
        }
        else {
            // return len; // return x : 첫 번째 반복이 끝난 후에 즉시 함수가 종료
            break;
        }
        // return len; // return x
    }
    /*
    int maxlen = max(len, sequencelength(a, start+(i+1), end));
    return maxlen;
    로 작성할 시, 재귀함수 전에 리턴값을 전달해버려 함수가 종료됨.
    */
    return max(len, sequencelength(a, i+1, end));
}

