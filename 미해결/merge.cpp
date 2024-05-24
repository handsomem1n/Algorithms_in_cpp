#include<iostream>

using namespace std;

#define MAX_SIZE 1000

int comparisonCount;

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int tmp[MAX_SIZE];

    for (i = low; i <= high; i++){
        tmp[i] = a[i];
    }    
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        comparisonCount++;
        if (tmp[i] <= tmp[j]){
            a[k++] = tmp[i++];
        }
        else{
            a[k++] = tmp[j++];
        }
    }
    while (i <= mid){
        a[k++] = tmp[i++];
    }
    while (j <= high){
        a[k++] = tmp[j++];
    }
}

void mergesort(int v[], int low, int high) {
    if (low == high){
        return; // 이게 base case
    }
    
    int mid = (low + high) / 2;
    mergesort(v, low, mid);
    mergesort(v, mid+1, high);
    merge(v, low, mid, high);
}

int main() {
    int t, n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        int v[MAX_SIZE];
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        comparisonCount = 0;
        mergesort(v, 0, n-1);

        cout << comparisonCount << endl;
    }
    
    return 0;
}
