// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#ifndef LINKED_LIST_NODE_H_
#define LINKED_LIST_NODE_H_

template<typename T>
class Node {
 public:
  explicit Node(T v, Node* n = nullptr) : value_(v), next_(n) {}
  ~Node() {}
  inline T& value() {return value_;}
  inline Node* next() { return next_; }
  inline void set_value(T *val) {value_ = val;}
  inline void set_next(Node *elem) {next_ = elem;}
 private:
  T value_;
  Node *next_;
};

#endif  // LINKED_LIST_NODE_H_
