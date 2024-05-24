#include <iostream>
#include <string>
#define MAX_LENGTH 101

using namespace std;

int lcs(string &dst, const string &s1, const string &s2);
void getLCS(string &dst, const string &s1, const string &s2, int S[][MAX_LENGTH], int m, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2, rs;
        cin >> s1 >> s2;

        int length = lcs(rs, s1, s2);
        cout << length << " " << rs << endl;
    }

    return 0;
}

int lcs(string &dst, const string &s1, const string &s2)
{
    int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];
    int m = s1.length();
    int n = s2.length();

    for (int i = 0; i <= m; i++)
    {
        L[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        L[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else
            {
                L[i][j] = max(L[i][j - 1], L[i - 1][j]);
                if (L[i][j] == L[i][j - 1])
                {
                    S[i][j] = 1;
                }
                else
                {
                    S[i][j] = 2;
                }
            }
        }
    }

    getLCS(dst, s1, s2, S, m, n);

    return L[m][n];
}

void getLCS(string &dst, const string &s1, const string &s2, int S[][MAX_LENGTH], int m, int n)
{
    if (m == 0 || n == 0)
    {
        return;
    }
    if (S[m][n] == 0)
    {
        getLCS(dst, s1, s2, S, m - 1, n - 1);
        dst += s1[m - 1];
    }
    else if (S[m][n] == 1)
    {
        getLCS(dst, s1, s2, S, m, n - 1);
    }
    else if (S[m][n] == 2)
    {
        getLCS(dst, s1, s2, S, m - 1, n);
    }
}
