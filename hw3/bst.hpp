#ifndef BST
#define BST

struct Node
{
  Node(int data);
  Node* left;
  Node* right;
  int data;
};

class Tree
{
private:
  Node* root;
  void insert(Node*, Node);
  void printTree(Node*);
public:
  Tree();
  void insert(int);
  void printTree();
};

#endif
