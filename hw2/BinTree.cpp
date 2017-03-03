#include "BinTree.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

unsigned int subSize(Node* n)
{
  if(n == NULL) return 0;
  return(subSize(n->left) + subSize(n->right) + 1);
}

unsigned int childCount(Node* n)
{
  unsigned int size = 0;
  Node* cur = n;
  while(cur->left)
  {
    size++;
    cur = cur->left;
  }
  return size;
}

void BinTree::printTree()
{
  cout<<"Tree for "+(root->word)<<endl;
  printTree(root, 0);
}

void BinTree::printTree(Node* n, int indent)
{
  print(n, indent);
  if(n->left) printTree(n->left, indent+1);
  if(n->right) printTree(n->right, indent+1);
}


void BinTree::print(Node* n, int indent)
{
  string line;
  for(int i=0; i < indent; i++)
  {
    line += "  ";
  }
  line += n->word;
  line += "[" + subSize(n);
  line += ":" + childCount(n);
  line += "]";
  cout << line << endl;
}

void BinTree::preorderBuild(string fileName)
{
  ifstream file;
  file.open(fileName);
  root = preorderBuild(file, 0);
}

Node* BinTree::preorderBuild(ifstream& file, int siblings)
{
  if(siblings >= 0)
  {
    string word;
    file >> word;
    int children;
    file >> children;
    Node n(word, preorderBuild(file, children), preorderBuild(file, siblings-1));
    return &n;
  }
  else
  {
    return NULL;
  }
}

// Node* BinTree::preordBuild(string word, ifstream& file, int children)
// {
//   Node()
//   for(int i = 0; i < children; i++)
//   {
//     string nW = "";
//     file >> nW;
//     int nC;
//     file >> nC;
//     preordBuild(nW, file, nC);
//   }
// }
