/*
'abcbdab', 'bdcaba' 두 문자열의 LCS : 'bdab', 'bcab'
수열의 길이가 길지않은 것을 위한 코드로 recursion으로도 구현 가능
idea :
    입력받은 문자열을 배열로 저장 -> index로 비교하여 동작 결정
*/

#include <iostream>
#include <string> // string 
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string strA;
        cin >> strA;
        int m = strA.length();
        for(int i = 0 ; i < m ; i ++){
            char a[i] = strA[i];
        }
        string strB;
        cin >> strB;
        int n = strB.length();
        for(int i = 0 ; i < n ; i ++){
            char b[i] = strB[i];
        }
        
        LCS_recursion(a, b, m, n);
    }
}

int LCS_recursion(char a[], char b[], int m, int n){
    if (m = 0 || n = 0) {
        return 0;
    }
    else if (a[m] == b[n]) {
        
    }

    }
    return commonlenth;
}