// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

int main() {
  List<int> my_list;

  cout << "Testing push_front: ";
  for (int i = 1; i <= 5; ++i)
     my_list.push_front(i);

  for (int i = 0; i < my_list.size(); ++i)
    cout << my_list.at(i);
  cout <<  endl;

  cout << "Testing pop_front and front: ";
  while (!my_list.is_empty()) {
    cout << my_list.front();
    my_list.pop_front();
  }
  cout << " Is list empty? " << std::boolalpha << my_list.is_empty();
  cout <<  endl;

  cout << "Testing push_back: ";
  for (int i = 1; i <= 5; ++i)
     my_list.push_back(i);

  for (int i = 0; i < my_list.size(); ++i)
    cout << my_list.at(i);
  cout <<  endl;

  cout << "Testing pop_back and back: ";
  while (!my_list.is_empty()) {
    cout << my_list.back();
    my_list.pop_back();
  }
  cout << " Is list empty? " << std::boolalpha << my_list.is_empty();
  cout <<  endl;

  cout << "Testing insert: ";
  for (int i = 1; i <= 5; i+=2)
     my_list.push_back(i);

  cout << "Before: ";

  for (int i = 0; i < my_list.size(); ++i)
    cout << my_list.at(i);

  cout << " After: ";

  my_list.insert(1, 2);
  my_list.insert(3, 4);

  for (int i = 0; i < my_list.size(); ++i)
    cout << my_list.at(i);
  cout <<  endl;

  cout << "Testing erase: ";
  while (my_list.size() - 1)
    my_list.erase(1);
  my_list.erase(0);

  cout << "Is list empty? " << std::boolalpha << my_list.is_empty();
  cout <<  endl;

  cout << "Fill using push front and push back \n";

  for (int i = 1; i <= 5; ++i) {
    my_list.push_front(i);
    my_list.push_back(i);
  }

  cout << "List contains: ";
  for (int i = 0; i < my_list.size(); ++i)
    cout << my_list.at(i);

  cout << "..the destructor will delete them!" << endl;

  return 0;
}


