#include <iostream>
#include <vector>

using namespace std;

void heapify_iter(vector<int> &heap, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }

    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(heap[i], heap[largest]);

        heapify_iter(heap, n, largest);
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
        heapify_iter(heap, n, i);
    }
    printHeap(heap);

    cout << "Constructed Heap: \n";
    printHeap(heap);

    return 0;
}