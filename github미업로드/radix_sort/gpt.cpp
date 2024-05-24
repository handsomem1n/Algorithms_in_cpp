#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int getMaxDigit(const vector<int> &arr) {
    int maxDigits = 0;
    for (int num : arr) {
        int digits = 0;
        while (num != 0) {
            num /= 10;
            digits++;
        }
        maxDigits = max(maxDigits, digits);
    }
    return maxDigits;
}
void radix_sort(vector<int> &arr) {
    int maxDigit = getMaxDigit(arr);  // 최대 자릿수를 계산하는 함수 필요
    int exp = 1;

    for (int d = 0; d < maxDigit; d++) {
        vector<queue<int>> buckets(10);

        for (int i = 0; i < arr.size(); i++) {
            int bucketIndex = (arr[i] / exp) % 10;
            buckets[bucketIndex].push(arr[i]);
        }

        int idx = 0;
        for (auto &bucket : buckets) {
            while (!bucket.empty()) {
                arr[idx++] = bucket.front();
                bucket.pop();
            }
        }

        exp *= 10;
    }
}



int main() {
    vector<int> arr = {170, 145, 175, 190, 102, 124, 112, 166};
    radix_sort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
