#include <iostream>
#include <string>
#include <vector>
#include "hashTable.hpp"

using namespace std;


// -------Item--------

Item::Item(int k, string n):
key(k),
name(n),
isDeleted(false)
{}

Item::Item(int k, string n, bool d):
key(k),
name(n),
isDeleted(d)
{}

// -------Table--------

HashTable::HashTable()
{
  table.resize(10, nullptr);
  itemCount=0;
}

int HashTable::hash(int key)
{
  return ((key+7)%(table.size()-1));
}

Item* HashTable::find(int key)
{
  int checkKey = hash(key);
  Item* item = table[checkKey];
  while(item)
  {
    if(item->key == key)
    {
      if(item->isDeleted)
        return nullptr;
      return item;
    }
    checkKey = hash(checkKey);
    item = table[checkKey];
  }
  return nullptr;
}

bool HashTable::insert(int key, string data)
{
  Item insItem(key, data);
  return insert(insItem);
}

bool HashTable::insert(Item item)
{
  if(itemCount >= table.size()/2)
    rehash();
  itemCount++;
  int probe = hash(item.key);
  while(true)
  {
    Item* probeItem = probeItem;
    if(probeItem == nullptr)
    {
      probeItem = &item;
      return true;
    }
    else
    {
      if(item.key == probeItem->key)
      {
        if(probeItem->isDeleted)
        {
          probeItem = &item;
          return true;
        }
        else
        {
          return false;
        }
      }
    }
    probe = hash(probe);
  }
}

void HashTable::remove(int key)
{
  int probeKey = hash(key);
  Item* probeItem = table[probeKey];
  while(probeItem != nullptr)
  {
    if(probeItem->key == key){
      probeItem->isDeleted = true;
      return;
    }
    probeKey = hash(probeKey);
    probeItem = table[probeKey];
  }
}

bool isin(int num, const vector<int>& arr)
{
  for(unsigned int i=0; i<arr.size(); i++)
  {
    if (num==arr[i])
      return true;
  }
  return false;
}

void HashTable::rehash()
{
  vector<int> hashedKeys(itemCount, -1);
  unsigned int size = table.size();
  table.resize(size*2, nullptr);
  unsigned int itemsHashed=0;
  for(unsigned int i=0; i<size && itemsHashed<itemCount; i++)
  {
    if(table[i])
    {
      Item* item = table[i];
      if(item->isDeleted)
      {
        table[i] = nullptr;
        delete(item);
      }
      else if(!isin(item->key, hashedKeys))
      {
        table[i] = nullptr;
        itemCount--;
        insert(*item);
        hashedKeys.push_back(item->key);
        itemsHashed++;
      }
    }
  }
}

void HashTable::printTable()
{
  cout << "Key, Name, IsDeleted\n";
  for(unsigned int i=0; i<table.size(); i++)
  {
    Item* item = table[i];
    if(item)
    {
      cout << item->key << ", " << item->name << ", " << item->isDeleted << endl;
    }
    else
    {
      cout << "0, No Item, 0\n";
    }
  }
}
