// Copyright (c) 2017 Oscar Albornoz.

// Binary search tree
// Visualitation: https://www.cs.usfca.edu/~galles/visualization/BST.html

#ifndef HEAP_PRIORITY_QUEUE_H_
#define HEAP_PRIORITY_QUEUE_H_

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using std::cout;
using std::endl;

template <typename T>
void heapify(const T* array, int size);

template <typename T>
void heap_sort(const T* array);

template <typename T>
class PriorityQueue {
 public:
  explicit PriorityQueue(int capacity) : capacity_(capacity), size_(0),
  array_(new T[capacity]) {}

  PriorityQueue() = delete;
  PriorityQueue(const PriorityQueue&) = delete;
  PriorityQueue operator=(const PriorityQueue&) = delete;
  ~PriorityQueue() {delete [] array_;}

  const T& pop();

  inline bool empty() const {return size_ == 0;}
  inline const T& top() const {return *array_;}
  inline int size() const {return size_;}

  void push(const T &value);
  void print();
  void remove(int index);
  static void sift_down(T* array, int index, int end);
  void sift_up(int index);

 private:
  int capacity_, size_;
  T *array_;
};

template <typename T>
void PriorityQueue<T>::push(const T &value) {
  assert(size_ < capacity_);
  array_[size_] = value;
  sift_up(size_++);
}

template <typename T>
void PriorityQueue<T>::print() {
  for (int i = 0; i < size_; ++i) {
    cout << array_[i] << ", ";
  }
  cout << endl;
}

template <typename T>
void PriorityQueue<T>::remove(int index) {
  assert(index < 0 && index >= size_);
  swap(array_[index], array_[--size_]);
  sift_down(array_, index, size_ - 1);
}

template <typename T>
const T& PriorityQueue<T>::pop() {
  assert(!empty());

  size_--;
  std::swap(array_[0], array_[size_]);
  sift_down(array_, 0, size_ - 1);
  return array_[size_];
}

template <typename T>
void PriorityQueue<T>::sift_up(int child) {
  int parent;
  while ((parent = (child-1) >> 1) >= 0 && array_[child] > array_[parent]) {
    std::swap(array_[child], array_[parent]);
    child = parent;
  }
}

template <typename T>
void PriorityQueue<T>::sift_down(T * array, int parent, int end) {
  int left_child, right_child, greater_child;

  while ((left_child = (parent << 1) + 1) < end) {
    right_child = left_child + 1;

    if (right_child > end)
      right_child = left_child;

    if (array[left_child] >= array[right_child])
      greater_child = left_child;
    else
      greater_child = right_child;

    if (array[parent] >= array[greater_child])
      break;

    std::swap(array[parent], array[greater_child]);
    parent = greater_child;
  }
}

template <typename T>
void heapify(const T* array, int size) {
}


#endif  // HEAP_PRIORITY_QUEUE_H_


