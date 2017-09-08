// Copyright (c) 2016 John Washam.
// https://github.com/jwasham/practice-cpp/blob/master/queue_linked_list/tests/queue_llist_tests.cc

#include <assert.h>
#include <iostream>
#include "../queue_linked_list.h"

void run_all_tests();
void test_empty();
void test_enqueue();
void test_dequeue();

void run_all_tests() {
  test_empty();
  test_enqueue();
  test_dequeue();
}

void test_empty() {
  Queue<int> q;

  assert(q.is_empty());

  q.enqueue(3);

  assert(!q.is_empty());
}

void test_enqueue() {
  Queue<double> q;

  q.enqueue(12.3);
  q.enqueue(4.235);
  q.enqueue(5.4);
  q.enqueue(7.0);
  q.enqueue(885314.32214);

  assert(!q.is_empty());
}

void test_dequeue() {
  Queue<int> q;

  q.enqueue(100);
  q.enqueue(200);
  assert(q.dequeue() == 100);
  q.enqueue(300);
  assert(q.dequeue() == 200);
  q.enqueue(400);
  q.enqueue(500);
  q.enqueue(600);
  q.enqueue(700);
  assert(q.dequeue() == 300);
  assert(q.dequeue() == 400);
  assert(q.dequeue() == 500);
  assert(q.dequeue() == 600);
  assert(q.dequeue() == 700);

  assert(q.is_empty());
}