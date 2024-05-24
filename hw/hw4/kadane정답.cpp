#include <iostream>
using namespace std;

int MCSS(int *arr, int n, int &start, int &end)
{
    int i, j;
    int maxSum = 0, thisSum = 0;

    start = end = -1;
    for (i = 0, j = 0; j < n; j++)
    {
        thisSum += arr[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            start = i;
            end = j;
        }
        else if (thisSum < 0)
        {
            i = j + 1;
            if (arr[i] == 0){
                i++;
            }
            thisSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int t, n, data;
    int start, end;

    cin >> t;
    while(t--)
    {
        cin >> n;
        int *arr = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> data;
            arr[j] = data;
        }
        start = 0;
        end = n - 1;

        int answer = MCSS(arr, n, start, end);

        if (answer == 0)
            cout << answer << " " << -1 << " " << -1 << endl;
        else
            cout << answer << " " << start << " " << end << endl;
    }

    return 0;
}