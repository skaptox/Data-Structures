// Copyright (c) 2017 Oscar Albornoz.

// Binary search tree
// Visualitation: https://www.cs.usfca.edu/~galles/visualization/BST.html

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_

#include <algorithm>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;

template <typename T>
struct BstNode {
  T value;
  BstNode *left;
  BstNode *right;
  explicit BstNode(const T &val, BstNode * l = nullptr, BstNode * r = nullptr) :
    value(val), left(l), right(r) {}
};

template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree() : root_(nullptr) {}
  BinarySearchTree(const BinarySearchTree &) = delete;
  BinarySearchTree operator=(const BinarySearchTree &) = delete;
  ~BinarySearchTree();

  BstNode<T>* find(const T &value);
  BstNode<T>* insert(const T &value);  // iteratively

  size_t height();
  size_t size();

  T max();
  T min();

  void print_bfs();  // Breadth-first traversal.
  void put(const T &value);
  void remove(const T &value);

 private:
  BstNode<T> *root_;

  BstNode<T>* get_parent(BstNode<T>* node);
  BstNode<T>* insert(BstNode<T>*& node, const T &value);  // recursivaly
  BstNode<T>* max_node(BstNode<T>* node);
  BstNode<T>* min_node(BstNode<T>* node);

  void delete_nodes(BstNode<T>* node);

  size_t count(BstNode<T>* node);
  size_t height(BstNode<T>* node);
};

// Private functions

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_parent(BstNode<T>* node) {
  BstNode<T> *parent = root_;
  while (parent && parent->left != node && parent->right != node) {
    parent = node->value < parent->value ? parent->left : parent->right;
  }
  return parent ? parent : root_;
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::insert(BstNode<T>*& node, const T &value) {
  if (node == nullptr) {
    return node = new BstNode<T>(value);
  }
  if (value < node->value) {
    return insert(node->left, value);
  } else if (value > node->value) {
    return insert(node->right, value);
  }
  return nullptr;  // Not inserted
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::max_node(BstNode<T>* root) {
  BstNode<T> *node = root;
  while (node->right) {
    node = node->right;
  }
  return node;
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::min_node(BstNode<T>* root) {
  BstNode<T> *node = root;
  while (node->left) {
    node = node->left;
  }
  return node;
}

template <typename T>
size_t BinarySearchTree<T>::count(BstNode<T>* node) {
  if (node == nullptr) {
    return 0;
  }
  return 1 + count(node->left) + count(node->right);
}

template <typename T>
void BinarySearchTree<T>::delete_nodes(BstNode<T>* node) {
  if (node->left) {
    delete_nodes(node->left);
  }
  if (node->right) {
    delete_nodes(node->right);
  }
  delete node;
}

template <typename T>
size_t BinarySearchTree<T>::height(BstNode<T>* node) {
  if (node == nullptr) {
    return 0;
  }
  return 1 + std::max(height(node->left), height(node->right));
}

// Public functions

template <typename T>
BstNode<T>* BinarySearchTree<T>::find(const T &value) {
  BstNode<T> *node = root_;
  while (node) {
    if (node->value == value) {
      return node;
    }
    node = value < node->value ? node->left : node ->right;
  }
  return node;  // No founded nullptr
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::insert(const T &value) {
  auto new_node = new BstNode<T>(value);

  if (root_ == nullptr) {  // If the tree is empty
    return root_ = new_node;
  }

  BstNode<T> *node = root_;
  while (node) {
    if (value == node->value) {  // Duplicated valor
      return nullptr;
    }
    if (value < node->value) {
      if (node->left == nullptr) {.
        return node->left = new_node;
      }
      node = node->left;
    } else {
      if (node->right == nullptr) {
        return node->right = new_node;
      }
      node = node->right;
    }
  }
  return nullptr;  // Not inserted
}

template <typename T>
size_t BinarySearchTree<T>::height() {
  return height(root_);
}

template <typename T>
size_t BinarySearchTree<T>::size() {
  return count(root_);
}

template <typename T>
T BinarySearchTree<T>::max() {
  return max_node(root_)->value;
}

template <typename T>
T BinarySearchTree<T>::min() {
  return min_node(root_)->value;
}

template <typename T>
void BinarySearchTree<T>::put(const T &value) {
  insert(root_, value);
}

template <typename T>
void BinarySearchTree<T>::print_bfs() {
  if (!root_)
    return;
  std::queue<BstNode<T>*> queue({root_});
  while (!queue.empty()) {
    BstNode<T>* node = queue.front();
    queue.pop();
    cout << node->value << ", ";
    if (node->left)
      queue.push(node->left);
    if (node->right)
      queue.push(node->right);
  }
  cout << endl;
}

template <typename T>
void BinarySearchTree<T>::remove(const T &value) {
  BstNode<T> *node = find(value);
  if (!node) return;

  BstNode<T> *node_parent = get_parent(node);
  if (node->left && node->right) {
    // Node to be removed has two children. Replace the value of the node with
    // the smaller value greater than it and delete that smaller node.

    BstNode<T> *min = min_node(node->right);
    BstNode<T> *min_parent = get_parent(min);
    node->value = min->value;

    if (node == min_parent)
      node->right = min->right;
    else
      min_parent->left = min->left;

    delete min;
  } else if (node->left || node->right) {
    // Node to be deleted has only one child: remove the node and replace
    // it with its child.
    BstNode<T> *child = node->left ? node->left : node->right;
    if (node == root_) {
      root_ = child;
    } else if (node == node_parent->left) {  // If is left child
      node_parent->left = child;
    } else {  // If is left child
      node_parent->right = child;
    }

    delete node;

  } else {
    // Node to be deleted is leaf: Simply remove from the tree.
    if (node == node_parent->left)  // If is left child
      node_parent->left = nullptr;
    else
      node_parent->right = nullptr;  // If is left child
    if (node == root_)
      root_ = nullptr;
    delete node;
  }
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  if (root_)
    delete_nodes(root_);
}

#endif  // BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
