// Copyright (c) 2017 Oscar Albornoz.

#ifndef _HOME_OSCAR_PRACTICES_CPP_VECTOR_VECTOR_H_
#define _HOME_OSCAR_PRACTICES_CPP_VECTOR_VECTOR_H_

#include <math.h>
#include <iostream>

namespace sk {

static const int kGrowthFactor = 2;
static const int kMinCapacity = 16;
static const int kShrinkFactor = 4;

template<typename T>
class Vector {
 public:
  Vector();
  explicit Vector(const size_t &capacity);
  Vector(const Vector &) = delete;
  Vector operator=(const Vector &) = delete;
  ~Vector() { delete [] array_;}

  inline bool is_empty() const {return size_ == 0;}
  inline size_t capacity() const {return capacity_;}
  inline size_t size() const {return size_;}

  int find(const T &val) const;

  T at(const size_t &index) const;
  T pop();

  void erase(const size_t &index);
  void insert(const size_t &index, const T &val);
  void prepend(const T &val);
  void push(const T &val);
  void remove(const T &val);
  template<typename F>
  void remove_if(F function);

 private:
  T *array_;
  size_t capacity_;
  size_t size_;
  void increase_size();
  void decrease_size();
  void resize();
};

template<typename T>
Vector<T>::Vector() : array_(new T[kMinCapacity]), capacity_(kMinCapacity),
 size_(0) {}

template<typename T>
Vector<T>::Vector(const size_t &capacity) : size_(0) {
  if (capacity > kMinCapacity) {
    capacity_ = pow(2, ceil((log2(capacity))));
    capacity_ *= 2;
  } else {
    capacity_ = kMinCapacity;
  }
  array_ = new T[capacity_];
}

template<typename T>
T Vector<T>::at(const size_t &index) const {
  if (index < size_) {
    return *(array_ + index);
  } else {
    std::cerr << "Error: Vector index out of range" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template<typename T>
void Vector<T>::decrease_size() {
  if (capacity_ / kGrowthFactor >= kMinCapacity) {
    capacity_ /= kGrowthFactor;
    resize();
  }
}

template<typename T>
void Vector<T>::erase(const size_t &index) {
  if (!is_empty()) {
    if (index < size_) {
      size_--;
      for (int i = index; i < size_; ++i)
        *(array_ + i) = *(array_ + i + 1);
    } else if (index == 0) {
      size_--;
    } else {
      std::cerr << "Error: Vector index out of range" << std::endl;
      exit(EXIT_FAILURE);
    }
  } else {
    std::cerr << "Error: Vector is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (size_ && capacity_ / size_ > kShrinkFactor) {
    decrease_size();
  }
}

template<typename T>
int Vector<T>::find(const T &val) const {
  for (int i = 0; i < size_; ++i) {
    if (*(array_ + i) == val) {
      return i;
    }
  }
  return -1;
}

template<typename T>
void Vector<T>::increase_size() {
  capacity_ *= kGrowthFactor;
  resize();
}

template<typename T>
void Vector<T>::insert(const size_t &index, const T &val) {
  if (size_ == capacity_) {
    increase_size();
  }
  if (index < size_) {
    for (int i = size_; i > index; i--) {
      *(array_ + i) = *(array_ + i - 1);
    }
    *(array_ + index) = val;
    size_++;
  } else {
    std::cerr << "Error: Vector index out of range" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template<typename T>
T Vector<T>::pop() {
  T val;
  if (!is_empty()) {
    size_--;
    val = *(array_ + size_);
  } else {
    std::cerr << "Error: Vector is empty" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (size_ && capacity_ / size_ > kShrinkFactor) {
    decrease_size();
  }

  return val;
}

template<typename T>
void Vector<T>::prepend(const T &val) {
  if (size_ == capacity_) {
    increase_size();
  }
  for (int i = size_; i > 0; i--) {
    *(array_ + i) = *(array_ + i - 1);
  }
  *(array_) = val;
  size_++;
}

template<typename T>
void Vector<T>::push(const T &val) {
  if (size_ == capacity_) {
    increase_size();
  }
  *(array_ + size_) = val;
  size_++;
}

template<typename T>
void Vector<T>::resize() {
  T *new_array = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    *(new_array+i) = *(array_+i);
  }
  delete [] array_;
  array_ = new_array;
}

template<typename T>
void Vector<T>::remove(const T &val) {
  int index;
  while ((index = find(val)) != -1) {
    erase(index);
  }

  if (size_ && capacity_ / size_ > kShrinkFactor) {
    decrease_size();
  }
}

template<typename T>
template<typename F>
void Vector<T>::remove_if(F function) {
  for (int i = 0; i < size_; ++i) {
    if (function(*(array_ + i))) {
      erase(i--);  // redo
    }
  }
  if (size_ && capacity_ / size_ > kShrinkFactor) {
    decrease_size();
  }
}



}  // namespace sk

#endif  // _HOME_OSCAR_PRACTICES_CPP_VECTOR_VECTOR_H_
