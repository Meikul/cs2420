#include "splay.hpp"

bool SplayTree::isLeft(const node *base)
{
  if(base->parent->left == base)
    return true;
  return false;
}

void SplayTree::splay(node *base)
{
  node* par = base->parent;
  node* gpar = base->parent->parent;
  if (base->parent) {
    if (base->parent->parent) {

    } else {
      /* code */
    }
  }
}

void SplayTree::zig(node *base, bool left)
{
  node* par = base->parent;
  if(isLeft(base))
  {
    
    root = base;
  }
}

void SplayTree::zigzig(node *base, bool left)
{

}

void SplayTree::zigzag(node *base, bool left)
{

}
