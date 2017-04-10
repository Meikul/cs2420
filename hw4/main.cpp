#include <iostream>
#include <fstream>
#include "hashTable.hpp"
using namespace std;

int toInt(string str);

int main()
{
  HashTable inventory;
  cout << "    After Initialization" << endl;
  inventory.printTable();
  inventory.insert(4514,"alfalfa sprouts");
  inventory.insert(4131,"apple fuji");
  inventory.insert(4133,"apple gala");
  inventory.insert(4017,"apple granny smith");
  inventory.insert(4218,"apricots");

  cout << "    Last entry before rehash" << endl;
  inventory.printTable();

  inventory.insert(3175,"beans haba dry");
  cout << "    Entry causes rehash" << endl;
  inventory.printTable();
  inventory.insert(4528,"beans haba fresh");
  inventory.insert(3173,"beans lentils");
  inventory.insert(3170,"beans peruano");
  inventory.insert(3172,"beans pinto");
  inventory.insert(3177,"beans red");
  inventory.insert(4539,"beets bunch");
  inventory.insert(4540,"beets loose");
  inventory.insert(4065,"bell pepper green");
  inventory.insert(4088,"bell pepper red");
  inventory.insert(4239,"black berries");
  inventory.insert(4545,"bok choy");
  inventory.insert(4060,"broccoli");
  inventory.insert(4550,"brussel sprouts");
  inventory.insert(4069,"cabbage green");
  inventory.insert(4556,"cabbage Napa");
  cout << "    All 20 inserted" << endl;
  inventory.printTable();

  cout << "   Finding Three" << endl;
  cout << inventory.find(4556).key << " " << inventory.find(4556).name << endl;
  cout << inventory.find(4239).key << " " << inventory.find(4239).name << endl;
  cout << inventory.find(4218).key << " " << inventory.find(4218).name << endl << endl;


  inventory.remove(4060);
  inventory.remove(4550);
  inventory.remove(3177);
  cout << "    After removing 3 (4060, 4550, and 3177)" << endl;
  inventory.printTable();



  return 0;
}
