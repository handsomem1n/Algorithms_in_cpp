// gap =1일때 bubblesort로 정렬 후, 그 후에도 정렬이완료되지않앗을 경우 한번 더 돌려줘야하기에 그것을 bool로 구분.
#include <iostream>
#include <algorithm>

#define max_size 1000

using namespace std;

void combSort(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[max_size];
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        combSort(arr, n);
    }
    return 0;
}

void combSort(int arr[], int n) {
    int compareExecution = 0;
    int swapExecution = 0;
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = (int)(gap / 1.3);

        if(gap < 1) {
            gap = 1;
        }

        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            compareExecution++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapExecution++;
                swapped = true;
            }
        }
    }
    cout << compareExecution << " " << swapExecution << endl;
}
