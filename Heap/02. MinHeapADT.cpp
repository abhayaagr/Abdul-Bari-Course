#include <bits/stdc++.h>
using namespace std;

template <class T>
class minHeap {
private:
    vector<T> heap;
    void heapifyUp(int index);          // Time - O(log n) | Space - O(1)
    void heapifyDown(int index);        // Time - O(log n) | Space - O(1)

public:
    void insert(T key);                 // Time - O(log n) | Space - O(1)
    T deleteRoot();                     // Time - O(log n) | Space - O(1)
    void display();                     // Time - O(n) | Space - O(1)
};

template <class T>
void minHeap<T>::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] < heap[parent]) {
        swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

template <class T>
void minHeap<T>::heapifyDown(int index) {
    int size = heap.size();
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] < heap[smallest])  
        smallest = leftChild;
    if (rightChild < size && heap[rightChild] < heap[smallest])  
        smallest = rightChild;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

template <class T>
void minHeap<T>::insert(T key) {
    heap.push_back(key);
    heapifyUp(heap.size() - 1);
}

template <class T>
T minHeap<T>::deleteRoot() {
    if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    T x = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return x;
}

template <class T>
void minHeap<T>::display() {
    for (const T &val : heap)
        cout << val << " ";
    cout << endl;
}

int main() {
    minHeap<int> h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(25);
    h.insert(5);
    h.insert(40);
    h.insert(35);
    h.display();
    cout<<h.deleteRoot()<<endl;
    h.display();
    return 0;
}
