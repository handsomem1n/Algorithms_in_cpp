#include <iostream>
#include <vector>
#include <cmath> // log2 함수를 사용하기 위해 필요



using namespace std;

void heapify_recur(vector<int>& heap, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // 왼쪽 자식이 현재 노드보다 크면 largest를 왼쪽 자식으로 설정
        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }

        // 오른쪽 자식이 현재 노드보다 크면 largest를 오른쪽 자식으로 설정
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        // 현재 노드가 가장 큰 경우 루프를 종료
        if (largest == i) {
            break;
        }

        // 가장 큰 노드와 현재 노드를 교환하고 반복
        swap(heap[i], heap[largest]);
        i = largest; // 업데이트된 서브트리에 대해 다시 검사
    }
}

void printHeap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); ++i)
        cout << heap[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> heap = {4, 10, 3, 5, 1};
    cout << "original Heap: \n";

    int n = heap.size();
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify_recur(heap, n, i);
    }
    printHeap(heap);
    buildHeap(heap);

    cout << "Constructed Heap: \n";
    printHeap(heap);

    return 0;
}
