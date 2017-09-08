// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

// Reference Image : https://screenshots.firefoxusercontent.com/images/54290b3c-a80a-411c-9d05-fe951f3bd30f.png

#ifndef _HOME_OSCAR_PRACTICES_CPP_QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_H_
#define _HOME_OSCAR_PRACTICES_CPP_QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_H_

#include <iostream>
#include "node.h"

template <typename T>
class Queue {
 public:
  Queue() : rear(nullptr) {}
  Queue(const Queue&) = delete;
  Queue operator=(const Queue&) = delete;
  ~Queue();

  inline bool is_empty() {return rear == nullptr;}
  void enqueue(const T &val);
  T dequeue();

 private:
  Node<T> *rear;
};

template <typename T>
void Queue<T>::enqueue(const T &val) {
  Node<T> *new_node = new Node<T>(val);
  if (is_empty()) {
    rear = new_node;
    new_node->set_next(new_node);
  } else {
    new_node->set_next(rear->next());  // newest node points at oldest node
    rear->set_next(new_node);  // previous newest node points at newest node
    rear = new_node;
  }
}

template <typename T>
T Queue<T>::dequeue() {
  Node<T> *oldest_node = rear;
  T oldest_value = oldest_node->value();

  if (rear != rear->next()) {
    oldest_node = rear->next();  // because newest node points to oldest node
    oldest_value = oldest_node->value();
    rear->set_next(oldest_node ->next());  // newest node points new oldest node
  } else {
    rear = nullptr;
  }
  delete oldest_node;
  return oldest_value;
}

template <typename T>
Queue<T>::~Queue() {
  if (!is_empty()) {
    Node<T> *current = rear->next();
    while (current != rear) {
      Node<T> *prev = current;
      current = current->next();
      delete prev;
    }
    delete rear;
  }
}


#endif  // _HOME_OSCAR_PRACTICES_CPP_QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_H_
