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
  table.resize(10);
  itemCount=0;
  for (unsigned int i=0; i<table.size(); i++)
  {
    table[i] = nullItem();
  }
}

Item HashTable::nullItem()
{
  return nullItem();
}

int HashTable::hash(int key)
{
  return ((key+7)%(table.size()-1));
}

Item HashTable::find(int key)
{
  int checkKey = hash(key);
  Item item = table[checkKey];
  while(item.key!=0)
  {
    if(item.key == key)
    {
      if(item.isDeleted)
        return nullItem();
      return item;
    }
    checkKey = hash(checkKey);
    item = table[checkKey];
  }
  return nullItem();
}

bool HashTable::insert(int key, string data)
{
  if(itemCount >= table.size()/2)
    rehash();
  itemCount++;
  Item item(key, data);
  int probe = hash(key);
  while(true)
  {
    Item probeItem = table[probe];
    if(probeItem.key == 0)
    {
      table[probe] = item;
      cout << table[probe].name << endl;
      return true;
    }
    else
    {
      if(key == probeItem.key)
      {
        if(probeItem.isDeleted)
        {
          table[probe] = item;
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

// bool HashTable::insert(Item item)
// {
//   if(itemCount >= table.size()/2)
//     rehash();
//   itemCount++;
//   int probe = hash(item.key);
//   while(true)
//   {
//     Item* probeItem = table[probe];
//     if(probeItem == nullptr)
//     {
//       cout << "probe null" << endl;
//       table[probe] = new Item(key, data);
//       cout << table[probe]->name << endl;
//       return true;
//     }
//     else
//     {
//       if(item.key == probeItem->key)
//       {
//         if(probeItem->isDeleted)
//         {
//           table[probe] = &item;
//           return true;
//         }
//         else
//         {
//           return false;
//         }
//       }
//     }
//     probe = hash(probe);
//   }
// }

void HashTable::remove(int key)
{
  if(key == 0)
    return;
  int probeKey = hash(key);
  Item probeItem = table[probeKey];
  while(probeItem.key != 0)
  {
    if(probeItem.key == key){
      probeItem.isDeleted = true;
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
  table.resize(size*2);
  for (unsigned int i=size; i<size*2; i++)
  {
    table[i] = nullItem();
  }
  unsigned int itemsHashed=0;
  for(unsigned int i=0; i<size && itemsHashed<itemCount; i++)
  {
    if(table[i].key != 0)
    {
      Item item = table[i];
      if(item.isDeleted)
      {
        table[i] = nullItem();
      }
      else if(!isin(item.key, hashedKeys))
      {
        table[i] = nullItem();
        itemCount--;
        insert(item.key, item.name);
        hashedKeys.push_back(item.key);
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
    Item item = table[i];
    if(item.key != 0)
    {
      cout << item.key << ", " << item.name << ", " << item.isDeleted << endl;
    }
    else
    {
      cout << "0, No Item, 1\n";
    }
  }
}
