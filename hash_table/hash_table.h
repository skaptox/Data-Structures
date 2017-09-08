// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

// Hashi Table with Chaining
// Reference Image: https://goo.gl/4DMkrH


#ifndef _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_TABLE_H_
#define _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_TABLE_H_

#include <iostream>
#include <functional>

#include "./hash_object.h"

using std::cout;
using std::endl;

template<typename TKey, typename TValue>
class HashTable {
 public:
  explicit HashTable(const size_t s, const std::function<size_t(TKey)>
    h = std::hash<TKey>());

  HashTable() = delete;
  HashTable (const HashTable<TKey, TValue>&) = delete;
  HashTable operator=(const HashObject<TKey, TValue>&) = delete;

  ~HashTable();

  inline size_t size() const {return size_;}

  bool exists(const TKey &k) const;
  HashObject<TKey, TValue>* find(const TKey &k) const;
  size_t hash(const TKey &k) const;
  TValue get(const TKey &k) const;

  void add(const TKey &k, const TValue &v);
  void print_debug() const;
  void remove(const TKey &k);

 private:
  HashObject<TKey, TValue> **data_;
  size_t size_;
  std::function<size_t(TKey)> hash_;
};

// Constructor by parameters

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable(const size_t s,
const std::function<size_t(TKey)> h) : size_(s), hash_(h) {
  data_ = new HashObject<TKey, TValue>*[size_];
}

// Add item to table (to beggining of the list because is O(1))

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::add(const TKey &k, const TValue &v) {
  HashObject<TKey, TValue>* item = find(k);

  if (item) {
    item->set_value(v);  // If key already exists, update value
  } else {
    size_t index = hash(k);
    auto *new_item = new HashObject<TKey, TValue>(k, v);

    if (!data_[index]) {  // If bucket is empty
      data_[index] = new_item;
    } else {
      new_item->set_next(data_[index]);  // Insert to the beggining of the list
      data_[index] = new_item;
    }
  }
}

// Check if is the item on the hash table

template<typename TKey, typename TValue>
bool HashTable<TKey, TValue>::exists(const TKey &k) const {
  return find(k) != nullptr;
}

// Find item on the hash table and return a pointer to it if exists

template<typename TKey, typename TValue>
HashObject<TKey, TValue>* HashTable<TKey, TValue>::find(const TKey &k)
const {
  size_t index = hash(k);
  if (data_[index]) {
    HashObject<TKey, TValue> *item = data_[index];
    while (item) {
      if (item->key() == k) {
        return item;
      }
      item = item->next();
    }
  }
  return nullptr;
}

// Get value associated with the key

template<typename TKey, typename TValue>
TValue HashTable<TKey, TValue>::get(const TKey &k) const {
  HashObject<TKey, TValue>* item = find(k);
  if (item) {
    return item->value();
  }
  return TValue();
}

// Aply the hash function to the key

template<typename TKey, typename TValue>
size_t HashTable<TKey, TValue>::hash(const TKey &k)
const {
  return hash_(k) % size_;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::print_debug() const {
  for (int i = 0; i < size_; ++i) {
    if (data_[i]) {
      HashObject<TKey, TValue> *item = data_[i];
      HashObject<TKey, TValue> *next;
      while (item) {
        next = item->next();
        cout <<"Hash:" << hash(item->key()) << " Key: " << item->key()
        << " Value: " << item->value() << endl;
        item = next;
      }
    }
  }
}

// Remove a item from the hash table if it exists

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::remove(const TKey &k) {
  size_t index = hash(k);

  if (data_[index]) {
    HashObject<TKey, TValue>* item = data_[index];
    HashObject<TKey, TValue>* prev_item = nullptr;

    while (item) {
      if (item->key() == k) {
        if (item->next()) {  // If there are least two items in the list
          if (prev_item) {  // If the item to delete is in the list's middle
            prev_item->set_next(item->next());
          } else {  // If the item to delete is the list's first
            data_[index] = item->next();
          }
        } else {
          if (item == data_[index]) {  // If there is only one element
            data_[index] = nullptr;
          } else {
            prev_item->set_next(nullptr);  // If the item to delete is the last
          }
        }
        delete item;
        return;
      }
      prev_item = item;
      item = item->next();
    }
  }
}

// Destructor

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::~HashTable() {
  for (int i = 0; i < size_; ++i) {
    if (data_[i]) {
      HashObject<TKey, TValue> *item = data_[i];
      HashObject<TKey, TValue> *next;
      while (item) {
        next = item->next();
        delete item;
        item = next;
      }
    }
  }
  delete [] data_;
}

#endif  // _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_TABLE_H_
