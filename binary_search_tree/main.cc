// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "./binary_search_tree.h"
#include <string>

using std::cout;
using std::endl;
using std::string;


int main() {
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);
  bst.insert(2);
  bst.insert(4);
  bst.insert(6);
  bst.insert(8);

  bst.print_bfs();

  cout << "Size: " << bst.size() << endl;
  cout << "Find 31: " << (bst.find(31) != nullptr) << endl;
  cout << "Find min: " << bst.min() << endl;
  cout << "Find max: " << bst.max() << endl;
  cout << "Height: " << bst.height() << endl;

  cout << "Delete items" << endl;
  bst.remove(2);
  bst.remove(3);
  bst.remove(4);
  bst.remove(5);

  bst.print_bfs();




  return 0;
}


