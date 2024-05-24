#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    cout << "heapify_result : " << endl;
    printArray(arr);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);
    return 0;
}
