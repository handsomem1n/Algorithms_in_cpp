// n개의 정수 a(1) ~ a(n)이 주어졌을 때, 연속적인 부분수열의 합 최대가 되는 구간(i, j)과 그 구간의 합을 계산
// 'a(1) + a(2) + a(3) == 시그마 n은 1부터 2까지 a(n) + a(3)'라는 아이디어를 통해 반복문의 갯수를 줄임.
// time complexity = big - O(n^2)
#include <iostream>

using namespace std;

int maxSubsequenceSum(int a[], int n, int *start, int *end);

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int start, end;
    int maxSum = maxSubsequenceSum(a, n, &start, &end);

    cout << maxSum << endl;
    cout << start << ' ' << end << endl;

    return 0;
}

int maxSubsequenceSum(int a[], int n, int *start, int *end)
{
    int maxSum = 0;

    *start = *end - 1;

    for (int i = 0; i < n; i++)
    {
        int thisSum = 0;
        for (int j = i; j < n; j++)
        {
            thisSum += a[j];
            if (thisSum > maxSum)
            {
                maxSum = thisSum;
                *start = i;
                *end = j;
            }
        }
    }
    return maxSum;
}