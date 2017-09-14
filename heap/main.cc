// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "./priority_queue.h"

using namespace std;  // NOLINT

int main() {
  string num[10] = {"zero", "one", "two", "three", "four", "five", "six",
  "seven", "eight", "nine"};

  const int size = 6;
  int arr[size] = {1,2,3,4,5,6};

  heapify(arr, size);
  cout << "Heapify: " << endl;
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << ", ";
  }


  /*

  PriorityQueue<pair<int, string>> mypq(50,
    [](const pair<int, string> &o1, const pair<int, string> &o2)
    { return o1.first > o2.first;});

  for (int i = 0; i < 10; ++i) {
    mypq.push(make_pair(i, num[i]));
  }

  std::cout << "Popping out elements..." << endl;
  while (!mypq.empty()) {
     std::cout << mypq.top().first << ", ";
     mypq.pop();
  }

   */
  std::cout << '\n';


  return 0;
}


