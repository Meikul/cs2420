#include <iostream>
#include <fstream>
#include "hashTable.hpp"
using namespace std;

int toInt(string str);

int main()
{
  HashTable inventory;
  inventory.printTable();
  inventory.insert(6520, "Apples");
  inventory.insert(3340, "Mini Bananas");
  inventory.insert(2414, "Durian");
  inventory.insert(2093, "Beets");
  
  inventory.printTable();
  
  inventory.remove(3340);
  inventory.insert(7782, "Starfruit");
  inventory.insert(3323, "Dragonfruit");
  inventory.printTable();
  return 0;
}

int toInt(string str)
{
  int out=0;
  for(unsigned int it=0; it<str.length(); it++)
  {
    int cur = (int)str[it];
    if(cur > 47 && cur < 58)
      out+=(cur-48)*(10*(str.length()-1));
    else
      return -1;
  }
  return out;
}
