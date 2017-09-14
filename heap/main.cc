// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "./priority_queue.h"

using namespace std;  // NOLINT

template <class T, class cmp = std::greater<T>>
bool comparar(T a1, T a2, cmp compare = cmp()) {
  return compare(a1,a2);
}

int main() {
  PriorityQueue<pair<int, string>> mypq(50);
  mypq.push(make_pair(30, "Thirty"));
  mypq.push(make_pair(100, "One hundred"));
  mypq.push(make_pair(25, "Twenty five"));
  mypq.push(make_pair(40, "Fourty"));

  std::cout << "Popping out elements..." << endl;
  while (!mypq.empty()) {
     std::cout << mypq.top().first << ", ";
     mypq.pop();
  }
  std::cout << '\n';

  cout << comparar(9,7) << endl;
  return 0;
}


