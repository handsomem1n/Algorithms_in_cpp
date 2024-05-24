// merge sort (!= iterative)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

void merge(vector<int>& a, int low, int mid, int high, int& count);
void mergeSort(vector<int>& a, int& count);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, count = 0;
        cin >> n;

        vector<int> a(MAX_SIZE);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        mergeSort(a, count);
        cout << count << endl;
    }
    return 0;
}


void mergeSort(vector<int>& a, int& count) {
    int n = a.size();
    for (int size = 1; size < n; size = size * 2) {
        for (int i = 0; i < n; i = i + 2 * size) {
            int low = i;
            int mid = min(low + size - 1, n - 1);
            int high = min(i + 2 * size - 1, n - 1);

            merge(a, low, mid, high, count);
        }
    }
}

void merge(vector<int>& a, int low, int mid, int high, int& count) {
    int i, j, k;
    vector<int> tmp(a.begin() + low, a.begin() + high + 1);

    i = k = low;
    j = mid + 1;
    
    while((i <= mid) && (j <= high)) {
        count++;
        if (tmp[i - low] <= tmp[j - low]){
            a[k++] = tmp[i++ - low];
        }
            
        else{
            a[k++] = tmp[j++ - low];
        }
    }

    while(i <= mid){
        a[k++] = tmp[i++ - low];
    }
    
    while(j <= high){
        a[k++] = tmp[j++ - low];
    }
}

