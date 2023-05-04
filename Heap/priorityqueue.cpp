#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
  std::vector<int> heapTree;
  
  void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
  }

  void heapify(int i) {
    int size = heapTree.size();

    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && heapTree[l] > heapTree[largest])
      largest = l;
    if (r < size && heapTree[r] > heapTree[largest])
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(heapTree[i], heapTree[largest]);
      heapify(largest);
    }
  }

public:
  PriorityQueue() {}

  void insert(int newNum) {
    int size = heapTree.size();
    if (size == 0) {
      heapTree.push_back(newNum);
    } else {
      heapTree.push_back(newNum);
      for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
      }
    }
  }

  int getMax() {
    int size = heapTree.size();
    if (size == 0) {
      throw "Priority queue is empty";
    }
    int max = heapTree[0];
    heapTree[0] = heapTree[size-1];
    heapTree.pop_back();
    heapify(0);
    return max;
  }

  bool isEmpty() {
    return heapTree.size() == 0;
  }

  int getSize() {
    return heapTree.size();
  }
};


int main() {
  PriorityQueue pq;

  pq.insert(3);
  pq.insert(4);
  pq.insert(9);
  pq.insert(5);
  pq.insert(2);

  std::cout << "Max element: " << pq.getMax() << std::endl;
  std::cout << "Max element: " << pq.getMax() << std::endl;

  pq.insert(7);

  std::cout << "Queue size: " << pq.getSize() << std::endl;
  std::cout << "Max element: " << pq.getMax() << std::endl;

  while (!pq.isEmpty()) {
    std::cout << pq.getMax() << " ";
  }
  std::cout << std::endl;

  return 0;
}



