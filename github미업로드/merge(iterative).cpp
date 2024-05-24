// merge(강의노트 참고)
// merge 과정 후 핵심연산자(비교연산자)의 실행 횟수 출력
/*
idea :
    더 이상 분할할 수 없을 때까지 두 개의 부분 배열로 분할
    분할된 부분 배열들을 배열의 원소를 순서대로 비교하면서 결과 배열에 차례로 삽입
    merge 함수에서 원소를 비교할 때마다 count를 1씩 증가
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void mergeSort(vector<int>& a, int n, int& count);
void merge(vector<int>& a, int low, int mid, int high, int& count);


int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, count = 0;
        cin >> n;

        vector<int> a(MAX_SIZE);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        mergeSort(a, n, count);
        cout << count << endl;
    }

    return 0;
}

void mergeSort(vector<int>& a, int n, int& count) {
    int size = 1;

    while (size < n) { 
        for (int i = 0; i < n; i = i + 2 * size) {
            int low = i;
            int mid = MIN(low + size - 1, n-1);
            int high = MIN(i + 2 * size - 1, n-1);

            merge(a, low, mid, high, count);
        }

        size = size * 2;
    }
}


void merge(vector<int>& a, int low, int mid, int high, int& count) {
    int i, j, k;
    vector<int> tmp(MAX_SIZE);

    for(i = low; i <= high; i++){
        tmp[i] = a[i];
    }

    i = k = low;
    j = mid + 1;
    
    while(i <= mid && j <= high) {
        count++;
        if (tmp[i] <= tmp[j]){
            a[k++] = tmp[i++];
        }
        else{
            a[k++] = tmp[j++];
        }
    }
    
    while(j <= high){
        a[k++] = tmp[j++];
    }

    while(i <= mid){
        a[k++] = tmp[i++];
    }
    

}
