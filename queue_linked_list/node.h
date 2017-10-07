// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#ifndef QUEUE_LINKED_LIST_NODE_H_
#define QUEUE_LINKED_LIST_NODE_H_

template <typename T>
class List;

template<typename T>
class Node {
 public:
  Node() : value_(0) , next_(nullptr) {}
  explicit Node(T v, Node* n = nullptr) : value_(v), next_(n) {}
  ~Node() {}
  inline T& value() {return value_;}
  inline Node* next() { return next_; }
  inline void set_value(T *val) {value_ = val;}
  inline void set_next(Node *elem) {next_ = elem;}
  friend class List<T>;

 private:
  T value_;
  Node *next_;
};

#endif  // QUEUE_LINKED_LIST_NODE_H_
