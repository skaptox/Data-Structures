// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#ifndef _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_OBJECT_H_
#define _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_OBJECT_H_

#include <iostream>

template<typename TKey, typename TValue>
class HashObject {
 public:
  HashObject() : key_(0), value_(0), next_(nullptr) {}
  HashObject(const TKey &k, const TValue &v) : key_(k), value_(v),
  next_(nullptr) {}

  HashObject(const HashObject<TKey, TValue>&) = delete;
  HashObject operator=(const HashObject<TKey, TValue>&) = delete;

  ~HashObject() {}
  inline TKey key() const { return key_;}
  inline TValue value() const { return value_;}
  inline HashObject<TKey, TValue>* next() const {return next_;}

  void set_value(const TValue &v) {value_ = v;}
  void set_next(HashObject<TKey, TValue> *n) { next_ = n;}
 private:
  TKey key_;
  TValue value_;
  HashObject *next_;
};

#endif  // _HOME_OSCAR_PRACTICES_CPP_HASH_TABLE_HASH_OBJECT_H_
