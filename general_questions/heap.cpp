#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;
public:
    MinHeap() {}

    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
    }

    int top()
    {
        return heap[1];
    }

    void heapifyUp(int idx)
    {
        if (idx == 1) return;
        int parent = idx / 2;

        if (heap[parent] > heap[idx])
        {
            swap(heap[parent], heap[idx]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int idx)
    {
        int left = idx * 2;
        int right = idx * 2 + 1;

        int child = left;
        if (left < heap.size() && right < heap.size() && heap[left] > heap[right])
        {
            child = right;
        }
        if (child < heap.size() && heap[child] < heap[idx])
        {
            swap(heap[idx], heap[child]);
            heapifyDown(child);
        }
    }
};

int main()
{
    MinHeap heap;

    heap.push(6);                   // [6]
    heap.push(2);                   // [2, 6]
    heap.push(5);                   // [2, 5, 6]
    cout << heap.top() << endl;     // 2
    heap.push(1);                   // [1, 2, 5, 6]
    heap.push(3);                   // [1, 2, 3, 5, 6]
    cout << heap.top() << endl;     // 1
    heap.pop();                     // [2, 3, 5, 6]
    cout << heap.top() << endl;     // 2
    heap.pop();                     // [3, 5, 6]
    cout << heap.top() << endl;     // 3
    heap.push(0);                   // [0, 3, 5, 6]
    cout << heap.top() << endl;     // 0
    heap.pop();                     // [3, 5, 6]
    heap.pop();                     // [5, 6]
    cout << heap.top() << endl;     // 5
}