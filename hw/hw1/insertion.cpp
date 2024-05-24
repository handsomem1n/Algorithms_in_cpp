#include <iostream>
#include <algorithm>
#define max_size 1000

using namespace std;
void insertionSort(int arr[], int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[max_size];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        insertionSort(arr, n);
    }
    return 0;
}

// void insertionSort(int arr[], int n){
//     int swapExecution = 0;
//     int compareExecution = 0;
//     for(int i = 1 ; i < n; i++){
//         int tmp = arr[i];
//         int j = i;
//         compareExecution++;
//         while(j > 0 && (arr[j-1] > tmp)){
//             // for(j = i; j > 0 && arr[j-1] > tmp; j--)
//             if(arr[j-1] > tmp){
//                 compareExecution++;
//                 swap(arr[j], arr[j-1]);
//                 swapExecution++;
//             }
//             // else{
//             //     compareExecution++;
//             // }
//             j--;
//         }
        
//     }
//     cout << compareExecution << " " << swapExecution << endl;
// }

void insertionSort(int arr[], int n){
    int swapExecution = 0;
    int compareExecution = 0;
    for(int i = 1 ; i < n; i++){ // i는 정렬된 숫자 
        int tmp = arr[i];
        int j = i;
        
        while(j > 0){ // j를 통해 arr[0]까지 비교
            compareExecution++;  // 조건 검사를 할 때마다 증가
            if(arr[j-1] > tmp){
                swap(arr[j], arr[j-1]);
                swapExecution++;
                j--;
            } else {
                break;  // arr[j-1]이 tmp보다 작거나 같으면 더 이상 왼쪽으로 가지 않아도 됨
            }
        }
    }
    cout << compareExecution << " " << swapExecution << endl;
}