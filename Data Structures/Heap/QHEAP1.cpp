#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(vector<int> &heap, int x, int y) {
    int temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
}

int getParentIndex(int index) {return (index - 1) / 2;}
int getLeftChildIndex(int index) {return (index * 2) + 1;}
int getRightChildIndex(int index) {return (index * 2) + 2;}

void addToHeap(vector<int> &heap, int x) {
    heap.push_back(x);
    int size = heap.size();
    int index = size - 1;
    while (index > 0 && heap[index] < heap[ (getParentIndex(index)) ]) {
        swap(heap, index, getParentIndex(index));
        index = getParentIndex(index);
    }

}

int searchX(vector<int> &heap, unsigned root, int x) {
    if (root >= heap.size())
        return -1;
    if (x == heap[root])
        return root;
    int foundInLeft = searchX(heap, getLeftChildIndex(root), x);
    if (foundInLeft > -1)
        return foundInLeft;    
    return searchX(heap, getRightChildIndex(root), x);
}

void sink(vector<int> &heap, int index) {
    int last = heap.size()-1;
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);

    int swapIndex = index;

    if (left <= last && heap[left] < heap[swapIndex])
      swapIndex = left;

    if (right <= last && heap[right] < heap[swapIndex])
      swapIndex = right;

    if (index == swapIndex)
        return;

    swap(heap, index, swapIndex);
    sink(heap, swapIndex);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    vector<int> heap;
    while (Q--) {
        int type;
        cin >> type;
        switch (type) {
            case 1: { // add element(x) to heap
                int x;
                cin >> x;
                addToHeap(heap, x);
                break;
            }
            case 2: { // delete element(x) from heap
                int x;
                cin >> x;
                int index = searchX(heap, 0, x);
                swap(heap, index, heap.size()-1);
                heap.pop_back();
                sink(heap, index);
                break;
            }
            case 3: { // print minimum element in heap
                cout << heap[0] << endl;
                break;
            }
        }
    }
    // for (unsigned i = 0; i < heap.size(); i++)
    //     cout << heap[i] << " ";
    return 0;
}
