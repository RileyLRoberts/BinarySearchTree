
#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H

class treeNode{                     //Declare class treeNode
    int value;                      //Declare private variables
    treeNode * left;
    treeNode * right;

    public:                         //Declare public member function
    treeNode(int val);
    int getValue();
    void setValue(int val);
    treeNode *getLeft();
    void setLeft(treeNode * l);
    treeNode *getRight();
    void setRight(treeNode * r);

};

#endif //BINARYTREE_TREENODE_H
