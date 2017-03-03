#ifndef BINTREE_H
#define BINTREE_H

#include <string>
#include <vector>

using namespace std;

class Node {
    public:
        Node(string w, Node* l, Node* r)
        {
          word = w;
          left = l;
          right = r;
        }
        string word;
        // string parentWord;//this can help when printing
        Node* left;//firstChild
        Node* right;//rightSibling
};


class BinTree {
    public:
        BinTree(string fileName);
        BinTree();
        void buildTree(string startWord, string endWord);
        void buildLevel(Node* n, vector <string> sibs);
        vector <string> getSibs(Node* n);
        void preorderBuild(string fileName);
        Node* preorderBuild(ifstream& file, int siblings);
        void printTree();
        void printTree(Node* n, int indent);
        void print(Node* n, int index);

    private:
        Node* root;
        vector <string> dict;
        vector <string> family;
        string startWord;
        string endWord;
};
#endif
