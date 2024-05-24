// 강제 형변환
// gap = 1일때 bubblesort + gap = 0으로 종료조건 맞춰주어 더이상 반복되지않게 하기.
#include <iostream>
#include <algorithm>

#define max_size 1000

using namespace std;
void combSort(int arr[], int n);

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
        combSort(arr, n);
    }
    return 0;
}

void combSort(int arr[], int n){
    int compareExecution = 0;
    int swapExecution = 0;
    int gap = (int)(n / 1.3); // 강제 형변환.
    // 한번에 시행 이후
    while(gap >= 1){
        for(int i = 0 ; i < n - gap ; i++){
            if(arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapExecution++;
            }
            compareExecution++;
        }

        gap = (int)(gap / 1.3);

        if(gap == 1){
            for(int i = 0 ; i < n-1; i ++){ // i < n이 아님
                if(arr[i] > arr[i+1]){
                    swap(arr[i], arr[i+1]);
                    swapExecution++;
                }
                compareExecution++;
            }
            gap = 0; // // 한 번 Bubble Sort 후에는 갭을 0으로 설정하여 루프를 종료    
        }
                if(gap == 0){
            for(int i = 0 ; i < n-1; i ++){ // i < n이 아님
                if(arr[i] > arr[i+1]){
                    swap(arr[i], arr[i+1]);
                    swapExecution++;
                }
                compareExecution++;
            }
        }


    }
    cout << compareExecution << " " << swapExecution << endl;
}

// void combSort(int arr[], int n){
//     int compareExecution = 0;
//     int swapExecution = 0;
//     int gap = n;
//     bool swapped = true;

//     while (gap != 1 || swapped == true){
//         gap = (int)(gap / 1.3);
//         if (gap < 1) // Minimum gap should be 1
//             gap = 1;

//         swapped = false;

//         for(int i = 0 ; i < n - gap ; i++){
//             if(arr[i] > arr[i+gap]){
//                 swap(arr[i], arr[i+gap]);
//                 swapExecution++;
//                 swapped = true;
//             }
//             compareExecution++;
//         }
//     }

//     cout << compareExecution << " " << swapExecution << endl;
// }