// Copyright (c) 2016 John Washam.
// https://github.com/jwasham/practice-cpp/blob/master/arrays/jvector_test.h

#ifndef PROJECT_JVECTOR_TEST_H
#define PROJECT_JVECTOR_TEST_H

#include "../vector.h"

namespace jw {

class JVectorTest {
 public:
  void RunTests() const;
  void TestSize() const;
  // Tests increases and decreases in capacity based on number of items stored.
  void TestCapacity() const;
  void TestIsEmpty() const;
  void TestGetValueAt() const;
  void TestPop() const;
  void TestInsert() const;
  void TestPrepend() const;
  void TestDelete() const;
  void TestRemove() const;
  void TestFind() const;
};


  void JVectorTest::RunTests() const {
  TestSize();
  TestIsEmpty();
  TestCapacity();
  TestGetValueAt();
  TestPop();
  TestInsert();
  TestPrepend();
  TestDelete();
  TestRemove();
  TestFind();
};

void JVectorTest::TestSize() const {
  sk::Vector<int> tester(3);
  assert(tester.size() == 0);

  int items_to_add = 5;
  for (int i = 0; i < items_to_add; ++i) {
    tester.push(i + 1);
  }
  assert(tester.size() == items_to_add);
}

void JVectorTest::TestIsEmpty() const {
  sk::Vector<int> tester(3);
  assert(tester.is_empty());
}

void JVectorTest::TestCapacity() const {
  sk::Vector<int> tester(4);

  // test increasing size
  assert(tester.capacity() == sk::kMinCapacity);


  for (int i = 0; i < 17; ++i) {
    tester.push(i + 1);
  }

  assert(tester.capacity() == sk::kMinCapacity * 2);
  for (int j = 0; j < 20; ++j) {
    tester.push(j + 1);
  }
  assert(tester.capacity() == sk::kMinCapacity * 4);

  // test decreasing size
  for (int k = 0; k < 30; ++k) {
    tester.pop();
  }
  assert(tester.capacity() == sk::kMinCapacity * 2);

  for (int k = 0; k < 7; ++k) {
    tester.pop();
  }
  assert(tester.capacity() == sk::kMinCapacity);
}

void JVectorTest::TestGetValueAt() const {
  sk::Vector<int> tester(3);
  tester.push(4);
  tester.push(9);
  tester.push(12);
  assert(tester.at(0) == 4);
  assert(tester.at(1) == 9);
  assert(tester.at(2) == 12);
}

void JVectorTest::TestPop() const {
  sk::Vector<int> tester(1);
  tester.push(3);

  int popped = tester.pop();
  assert(popped == 3);
  tester.push(9);
  tester.push(8);

  assert(tester.size() == 2);
  int popped2 = tester.pop();
  assert(popped2 == 8);
  assert(tester.size() == 1);
}

void JVectorTest::TestInsert() const {
  sk::Vector<int> tester(3);
  tester.push(5);
  tester.push(7);
  tester.push(9);
  tester.insert(0, 4);
  assert(tester.at(0) == 4);
  assert(tester.at(1) == 5);
  assert(tester.at(2) == 7);
  assert(tester.at(3) == 9);
  tester.insert(3, 8);
  assert(tester.at(3) == 8);
  assert(tester.at(4) == 9);
}

void JVectorTest::TestPrepend() const {
  sk::Vector<int> tester(3);
  tester.push(9);
  tester.push(8);
  tester.push(7);
  tester.prepend(6);
  assert(tester.size() == 4);
  assert(tester.at(0) == 6);
  assert(tester.at(1) == 9);
  assert(tester.at(3) == 7);
}

void JVectorTest::TestDelete() const {
  sk::Vector<int> tester(1);
  tester.push(5);
  tester.erase(0);
  assert(tester.size() == 0);

  tester.push(9);
  tester.push(10);
  tester.push(11);
  tester.erase(1);
  assert(tester.size() == 2);
  assert(tester.at(0) == 9);
  assert(tester.at(1) == 11);
}

void JVectorTest::TestRemove() const {
  sk::Vector<int> tester(5);
  tester.push(50);
  tester.push(2);
  tester.push(50);
  tester.push(4);
  tester.push(50);
  tester.remove(50);
  assert(tester.size() == 2);
  assert(tester.at(0) == 2);
  assert(tester.at(1) == 4);
}

void JVectorTest::TestFind() const {
  sk::Vector<int> tester(3);
  tester.push(4);
  tester.push(7);
  tester.push(11);
  assert(tester.find(5) == -1);
  assert(tester.find(4) == 0);
  assert(tester.find(7) == 1);
  assert(tester.find(11) == 2);
}

}  // namespace jw

#endif // PROJECT_JVECTOR_TEST_H