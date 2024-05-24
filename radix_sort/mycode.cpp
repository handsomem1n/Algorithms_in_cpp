#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countdigit(int k){ // 자릿수 개수
    int count = 1;
    while (k>=10){
        k = k/10;
        count ++;
    }
    return count;
}

int comparing(const vector<int> &arr) {
    int n = countdigit(arr[0]); // 백의자리숫자면 3
    int startcomparing = 1;
    if (n<=1){
        return startcomparing;
    }
    else if (n >= 2) {
        for (int i = 0; i<n ; i++ ){ // n번동안 10곱함
            startcomparing = startcomparing*10;
        }
    }
    return startcomparing;
}

void radix_sort(vector<int> &arr) {
    // int n = countdigit(arr[0]); // 백의자리숫자면 3
    int startcomparing = comparing(n); // 백의자리숫자면 100스타트

    int elements = arr.size(); // 원소의 갯수

    vector<queue<int>> buckets(10);

    while(n--){ // n(=자릿수개수)번동안 비교.
        
        for (int i =0 ; i < elements; i++){
            int digit = arr[i] % startcomparing
            buckets[digit].push(arr[i]);
        }

        int idx = 0;
        for (auto &bucket : buckets) {
            while (!bucket.empty()) {
                arr[idx++] = bucket.front();
                bucket.pop();
            }
        }
    }

}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radix_sort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}