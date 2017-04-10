#include <iostream>
#include <fstream>
#include "bst.hpp"

int main()
{
  Tree myTree();
  myTree.insert(50);
  myTree.insert(23);
  myTree.insert(60);
  myTree.printTree();
  return 0;
}
