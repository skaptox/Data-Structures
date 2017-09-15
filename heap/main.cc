// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "./priority_queue.h"

using namespace std;  // NOLINT

template<typename T>
void print_queue(T& q) {
  while (!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }
  std::cout << '\n';
}

int main() {
  PriorityQueue<int> q(10);

  for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
      q.push(n);
  }

  cout << "\nQueue 1 Max Heap" << endl;
  cout << "Max: " << q.top() << endl;
  print_queue(q);

  PriorityQueue<int, std::greater<int> > q2(10);

  for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
      q2.push(n);

  cout << "\nQueue 2 Min Heap" << endl;
  cout << "Min: " << q2.top() << endl;
  print_queue(q2);

  // Using lambda to compare elements.
  auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
  PriorityQueue<int, decltype(cmp)> q3(10, cmp);

  for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
      q3.push(n);

  cout << "\nQueue 3 lambda" << endl;
  cout << "Top: " << q3.top() << endl;
  print_queue(q3);

  cout << endl;
  return 0;
}


