// Copyright (c) 2017 Oscar Albornoz.

// Heap
// Visualitation: https://visualgo.net/en/heap

#ifndef HEAP_PRIORITY_QUEUE_H_
#define HEAP_PRIORITY_QUEUE_H_

#include <assert.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>

using std::cout;
using std::endl;

template <typename T, typename Comp = std::less<T>>
class PriorityQueue {
 public:
  explicit PriorityQueue(int capacity, const Comp &cmp = Comp()) :
    capacity_(capacity), size_(0), array_(new T[capacity]), cmp_(cmp) {}

  PriorityQueue() = delete;
  PriorityQueue(const PriorityQueue&) = delete;
  PriorityQueue operator=(const PriorityQueue&) = delete;
  ~PriorityQueue() {array_.reset();}

  const T& pop();
  inline bool empty() const noexcept {return size_ == 0;}
  inline const T& top() const noexcept {return array_[0];}
  inline int size() const noexcept {return size_;}
  void print();
  void push(const T &value);
  void remove(int index);

 private:
  int capacity_, size_;
  std::unique_ptr<T[]> array_;
  Comp cmp_;

  void sift_down(int index, int end, const Comp &cmp = Comp());
  void sift_up(int index, const Comp &cmp = Comp());
};

template <typename T, typename Comp>
void PriorityQueue<T, Comp>::print() {
  for (int i = 0; i < size_; ++i) {
    cout << array_[i] << ", ";
  }
  cout << endl;
}

template <typename T, typename Comp>
void PriorityQueue<T, Comp>::push(const T &value) {
  assert(size_ < capacity_);
  array_[size_] = value;
  sift_up(size_++, cmp_);
}

template <typename T, typename Comp>
void PriorityQueue<T, Comp>::remove(int index) {
  assert(index < 0 && index >= size_);
  swap(array_[index], array_[--size_]);
  sift_down(index, size_ - 1, cmp_);
}

template <typename T, typename Comp>
const T& PriorityQueue<T, Comp>::pop() {
  assert(!empty());

  size_--;
  std::swap(array_[0], array_[size_]);
  sift_down(0, size_ - 1, cmp_);
  return array_[size_];
}

template <typename T, typename Comp>
void PriorityQueue<T, Comp>::sift_up(int child, const Comp &cmp) {
  int parent;
  while ((parent = (child-1) >> 1) >= 0 && cmp(array_[parent], array_[child])) {
    std::swap(array_[child], array_[parent]);
    child = parent;
  }
}

template <typename T, typename Comp>
void PriorityQueue<T, Comp>::sift_down(int parent, int end, const Comp &cmp) {
  int left_child, right_child, swappable_child;

  while ((left_child = (parent << 1) + 1) <= end) {
    right_child = left_child + 1;

    if (right_child > end)
      right_child = left_child;

    swappable_child = cmp(array_[right_child], array_[left_child]) ?
      left_child : right_child;

    if (cmp(array_[swappable_child], array_[parent]))
      break;

    std::swap(array_[parent], array_[swappable_child]);
    parent = swappable_child;
  }
}

#endif  // HEAP_PRIORITY_QUEUE_H_


