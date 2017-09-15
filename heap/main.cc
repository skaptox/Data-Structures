// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "./priority_queue.h"

using namespace std;  // NOLINT

template<typename T>
void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();

    }
    std::cout << '\n';
}

int main() {
    PriorityQueue<int> q(10);

    for(int n : {1,8,5,6,3,4,0,9,7,2}) {
        q.push(n);
    }

    print_queue(q);

    PriorityQueue<int, std::greater<int> > q2(10);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);

    print_queue(q2);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
    PriorityQueue<int, decltype(cmp)> q3(10,cmp);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);

    cout << "Sorting array: " << endl;
    int arr[10] = {1,8,5,6,3,4,0,9,7,2};
    heap_sort(arr,10,[](int f,int s){return f>s;});
    for (int i = 0; i < 10; ++i) {
      cout << arr[i] << ", ";
    }

    cout << endl;




  return 0;
}


