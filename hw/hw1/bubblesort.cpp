// 간과하기 쉬운부분 : 맨오른쪽이 정렬되므로 그 부분은 compare할필요가 없어진다.
#include <iostream>
#include <algorithm>

#define max_size 1000

using namespace std;
void bubbleSort(int arr[], int n);
void improvedBS1(int arr[], int n);
void improvedBS2(int arr[], int n);
int main()
{
    int t; // t는 testcase 갯수
    cin >> t;
    while (t--)
    {
        int n; // n은 입력받을 정수의 총 갯수
        cin >> n;
        int arr[max_size];
                int backup[max_size];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            backup[i] = arr[i];
        }
        bubbleSort(arr, n);

        for (int i = 0; i < n; ++i)
            arr[i] = backup[i];
        improvedBS1(arr, n);

        for (int i = 0; i < n; ++i)
            arr[i] = backup[i];
        improvedBS2(arr, n);
    }
    return 0;
}

void bubbleSort(int arr[], int n)
{
    int compareExecution = 0;
    int swapExecution = 0;
    for (int j = n; j > 1; j--) // j>2가 아님
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapExecution++;
            }
            compareExecution++;
        }
        i = 0;
        n--;
    }
    cout << compareExecution << " " << swapExecution << " ";
}

void improvedBS1(int arr[], int n)
{
    bool swapped;
    int compareExecution1 = 0;
    int swapExecution1 = 0;
    for (int j = n; j > 1; j--) // j>2가 아님
    {
        swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapExecution1++;
                swapped = true;
            }
            compareExecution1++;
        }
        int i = 0;
        n--;
        if (swapped == false){
            break;
        }
    }
    cout << compareExecution1 << " " << swapExecution1 << " " ;
}

void improvedBS2(int arr[], int n)
{
    int compareExecution2 = 0;
    int swapExecution2 = 0;
    int lastSwappedIndex = n - 1; // 마지막으로 교환된 위치를 저장하는 변수
    while (lastSwappedIndex > 0)
    {
        int tempSwappedIndex = 0; // 이번 패스에서 마지막으로 교환된 위치를 임시로 저장하는 변수

        for (int i = 0; i < lastSwappedIndex; i++) // lastSwappedIndex까지만 비교를 수행
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapExecution2++;
                tempSwappedIndex = i; // i 위치에서 교환 발생, i를 임시로 저장
            }
            compareExecution2++;
        }

        lastSwappedIndex = tempSwappedIndex; // 임시 저장한 위치를 lastSwappedIndex로 업데이트
    }

    cout << compareExecution2 << " " << swapExecution2 << endl;
}
