// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "hash_table.h"
#include <string>

using std::cout;
using std::endl;
using std::string;

size_t djb2(string str) {
  unsigned long hash = 5381;
    for (char c : str) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash;
}

int main() {
  HashTable<string,int> table(5);
  cout << "\nSize: " << table.size() << endl;

  cout << "\nAdding items\n"<< endl;

  table.add("John Smith",1218976);
  table.add("Lisa Williams",2211234);
  table.add("Sam Doe",3219655);
  table.add("Sandra Dee",4184165);
  table.add("Ted Baker",5215030);

  table.print_debug();

  cout << "\nUpdate some values\n" << endl;

  table.add("John Smith",-1218976);
  table.add("Sandra Dee",-4184165);

  table.print_debug();


  cout << "\nGetting values\n" << endl;

  cout << "John Smith: " << table.get("John Smith") << endl;
  cout << "Lisa Williams: " << table.get("Lisa Williams") << endl;
  cout << "Sam Doe: " << table.get("Sam Doe") << endl;
  cout << "Sandra Dee: " << table.get("Sandra Dee") << endl;
  cout << "Ted Baker: " << table.get("Ted Baker") << endl;

  cout << "\nChecking if a item exists\n" << endl;

  cout << "Ted Baker: " << std::boolalpha << table.exists("Ted Baker") << endl;
  cout << "Alice Brown: " << std::boolalpha << table.exists("Alice Brown") << endl;

  cout << "\nRemove items\n" << endl;

  table.remove("Sam Doe");
  table.remove("Ted Baker");
  table.remove("John Smith");
  table.remove("Sandra Dee");
  table.remove("Lisa Williams");


  table.print_debug();

  cout << endl;

  return 0;
}


