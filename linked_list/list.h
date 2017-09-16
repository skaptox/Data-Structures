// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

// Singly Linked List
// Reference Image: http://www.cs.usfca.edu/~srollins/courses/cs112-f07/web/notes/linkedlists/ll2.gif

#ifndef LINKED_LIST_LIST_H_
#define LINKED_LIST_LIST_H_

#include <iostream>
#include <utility>
#include "./node.h"

template<typename T>
class List {
 public:
  List() : head_(nullptr), tail_(nullptr), size_(0) {}
  ~List();
  inline bool is_empty() const {return size_ == 0;}
  inline size_t size() const {return size_;}
  inline T back() const { return tail_->value(); }
  inline T front() const { return head_->value(); }

  T& at(size_t pos);
  void erase(size_t pos);
  void insert(size_t pos, const T &val);
  void pop_back();
  void pop_front();
  void push_back(const T &val);
  void push_front(const T &val);
  void reverse();

 private:
  Node<T> *head_;
  Node<T> *tail_;
  size_t size_;
};

template<typename T>
T& List<T>::at(size_t pos) {
  if (pos < size()) {
    Node<T> *current = head_;
    for (int i = 0; i < pos && current->next(); ++i) {
      current = current->next();
    }
    return current->value();

  } else {
    std::cerr << "Error: List index out of range" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template<typename T>
void List<T>::erase(size_t pos) {
  if (pos < size()) {
    if (pos == 0) {
      pop_front();
    } else if (pos == size()- 1) {
      pop_back();
      } else {
        Node<T> *prev = head_;

        for (int i = 1; i < pos && prev->next(); ++i)
          prev = prev->next();

        Node<T> *current = prev->next();
        prev->set_next(current->next());

        delete current;
        size_--;
      }
  } else {
     std::cerr << "Error: List index out of range" << std::endl;
     exit(EXIT_FAILURE);
  }
}

template<typename T>
void List<T>::insert(size_t pos, const T &val) {
    if (pos < size()) {
      if (pos == 0) {
        push_front(val);
      } else {
        Node<T> *prev = head_;

        for (int i = 1; i < pos && prev->next(); ++i)
          prev = prev->next();

        Node<T> *new_node = new Node<T>(val);

        new_node->set_next(prev->next());
        prev->set_next(new_node);
        size_++;
      }
    } else {
       std::cerr << "Error: List index out of range" << std::endl;
       exit(EXIT_FAILURE);
    }
  }

template<typename T>
void List<T>::pop_back() {
  if (!is_empty()) {
    Node<T> *prev = head_;
    while (prev->next() && prev->next() != tail_) {
      prev = prev->next();
    }
    delete tail_;
    tail_ = prev;
    tail_->set_next(nullptr);
    size_--;
  } else {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template<typename T>
void List<T>::pop_front() {
  if (!is_empty()) {
    Node<T> *first_node = head_;

    head_ = head_->next();
    delete first_node;
    size_--;

  } else {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template<typename T>
void List<T>::push_back(const T &val) {
    Node<T> *new_node = new Node<T>(val);

    if (is_empty()) {
      head_ = tail_ = new_node;  // Both point to single node
    } else if (head_ == tail_) {
        head_->set_next(new_node);  // First node point to second node
        tail_ = head_->next();  // Tail point to second node
      } else {
        tail_->set_next(new_node);  // Last node point to new last node
        tail_ = tail_->next();  // Tail point to new last node
        }
    size_++;
  }

template<typename T>
void List<T>::push_front(const T &val) {
  Node<T> *new_node = new Node<T>(val);

  if (is_empty()) {
    tail_ = new_node;
  } else {
    new_node->set_next(head_);
  }

  head_ = new_node;
  size_++;
}

template<typename T>
void List<T>::reverse() {
  Node<T> *current = head_;
  Node<T> *prev = nullptr;

  while (current) {
    Node<T> *next = current->next();
    current->set_next(prev);
    prev = current;
    current = next;
  }
  std::swap(head_, tail_);
}

template<typename T>
List<T>::~List() {
  if (!is_empty()) {
    Node<T> *prev = head_;
    while (prev) {
      Node<T> *current = prev->next();
      delete prev;
      prev = current;
    }
  }
}

#endif  // LINKED_LIST_LIST_H_



