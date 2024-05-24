#include <iostream>
#include <climits> // INT_MAX

#define MAX_LENGTH 101

using namespace std;

int minmult(int n, const int d[], int P[][MAX_LENGTH]);
int minindex(int l[], int len);
void order(int P[][MAX_LENGTH], int i, int j);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int d[MAX_LENGTH];

        cin >> n;

        for (int i = 0; i < n + 1; i++)
        {
            cin >> d[i];
        }

        int P[MAX_LENGTH][MAX_LENGTH];
        int r = minmult(n, d, P);

        order(P, 0, n - 1);
        
        cout << r << endl;
    }
    return 0;
}

int minmult(int n, const int d[], int P[][MAX_LENGTH])
{
    int M[MAX_LENGTH][MAX_LENGTH] = {0};
    for (int diagonal = 1; diagonal < n; diagonal++)
    {
        for (int i = 0; i < n - diagonal; i++)
        {
            int j = i + diagonal;
            int len = j - i;
            int l[MAX_LENGTH];

            for (int k = i; k < j; k++)
            {
                l[k - i] = M[i][k] + M[k + 1][j] + ((d[i] * d[k + 1]) * d[j + 1]);
            }
            int index = minindex(l, len);

            M[i][j] = l[index];
            P[i][j] = index + i;
        }
    }

    return M[0][n - 1];
}

void order(int P[][MAX_LENGTH], int i, int j)
{
    if (i == j)
    {
        cout << "M" << i + 1;
    }

    else
    {
        int k = P[i][j];
    }
}

int minindex(int l[], int len)
{
    int index = 0;
    int r = INT_MAX;

    for (int i = 0; i < len; i++)
    {
        if (r > l[i])
        {
            index = i;
            r = l[i];
        }
    }
    return index;
}
