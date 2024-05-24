// 단조증가
#include <iostream>
#include <vector>

using namespace std;

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

        int maxlen = 0, nowlen = 1;

        for (int i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1])// 단증
            { 
                nowlen++;
            }
            else// 끊김
            { 
                if (nowlen > maxlen)
                {
                    maxlen = nowlen;
                }
                nowlen = 1; 
            }
        }
        if (nowlen > maxlen)
        {
            maxlen = nowlen; 
        }

        cout << maxlen << endl;
    }

    return 0;
}
