#ifndef SPLAY
#define SPLAY

struct node
{
  int data;
  node* right;
  node* left;
  node* parent;
  node(int n):
    data(n),
    right(nullptr),
    left(nullptr),
    parent(nullptr)
    {}
};

class SplayTree
{
private:
  node* root;
  void zigzig(node* base, bool left);
  void zigzag(node* base, bool left);
  void zig(node* base, bool left);
  void splay(node* base);
  bool isLeft(const node* base);
public:
  SplayTree():
    root(nullptr)
  {}
  bool insert(int num);
  bool remove(int num);
  bool search(int num);
};


#endif /* end of include guard: SPLAY */
