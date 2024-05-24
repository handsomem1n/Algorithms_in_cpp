#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void permu(string s, int a, int b, vector<string>& result); // 이 함수는 주어진 문자열 s에 대한 모든 순열을 생성하여 result 벡터에 저장(a과 b은 문자열 내의 인덱스로 사용)
int weight(const string& str); // 가중치

int main() {
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int n = str.length();
        int permCount = 0;

        vector<string> permutations; // 모든 순열을 저장할 벡터
        permu(str, 0, n-1, permutations); // permu 함수를 호출하여 str의 모든 순열을 permutations 벡터에 저장

        for (size_t i = 0; i < permutations.size(); i++) { // size_t는 data type임. unsigned number로 양수만 저장함.
            permCount += weight(permutations[i]) > 0 ? 1 : 0; // weight 함수를 호출하여 현재 순열의 가중치를 계산하고, 양수인 경우 permCount를 증가
        }
        
        cout << permCount << endl;
        
    }
    return 0;
}

void permu(string s, int a, int b, vector<string>& result) { // 문자열의 순열을 생성하는 재귀 함수(a에서 b까지의 인덱스 범위에서 문자열 s의 순열을 생성하고, 이 순열을 result 벡터에 저장)
    if (a == b) {
        result.push_back(s);
    } else {
        for (int i = a; i <= b; i++) {
            swap(s[a], s[i]);
            permu(s, a+1, b, result);
            swap(s[a], s[i]);
        }
    }
}

int weight(const string& str) { // 순열 조합의 string배열을 인자로 받아 가중치 구하기.
    int weighttotal = 0;
    for (size_t j = 0; j < str.size(); j++) { 
        char c = str[j];
        int asciiValue = static_cast<int>(c);
        int asciiA = static_cast<int>('a'); // static_cast<char>(a)는 안됨
        int weight = pow(-1, j) * (asciiValue - asciiA);
        weighttotal += weight;
    }
    return weighttotal;
}
