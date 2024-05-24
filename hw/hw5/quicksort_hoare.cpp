#include <iostream>
#include <vector>

using namespace std;

void quicksort(int m, vector<int> &A, int low, int high, int &scount, int &ccount);
int partition_Hoare(vector<int> &A, int low, int high, int &scount, int &ccount);
int partition_Lomuto(vector<int> &A, int low, int high, int &scount, int &ccount);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tmp;

        vector<int> a1(1000), a2(1000);
        int h_scount = 0, h_ccount = 0, l_scount = 0, l_ccount = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a1[i] = a2[i] = tmp;
        }
        quicksort(0, a1, 0, n - 1, h_scount, h_ccount);
        quicksort(1, a2, 0, n - 1, l_scount, l_ccount);

        cout << h_scount << " " << l_scount << " " << h_ccount << " " << l_ccount << endl;
    }

    return 0;
}

void quicksort(int m, vector<int> &A, int low, int high, int &scount, int &ccount)
{
    if (low >= high)
    {
        return;
    }
    int p; // pivot
    if (m == 0)
    {
        p = partition_Hoare(A, low, high, scount, ccount);
        quicksort(m, A, low, p, scount, ccount);
        quicksort(m, A, p + 1, high, scount, ccount);
    }
    else
    {
        p = partition_Lomuto(A, low, high, scount, ccount);
        quicksort(m, A, low, p - 1, scount, ccount);
        quicksort(m, A, p + 1, high, scount, ccount);
    }
}

int partition_Hoare(vector<int> &A, int low, int high, int &scount, int &ccount)
{
    int i, j;
    int pivot = A[low];
    i = low - 1;
    j = high + 1;
    while (1) {
        do { i++; ccount++; } while (A[i] < pivot);
        do { j--; ccount++; } while (A[j] > pivot);
        if (i < j) {
            scount++;
            swap(A[i], A[j]);
        } else
            return j;
    }
}

int partition_Lomuto(vector<int> &A, int low, int high, int &scount, int &ccount)
{
    int pivot = A[low];
    int j;
    j = low;
    for (int i = low + 1; i < high + 1; i++)
    {
        ccount++;
        if (A[i] < pivot)
        {
            j++;
            scount++;
            swap(A[i], A[j]);
        }
    }
    scount++;
    swap(A[j], A[low]);
    return j;
}
