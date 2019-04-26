#include "tree.h"
#include "treeNode.h"
#include <cmath>
#include <iomanip>

/*******************************************************************************************
 * Function Title: Tree Constructor
 *
 * Summary: Creates an object of class tree
 *
 * Inputs: None
 * Outputs: A new object of class tree is created
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Set root to be a null pointer
 * End
 * ******************************************************************************************/
tree::tree() {      //Begin
    root = nullptr;     //Set root to be a null pointer
}                   //End

/*******************************************************************************************
 * Function Title: Root Getter
 *
 * Summary: Returns the root of a tree object
 *
 * Inputs: The tree object it is called on
 * Outputs: A pointer to the root
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Return the root
 * End
 * ******************************************************************************************/

treeNode* tree::getRoot() { //Begin
    return root;                //Return the root
}                           //End

/*******************************************************************************************
 * Function Title: Node Adder
 *
 * Summary: Adds a node to a binary tree
 *
 * Inputs: The value to be added
 * Outputs: The new node is added into the binary tree in the correct location
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If the tree is empty
 *  Then
 *      Create a new treeNode with the inputted value and point root there
 *  Else
 *      Point location to the root
 *      Loop
 *          If the value at location is equal to the inputted value
 *          Then
 *              End the function
 *          EndIf
 *          If the value at location is greater than the inputted value
 *          Then
 *              If locations left side is empty
 *              Then
 *                  Add a new treeNode to the left side of location
 *                  End the function
 *              Else
 *                  Set location to the left pointer of location
 *              EndIf
 *          Else
 *              If locations right side is empty
 *              Then
 *                  Add a new treeNode to the right side of location
 *                  End the function
 *              Else
 *                  Set location to the right pointer of location
 *              EndIf
 *          EndIf
 *      EndLoop as shown above
 *  EndIf
 * End
 * ******************************************************************************************/

void tree::addNode(int val) {                           //Begin

    if(root == nullptr) {                                   //If the tree is empty
                                                            //Then
        root = new treeNode(val);                               //Create a new treeNode with the inputted value and point root there
    }
    else {                                                  //Else
        treeNode* location = root;                              //Point location to the root

        for(;;) {                                               //Loop

            if(location->getValue() == val) {                       //If the value at location is equal to the inputted value
                                                                    //Then
                return;                                                 //End the function
            }                                                       //EndIf

            if(location->getValue() > val) {                        //If the value at location is greater than the inputted value
                                                                    //Then
                if (location->getLeft() == nullptr ) {                  //If locations left side is empty
                                                                        //Then
                    location->setLeft(new treeNode(val));                   //Add a new treeNode to the left side of location
                    return;                                                 //End the function
                }
                else {                                                  //Else
                    location = location->getLeft();                         //Set location to the left pointer of location
                }                                                       //EndIf
            }
            else {                                                  //Else
                if (location->getRight() == nullptr ) {                 //If locations right side is empty
                                                                        //Then
                    location->setRight(new treeNode(val));                  //Add a new treeNode to the right side of location
                    return;                                                 //End the function
                }
                else {                                                  //Else
                    location = location->getRight();                        //Set location to the right pointer of location
                }                                                       //EndIf
            }                                                       //EndIf
        }                                                       //EndLoop as shown above
    }                                                       //EndIf
}                                                       //End

/*******************************************************************************************
 * Function Title: Node Deleter
 *
 * Summary: Deletes a node from a binary search tree object
 *
 * Inputs: The value of the node to be deleted
 * Outputs: The node with that value is deleted
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If the tree is empty
 *  Then
 *      End the function
 *  Else
 *      Point location at the root
 *      Point parent at null
 *      Loop
 *          If location is a null pointer
 *          Then
 *              End the function
 *          EndIf
 *          If the value at location is the inputted value
 *          Then
 *              End the Loop
 *          EndIf
 *          If the value at location is greater than the inputted value
 *          Then
 *              Point parent at location
 *              Point location at the left pointer of location
 *          Else
 *              Point parent at location
 *              Point location at the right pointer of location
 *          EndIf
 *      EndLoop when stated above
 *      If location is a leaf
 *      Then
 *          Call delete leaf on location
 *      Else If location has one child
 *      Then
 *          Call deleteOneChild on location
 *      Else If location has two children
 *      Then
 *          Call deleteTwoChild on location
 *      EndIf
 *  EndIf
 * End
 * ******************************************************************************************/

void tree::deleteNode(int val) {                                                //Begin
    if(root == nullptr) {                                                           //If the tree is empty
                                                                                    //Then
        return;                                                                         //End the function
    }
    else {                                                                          //Else
        treeNode* location = root;                                                      //Point location at the root
        treeNode* parent = nullptr;                                                     //Point parent at null
        for(;;) {                                                                       //Loop

            if (location == nullptr) {                                                      //If location is a null pointer
                                                                                            //Then
                return;                                                                         //End the function
            }                                                                               //EndIf

            if(location->getValue() == val ) {                                              //If the value at location is the inputted value
                                                                                            //Then
                break;                                                                          //End the Loop
            }                                                                               //EndIf

            if(location->getValue() > val) {                                                //If the value at location is greater than the inputted value
                                                                                            //Then
                parent = location;                                                              //Point parent at location
                location = location->getLeft();                                                 //Point location at the left pointer of location
            }
            else {                                                                          //Else
                parent = location;                                                              //Point parent at location
                location = location->getRight();                                                //Point location at the right pointer of location
            }                                                                               //EndIf

        }                                                                               //EndLoop when stated above
        if (location->getLeft() == nullptr && location->getRight() == nullptr) {        //If location is a leaf
                                                                                        //Then
            deleteLeaf(location, parent);                                                   //Call delete leaf on location
        }
        else if (location->getLeft() == nullptr || location->getRight() == nullptr) {   //Else If location has one child
                                                                                        //Then
            deleteOneChild(location, parent);                                               //Call deleteOneChild on location
        }
        else if (location->getLeft() != nullptr && location->getRight() != nullptr) {   //Else If location has two children
                                                                                        //Then
            deleteTwoChild(location, parent);                                               //Call deleteTwoChild on location
        }                                                                               //EndIf
    }                                                                               //EndIf
}                                                                               //End

/*******************************************************************************************
 * Function Title: Leaf Deleter
 *
 * Summary: Deletes a leaf from a binary tree
 *
 * Inputs: The pointer to the leaf and a pointer to its parent
 * Outputs: The leaf is removed from the tree
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If the leaf is the root
 *  Then
 *      Point root at null
 *      Delete the leaf
 *  Else
 *      If the leaf is on the left of the parent
 *      Then
 *          Point the left pointer of the parent at null
 *          Delete the leaf
 *      Else
 *          Point the right pointer of the parent at null
 *          Delete the leaf
 *      EndIf
 *  EndIf
 * End
 * ******************************************************************************************/

void tree::deleteLeaf(treeNode * node, treeNode* parent) {  //Begin
    if (node == root) {                                         //If the leaf is the root
                                                                //Then
        root = nullptr;                                             //Point root at null
        delete node;                                                //Delete the leaf
    }
    else {                                                      //Else
        if (node->getValue() < parent->getValue()) {                //If the leaf is on the left of the parent
                                                                    //Then
            parent->setLeft(nullptr);                                   //Point the left pointer of the parent at null
            delete node;                                                //Delete the leaf
        }
        else {                                                      //Else
            parent->setRight(nullptr);                                  //Point the right pointer of the parent at null
            delete node;                                                //Delete the leaf
        }                                                           //EndIf
    }                                                           //EndIf
}                                                           //End

/*******************************************************************************************
 * Function Title: One Child node deleter
 *
 * Summary: Deletes a node with one child
 *
 * Inputs: A pointer to the node and a pointer to its parent
 * Outputs: The node is deleted from the tree
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If the node is the root
 *  Then
 *      If the nodes left pointer is null
 *      Then
 *          Point root at the the nodes right pointer
 *          Delete the node
 *      Else
 *          Point root at the nodes left pointer
 *          Delete the node
 *      EndIf
 *  Else
 *      If the node is on the left of the parent
 *      Then
 *          If the nodes left pointer is null
 *          Then
 *              Point the parents left pointer at the nodes right pointer
 *              Delete the node
 *          Else
 *              Point the parents left pointer at the nodes left pointer
 *              Delete the node
 *          EndIf
 *      Else
 *          If the nodes left pointer is null
 *          Then
 *              Point the parents right pointer at the nodes right pointer
 *              Delete the node
 *          Else
 *              Point the parents right pointer at the nodes left pointer
 *              Delete the node
 *          EndIf
 *      EndIf
 *  EndIf
 * End
 * ******************************************************************************************/

void tree::deleteOneChild(treeNode * node, treeNode* parent) {  //Begin
    if (node == root) {                                             //If the node is the root
                                                                    //Then
        if (node->getLeft() == nullptr) {                               //If the nodes left pointer is null
                                                                        //Then
            root = node->getRight();                                        //Point root at the the nodes right pointer
            delete node;                                                    //Delete the node
        }
        else {                                                          //Else
            root = node->getLeft();                                         //Point root at the nodes left pointer
            delete node;                                                    //Delete the node
        }                                                               //EndIf
    }
    else {                                                          //Else
        if (node->getValue() < parent->getValue()) {                    //If the node is on the left of the parent
                                                                        //Then
            if (node->getLeft() == nullptr) {                               //If the nodes left pointer is null
                                                                            //Then
                parent->setLeft(node->getRight());                              //Point the parents left pointer at the nodes right pointer
                delete node;                                                    //Delete the node
            } else {                                                        //Else
                parent->setLeft(node->getLeft());                               //Point the parents left pointer at the nodes left pointer
                delete node;                                                    //Delete the node
            }                                                               //EndIf
        }
        else {                                                          //Else
            if (node->getLeft() == nullptr) {                               //If the nodes left pointer is null
                                                                            //Then
                parent->setRight(node->getRight());                             //Point the parents right pointer at the nodes right pointer
                delete node;                                                    //Delete the node
            } else {                                                        //Else
                parent->setRight(node->getLeft());                              //Point the parents right pointer at the nodes left pointer
                delete node;                                                    //Delete the node
            }                                                               //EndIf
        }                                                               //EndIf
    }                                                               //EndIf
}                                                               //End

/*******************************************************************************************
 * Function Title: Two Child Node deleter
 *
 * Summary: Deletes a node with two children
 *
 * Inputs: A pointer to the node and a pointer to its parent
 * Outputs: The node is deleted
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Point location at the nodes left pointer
 *  Point parent at node
 *  Loop while locations right pointer is not pointing at null
 *      Point parent at location
 *      Point location at the right pointer of location
 *  EndLoop when the right pointer of location is null
 *  Store the value at location in a temporary variable
 *  If locations left pointer is null
 *  Then
 *      Call delete leaf on location
 *  Else
 *      Call deleteOneChild on location
 *  EndIf
 *  Set the value of the node to the temporary value
 * End
 * ******************************************************************************************/

void tree::deleteTwoChild(treeNode * node, treeNode* parent) {  //Begin

    treeNode * location = node->getLeft();                          //Point location at the nodes left pointer
    parent = node;                                                  //Point parent at node
    while (location->getRight() != nullptr) {                       //Loop while locations right pointer is not pointing at null
        parent = location;                                              //Point parent at location
        location = location->getRight();                                //Point location at the right pointer of location
    }                                                               //EndLoop when the right pointer of location is null

    int temp = location->getValue();                                //Store the value at location in a temporary variable
    if (location->getLeft() == nullptr) {                           //If locations left pointer is null
                                                                    //Then
        deleteLeaf(location, parent);                                   //Call delete leaf on location
    }
    else {                                                          //Else
        deleteOneChild(location,parent);                                //Call deleteOneChild on location
    }                                                               //EndIf
    node->setValue(temp);                                           //Set the value of the node to the temporary value
}                                                               //End

/*******************************************************************************************
 * Function Title: Print Tree
 *
 * Summary: Prints the values stored in the tree, and their base 10 logs in ascending order
 *
 * Inputs: A pointer to the tree, and the output stream to print to
 * Outputs: Prints the values stored in the tree, and their base 10 logs in ascending order
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If the tree pointer is not null
 *  Then
 *      Call printTree on the left pointer of tree
 *      Print the value
 *      Print the base 10 log
 *      Call printTree on the right pointer of tree
 *  EndIf
 * End
 * ******************************************************************************************/

void tree::printTree(treeNode* tree, ofstream &out) {                                           //Begin

    if (tree != nullptr) {                                                                          //If the tree pointer is not null
                                                                                                    //Then
        printTree(tree->getLeft(), out);                                                                //Call printTree on the left pointer of tree
        out << left << setw(2) << tree->getValue() << " ";                                              //Print the value
        out << setw(5) << fixed << setprecision(4) << log10((float) tree->getValue()) << endl;          //Print the base 10 log
        printTree(tree->getRight(), out);                                                               //Call printTree on the right pointer of tree
    }                                                                                               //EndIf
}                                                                                               //End

/*******************************************************************************************
 * Function Title: Tree Destructor
 *
 * Summary: Deletes all nodes and allocated memory in a binary search tree
 *
 * Inputs: The tree it is called on
 * Outputs: The tree is deleted
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Point parent at null
 *  Loop while root is not null
 *      If both the left and right pointer of root are null
 *      Then
 *          Call deleteLeaf on root
 *      Else If root has one child
 *      Then
 *          Call deleteOneChild on root
 *      Else If root has two children
 *      Then
 *          Call deleteTwoChild on root
 *      EndIf
 *  EndLoop when root is null
 * End
 * ******************************************************************************************/

tree::~tree() {                                                                 //Begin

    treeNode * parent = nullptr;                                                    //Point parent at null

    while(root != nullptr) {                                                        //Loop while root is not null

        if (root->getLeft() == nullptr && root->getRight() == nullptr) {                //If both the left and right pointer of root are null
                                                                                        //Then
            deleteLeaf(root, parent);                                                       //Call deleteLeaf on root
        }
        else if (root->getLeft() == nullptr || root->getRight() == nullptr) {           //Else If root has one child
                                                                                        //Then
            deleteOneChild(root, parent);                                                   //Call deleteOneChild on root
        }
        else if (root->getLeft() != nullptr && root->getRight() != nullptr) {           //Else If root has two children
                                                                                        //Then
            deleteTwoChild(root, parent);                                                   //Call deleteTwoChild on root
        }                                                                               //EndIf

    }                                                                               //EndLoop when root is null
}                                                                               //End

