#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Item
{
  Item(int key, string name);
  Item(int key, string name, bool isDel);
  int key;
  string name;
  bool isDeleted;
};

class HashTable
{
private:
  int hash(int key);
  vector<Item> table;
  unsigned int itemCount;
  Item nullItem();
public:
  HashTable();
  bool insert(int key, string data);
  Item find(int key);
  void remove(int key);
  void rehash();
  void printTable();
};

#endif
