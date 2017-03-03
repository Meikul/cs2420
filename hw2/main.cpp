#include "BinTree.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  BinTree tree();
  tree.preorderBuild("prog2in.txt");
  tree.printTree();
  return 0;

  // This is an update.
}
