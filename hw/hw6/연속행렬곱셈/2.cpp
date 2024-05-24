#include <iostream>
#include <climits> // INT_MAX

#define MAX_LENGTH 101

using namespace std;

int matmul(int msl[], int M[][MAX_LENGTH], int i, int j);
int min(int l[], int len);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int msl[MAX_LENGTH];
        int M[MAX_LENGTH][MAX_LENGTH] = {0,0}; // all 0
        
        cin >> n;

        for (int i = 0; i < n + 1; i++)
        {
            cin >> msl[i];
        }
        cout << matmul(msl, M, 1, n) << endl;
    }
    return 0;
}

int matmul(int msl[], int M[][MAX_LENGTH], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    else // !=
    {
        int l[MAX_LENGTH];
        int len = j - i;

        for (int k = i; k < j; k++ )
        {
            int a, b = 0;

            if (M[i][k] != 0)
            {
                a = M[i][k];
            }
            else if(M[i][k] ==0)
            { // 
                a = M[i][k] = matmul(msl, M, i, k);
            }

            if (M[k + 1][j] != 0)
            {
                b = M[k + 1][j];
            }
            else // == 0
            {
                b = M[k + 1][j] = matmul(msl, M, k + 1, j);
            }
            l[k - i] = a + b + ( (msl[i - 1] * msl[k]) * msl[j] );
        }

        return M[i][j] = min(l, len);
    }
}

int min(int l[], int len)
{
    int r = INT_MAX;

    for (int i = 0; i < len; i++)
    {
        if (r > l[i])
        {
            r = l[i];
        }
    }
    return r;
}
