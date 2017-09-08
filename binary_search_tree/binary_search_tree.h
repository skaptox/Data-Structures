// Copyright (c) 2017 Oscar Albornoz.

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_

#include <iostream>

template <typename T>
struct BstNode {
  T data;
  BstNode *left;
  BstNode *right;
};

template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree();
  ~BinarySearchTree();
};

#endif  // BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
