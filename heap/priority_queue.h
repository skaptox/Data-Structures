// Copyright (c) 2017 Oscar Albornoz.

// Binary search tree
// Visualitation: https://www.cs.usfca.edu/~galles/visualization/BST.html

#ifndef HEAP_PRIORITY_QUEUE_H_
#define HEAP_PRIORITY_QUEUE_H_

#include <assert.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>


using std::cout;
using std::endl;

template <typename T>
void heapify(T* array, int size,
  const std::function<bool(T&, T&)> &cmp = std::greater<T>());

template <typename T>
void heap_sort(T* array,
  const std::function<bool(T&, T&)> &cmp = std::greater<T>());

template <typename T>
class PriorityQueue {
 public:
  explicit PriorityQueue(int capacity,
    const std::function<bool(T&, T&)> &cmp = std::greater<T>()) :
    capacity_(capacity), size_(0), array_(new T[capacity]), cmp_(cmp) {}

  PriorityQueue() = delete;
  PriorityQueue(const PriorityQueue&) = delete;
  PriorityQueue operator=(const PriorityQueue&) = delete;

  ~PriorityQueue() {delete [] array_;}

  const T& pop();

  inline bool empty() const noexcept {return size_ == 0;}
  inline const T& top() const noexcept {return *array_;}
  inline int size() const noexcept {return size_;}

  void push(const T &value);
  void print();
  void remove(int index);


  static void sift_down(T* array, int index, int end,
    const std::function<bool(T&, T&)> &cmp  = std::greater<T>());

  static void sift_up(T* array, int index,
    const std::function<bool(T&, T&)> &cmp  = std::greater<T>());

 private:
  int capacity_, size_;
  T *array_;
  std::function<bool(T&, T&)> cmp_;
};

template <typename T>
void PriorityQueue<T>::push(const T &value) {
  assert(size_ < capacity_);
  array_[size_] = value;
  sift_up(array_, size_++, cmp_);
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
  sift_down(array_, index, size_ - 1, cmp_);
}

template <typename T>
const T& PriorityQueue<T>::pop() {
  assert(!empty());

  size_--;
  std::swap(array_[0], array_[size_]);
  sift_down(array_, 0, size_ - 1, cmp_);
  return array_[size_];
}

template <typename T>
void PriorityQueue<T>::sift_up(T* array, int child,
const  std::function<bool(T&, T&)> &cmp) {
  int parent;
  while ((parent = (child-1) >> 1) >= 0 && cmp(array[child], array[parent])) {
    std::swap(array[child], array[parent]);
    child = parent;
  }
}

template <typename T>
void PriorityQueue<T>::sift_down(T * array, int parent, int end,
const std::function<bool(T&, T&)> &cmp) {
  int left_child, right_child, greater_child;

  while ((left_child = (parent << 1) + 1) <= end) {
    right_child = left_child + 1;

    if (right_child > end)  // If does't have right children
      right_child = left_child;

    if (cmp(array[right_child], array[left_child]))  // Choise greater child
      greater_child = right_child;
    else
      greater_child = left_child;

    if (cmp(array[parent], array[greater_child]))
      break;

    cout << "P: " << array[parent] << endl;
    cout << "Gc: " << array[greater_child] << endl;
    std::swap(array[parent], array[greater_child]);
    parent = greater_child;
  }
}

template <typename T>
void heapify(T* array, int size, const std::function<bool(T&, T&)> &cmp) {
  cout << "aqui" << endl;
  for (int i = size / 2 - 1; i >= 0; --i) {
    PriorityQueue<T>::sift_down(array, i, size - 1, cmp);
    for (int i = 0; i < size; ++i) {
      cout << array[i] << ", ";
    }
    cout << endl;
  }
}

template <typename T>
void heap_sort(T* array, const std::function<bool(T&, T&)> &cmp) {
}


#endif  // HEAP_PRIORITY_QUEUE_H_


