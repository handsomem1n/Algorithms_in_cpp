#include <iostream>
#include <cstring>
using namespace std;

const int LENGTH = 1001;

void computeFailFunction(char pattern[], int m, int failarr[])
{
    failarr[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = failarr[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        failarr[i] = j;
    }
}

int main()
{
    char text[LENGTH], pattern[LENGTH];
    cin >> text >> pattern;
    int n = strlen(text);
    int m = strlen(pattern);
    int failarr[LENGTH];

    computeFailFunction(pattern, m, failarr);

    for (int i = 0; i < m; i++)
    {
        cout << failarr[i] << " ";
    }
    cout << endl;

    int j = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = failarr[j - 1];
        }
        if (text[i] == pattern[j])
        {
            if (j == m - 1)
            {
                r++;
                j = failarr[j];
            }
            else
            {
                j++;
            }
        }
    }
    cout << r << endl;
    return 0;
}
