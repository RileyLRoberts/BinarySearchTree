
#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H
#include <iostream>
#include <fstream>
#include "treeNode.h"
using namespace std;

class tree {                                                //Declare class tree

    treeNode * root;                                        //Declare private variable root as treeNode pointer

    public:                                                 //Declare public member function
    tree();
    treeNode* getRoot();
    void addNode(int val);
    void deleteNode(int val);
    void deleteLeaf(treeNode * node, treeNode* parent);
    void deleteOneChild(treeNode * node, treeNode* parent);
    void deleteTwoChild(treeNode * node, treeNode* parent);
    void printTree(treeNode* tree, ofstream &out);
    ~tree();
};


#endif //BINARYTREE_TREE_H
