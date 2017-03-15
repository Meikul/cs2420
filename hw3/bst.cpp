#include <fstream>
#include <iostream>
#include "bst.hpp"

using namespace std;

Node::Node(int value)
{
  left = nullptr;
  right = nullptr;
  data = value;
}

Tree::Tree()
{
  root = nullptr;
}

void Tree::insert(int value)
{
  Node insNode(value);
  insert(root, insNode);
}

void Tree::insert(Node* base, Node insNode)
{
  if (base == nullptr)
  {
    base = &insNode;
    return;
  }
  if (base->data == insNode.data)
    cout << insNode.data << " is already inserted." << endl;
  else if (base->data > insNode.data)
    insert(base->left, insNode);
  else
    insert(base->right, insNode);
}

void Tree::printTree()
{
  printTree(root);
}

void Tree::printTree(Node*  cur)
{
  printTree(cur->left);
  if (cur != nullptr)
    cout << cur->data << " ";
  printTree(cur->right);
}
