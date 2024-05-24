#include <iostream>
#include <algorithm>
#define max_size 1000

using namespace std;
void shellSort(int arr[], int n);

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
        shellSort(arr, n);
    }
    return 0;
}

void shellSort(int arr[], int n){
    int swapExecution = 0;
    int compareExecution = 0;

    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int tmp = arr[i];
            int j = i;

            while (j >= gap) {
                compareExecution++;  // 조건 검사를 할 때마다 증가
                if (arr[j - gap] > tmp) {
                    swap(arr[j], arr[j - gap]);
                    swapExecution++;
                    j -= gap;
                } else {
                    break;
                }
            }
        }
        gap /= 2; // half divi
    }

    cout << compareExecution << " " << swapExecution << endl;
}
