#include <iostream>
#include <string>
#define MAX_LENGTH 101

using namespace std;

int lcs(int L[MAX_LENGTH][MAX_LENGTH], string s1, string s2, int m, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int L[MAX_LENGTH][MAX_LENGTH];
        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                L[i][j] = -1;
            }
        }

        cout << lcs(L, s1, s2, s1.length(), s2.length()) << endl;
    }

    return 0;
}

int lcs(int L[MAX_LENGTH][MAX_LENGTH], string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    else if (s1[m - 1] == s2[n - 1])
    {
        if (L[m][n] == -1)
        {
            L[m][n] = lcs(L, s1, s2, m - 1, n - 1) + 1;
        }
        return L[m][n];
    }
    else
    {
        if (L[m][n] == -1)
        {
            L[m][n] = max(lcs(L, s1, s2, m - 1, n), lcs(L, s1, s2, m, n - 1));
        }
        return L[m][n];
    }
}
