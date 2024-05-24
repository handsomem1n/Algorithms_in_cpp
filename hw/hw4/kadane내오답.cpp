/*
최대가 되는 구간이 여러 개이면 구간의 시작 index 가 가장 작은 구간을 출력.
또한 같은 시작 index 인 구간이 여러 개인 경우에는 가장 짧은 구간을 출력.
    위의 두 가지를 만족하기위해선, 이전의 maxsum값과 같으면 update를 하지 않으면 됨.

구간이 시작되는 정수가 0 이어서는 안된다.


최대 구간의 합이 음수인 경우에는 최대합을 0 으로 출력하고, 구간의 시작 index 와 종료 index를 모두 -1 로 출력
*/

#include <iostream>
using namespace std;

int MCSS(int a[], int n, int *start, int *end);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int start, end;
        int maxSum = MCSS(a, n, &start, &end);

        // maxsum이 음수일떄 start, end가 -1, -1 (MCSS 안에는 포인터변수기에 -1로 지정이 불가하므로 메인함수안에)
        if (maxSum < 0)
        {
            maxSum = 0;
            start = -1;
            end = -1;
        }

        cout << maxSum << ' ' << start << ' ' << end << endl;
    }
    return 0;
}

int MCSS(int a[], int n, int *start, int *end)
{
    int maxSum = -1;
    int thisSum = 0;
    *start = 0;
    *end = 0;

    int i = 0;
    int j = 0;

    while (j < n)
    {
        if (a[j] != 0)
        {
            thisSum += a[j];

            if (thisSum > maxSum)
            {
                maxSum = thisSum;
                *start = i;
                *end = j;
            }

            else if (thisSum < 0)
            {
                i = j + 1;
                thisSum = 0;
            }

            else if ( thisSum == 0){ // 같은 시작 index 인 구간이 여러 개인 경우에는 가장 짧은 구간을 출력.
                i = j + 1;
            }

            j++;
        }

        else if(a[j] == 0)
        {
            // i = j + 1;
            i++;
            j++;
        }
    }
    return maxSum;
}
