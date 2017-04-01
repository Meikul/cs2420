#include <iostream>
#include <fstream>
#include "hashTable.hpp"

using namespace std;

int toInt(string str);

int main()
{
  HashTable inventory;
  string keyString;
  string word;
  ifstream fruitFile("fruit.csv");
  inventory.printTable();
  for (unsigned int i=0; (i<20)&&(getline(fruitFile, keyString, ','))&&(getline(fruitFile, word, ',')); i++)
  {
    inventory.insert(toInt(keyString),word);
  }
  
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
