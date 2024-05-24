/*
1. 덩어리로 보았을 때, 왼쪽 덩어리와 오른쪽 덩어리 중 큰 것이 maxsum / 같으면 둘을 더한 것이 maxsum
2. 핵심) 문제를 더 작은 부분 문제로 나누기 위해 half를 기준으로 왼쪽과 오른쪽으로 확장해가며 연속된 숫자들의 합을 계산하는 방식으로 접근
3. a[i]의 값이 음수라는 이유만으로 버리면 안됨(예를 들어 5 -1 10의 경우 0 2기 츨략되어야 하니.)
4. 최댓값이 음수의 경우 0으로 출력
*/
#include <iostream>
#include <climits> // INT_MAX
using namespace std;

#define MAXSIZE 100

int MCSSDnC(int a[], int left, int right);


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
        int left = 0;
        int right = n-1;
        
        cout << MCSSDnC(a, left, right) << endl;

    }
    return 0;
}

int MCSSDnC(int a[], int left, int right){
    if (left == right){
        return a[left];
    }
    int leftsum = 0, rightsum = 0; // int leftsum, rightsum = 0; 오류
    int leftmaxsum  = INT_MIN; // int 범위에서의 최솟값으로 설정
    int rightmaxsum  = INT_MIN;
    int half = (left + right) / 2;

    for (int i = half; i >= left; i--){ // 조건2 half to left
        leftsum = leftsum + a[i];
        leftmaxsum = max(leftsum, leftmaxsum);
    }
    for(int i = half+1 ; i <= right ; i++){ // half+1 to right
        rightsum = rightsum + a[i];
        rightmaxsum = max(rightsum, rightmaxsum);
    }
    
    int halfsum = rightmaxsum + leftmaxsum; // Dnc - 중앙 기준 연속 부분 배열의 합
    int sectorsum = max(MCSSDnC(a, left, half), MCSSDnC(a, half+1, right)); // DnC - 각 부분에서의 최대 연속 부분 배열의 합
    if (halfsum < 0){ // 조건4
        halfsum = 0;
    }
    return max(halfsum, sectorsum);

}
