// Copyright (c) 2017 Oscar Albornoz.

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_

#include <iostream>
#include <queue>

using std::cout;
using std::endl;

template <typename T>
struct BstNode {
  T value;
  BstNode *left;
  BstNode *right;
  BstNode(T val,BstNode * l = nullptr, BstNode * r = nullptr) :
    value(val), left(l), right(r) {}
};

template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree() : root_(nullptr) {}
  BinarySearchTree(const BinarySearchTree &) = delete;
  BinarySearchTree operator=(const BinarySearchTree &) = delete;
  ~BinarySearchTree() {}

  BstNode<T>* insert(const T &value);  // insert value into tree iteratively
  void put(const T &value);  // insert value into tree recursively

  size_t size();
  void print_bfs();  // Breadth-first traversal.
  BstNode<T>* find(const T &value);
  void height();
  T min();
  T max();
  void remove(const T &value);
 private:
  BstNode<T> *root_;
  BstNode<T>* insert(BstNode<T>*& root,const T &value);
  BstNode<T>* min_node(BstNode<T>* root);
  BstNode<T>* max_node(BstNode<T>* root);
  BstNode<T>* get_parent(BstNode<T>* node);

  size_t count(const BstNode<T>* root);
};

// Private functions

template <typename T>
size_t BinarySearchTree<T>::count(const BstNode<T>* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + count(root->left) + count(root->right);
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::insert(BstNode<T>*& root ,const T &value) {
  if (root == nullptr) {
    return root = new BstNode<T>(value);
  }
  if (value < root->value) {
    return insert(root->left,value);
  } else if (value > root->value) {
    return insert(root->right,value);
  }
  return nullptr;  // Not inserted
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_parent(BstNode<T>* node) {
  BstNode<T> *parent = root_;
  while (parent && parent->left != node && parent->right != node) {
    parent = node->value < parent->value ? parent->left : parent->right;
  }

  if (!parent) {
    return root_;
  }

  return parent;
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::min_node(BstNode<T>* root) {
  BstNode<T> *node = root;
  while(node->left) {
    node = node->left;
  }
  return node;
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::max_node(BstNode<T>* root) {
  BstNode<T> *node = root;
  while(node->right) {
    node = node->right;
  }
  return node;
}

// Public functions

template <typename T>
T BinarySearchTree<T>::min() {
  return min_node(root_)->value;
}

template <typename T>
T BinarySearchTree<T>::max() {
  return max_node(root_)->value;
}

template <typename T>
void BinarySearchTree<T>::remove(const T &value) {
  BstNode<T> *node = find(value);
  BstNode<T> *node_parent = get_parent(node);


  if (node->left && node->right) {
    // Node to be removed has two children.
    BstNode<T> *min = min_node(node->right);
    BstNode<T> *min_parent = get_parent(min);

    node->value = min->value;

    if (node == min_parent)
      node->right = min->right;
    else
      min_parent->left = min->left;

    delete min;
  } else if (node->left || node->right) {
    //Node to be deleted has only one child: remove the node and replace it with its child.

    if (node == root_)
      root_ = root_->left ? root_->left : root_->right;
    else if (node == node_parent->left)  // If is left child
      node_parent->left = node->left ? node->left : node->right;
    else // If is left child
      node_parent->right = node->left ? node->left : node->right;

    delete node;

  } else {
    // Node to be deleted is leaf: Simply remove from the tree.

    if (node == node_parent->left)  // If is left child
      node_parent->left = nullptr;
    else
      node_parent->right = nullptr; // If is left child
    if (node == root_)
      root_ = nullptr;
    delete node;
  }
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::find(const T &value) {
  BstNode<T> *node = root_;
  while (node) {
    if (node->value == value) {
      return node;
    }
    node = value < node->value ? node->left : node ->right;
  }
  return node; // No founded nullptr
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
      if (node->left == nullptr) {
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
void BinarySearchTree<T>::put(const T &value) {
  insert(root_,value);
}

template <typename T>
void BinarySearchTree<T>::print_bfs() {
  if (!root_)
    return;
  std::queue<BstNode<T>*> queue({root_});
  while(!queue.empty()) {
    BstNode<T>* root = queue.front();
    queue.pop();
    cout << root->value << ", ";
    if (root->left)
      queue.push(root->left);
    if (root->right)
      queue.push(root->right);
  }
  cout << endl;
}

template <typename T>
size_t BinarySearchTree<T>::size() {
  return count(root_);
}
#endif  // BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
