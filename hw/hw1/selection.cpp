//핵심 : 바꾸기전에 값을 기억하는 게 아니라, 인덱스의 값을 다루다가, swap할 때 그 인덱스의 해당하는 값을 swap함.
#include <iostream>
#include <algorithm>

#define max_size 1000

using namespace std;
void selectionSort(int arr[], int n);

int main(){
    int t; // t는 testcase 갯수
    cin >> t;
    while(t--){
        int n; // n은 입력받을 정수의 총 갯수
        cin >> n;
        int arr[max_size];
        for(int i =0; i<n; ++i){
            cin >> arr[i];
        }
        selectionSort(arr, n);
    }
    return 0;
}

void selectionSort(int arr[], int n){
    int compareExecution = 0;
    int swapExecution = 0;
    
    for(int i = 0 ; i < n-1; i++){
        int minIndex = i;

        for(int j = i+1 ; j<n; j ++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
                // compareExecution++;
            }
            compareExecution++;
        }

        if(minIndex != i){
            swap(arr[minIndex], arr[i]);
            swapExecution++;
        }
    }
    cout << compareExecution << " " << swapExecution << endl;
}