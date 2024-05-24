// DnCMCSS.cpp보다 명료함
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int crossSum(const vector<int>& nums, int left, int mid, int right) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        left_sum = max(left_sum, sum);
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSubArrayHelper(const vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];

    int mid = (left + right) / 2;

    int left_sum = maxSubArrayHelper(nums, left, mid);
    int right_sum = maxSubArrayHelper(nums, mid + 1, right);
    int cross_sum = crossSum(nums, left, mid, right);

    return max(max(left_sum, right_sum), cross_sum);
}

int maxSubArray(const vector<int>& nums) {
    return maxSubArrayHelper(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {4, -6, 0, 2, 3, -4, 1, 3, 0, -9, 4, 1, -3, 2};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}
