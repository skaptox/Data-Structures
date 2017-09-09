// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "./binary_search_tree.h"
#include <string>

using std::cout;
using std::endl;
using std::string;


int main() {
  BinarySearchTree<float> bst;
  bst.insert(9);
  bst.insert(5);
  bst.insert(2);
  bst.insert(7);
  bst.insert(1);
  bst.insert(4);
  bst.insert(8);
  bst.insert(6);
  bst.insert(3);
  bst.insert(11);
  bst.insert(12);
  bst.insert(10);
  bst.insert(8.5);
  bst.insert(0.5);
  bst.insert(0);

  bst.print_bfs();

/*
  cout << "Size: " << bst.size() << endl;
  cout << "Find 31: " << (bst.find(31) != nullptr) << endl;
  cout << "Find min: " << bst.min() << endl;
  cout << "Find max: " << bst.max() << endl;

*/
   bst.remove(5);


   bst.remove(6);
   bst.print_bfs();
   bst.remove(2);
   bst.print_bfs();
   bst.remove(11);
   bst.print_bfs();
   bst.remove(10);
   bst.print_bfs();
   bst.remove(7);
   bst.print_bfs();
   bst.remove(9);
   bst.print_bfs();
   bst.remove(1);
   bst.print_bfs();
   bst.remove(3);
   bst.print_bfs();
   bst.remove(12);
   bst.print_bfs();
   bst.remove(0.5);
   bst.print_bfs();
   bst.remove(8);
   bst.print_bfs();
   bst.remove(8.5);
   bst.print_bfs();
   bst.remove(4);
   bst.print_bfs();
   bst.remove(0);
   bst.print_bfs();

   cout << "hola" << endl;
   bst.print_bfs();


  return 0;
}


