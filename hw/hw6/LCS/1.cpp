/*
'abcbdab', 'bdcaba' 두 문자열의 LCS : 'bdab', 'bcab'
수열의 길이가 길지않은 것을 위한 코드로 recursion으로도 구현 가능
idea :
    index로 마지막 각 문자열의 마지막부터 첫번째까지 역순으로 비교하여 동작 결정
*/

#include <iostream>
#include <string>

using namespace std;

int len(string s);
int lcs(string s1, string s2, int m, int n);

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2, len(s1), len(s2)) << endl;
    }

    return 0;
}

int len(string s) {
    return s.length();
}

int lcs(string s1, string s2, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;   
    } else if (s1[m-1] == s2[n-1]) {
        return lcs(s1, s2, m-1, n-1) + 1;
    } else {
        return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
    }
}
