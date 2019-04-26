#include "treeNode.h"
#include <iostream>
using namespace std;

/*******************************************************************************************
 * Function Title: treeNode Constructor
 *
 * Summary: Creates an object of class treeNode
 *
 * Inputs: The value for the new node
 * Outputs: A new treeNode with the inputted value is created
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Set value equal to the inputted value
 *  Point left at null
 *  Point right at null
 * End
 * ******************************************************************************************/

treeNode::treeNode(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
}

/*******************************************************************************************
 * Function Title: treeNode Value Getter
 *
 * Summary: Return the value of the treeNode
 *
 * Inputs: The treeNode it is called on
 * Outputs: Returns the value of the node
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Return the value
 * End
 * ******************************************************************************************/

int treeNode::getValue() {  //Begin
    return value;               //Return the value
}                           //End

/*******************************************************************************************
 * Function Title: treeNode Value Setter
 *
 * Summary: Sets the value of a treeNode
 *
 * Inputs: A value to set the treeNode value to
 * Outputs: The nodes value is changed
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Set value equal to the inputted value
 * End
 * ******************************************************************************************/

void treeNode::setValue(int val) {  //Begin
    value = val;                        //Set value equal to the inputted value
}                                   //End

/*******************************************************************************************
 * Function Title: treeNode Left Pointer Getter
 *
 * Summary: Return the left pointer of a treeNode
 *
 * Inputs: The treeNode it is called on
 * Outputs: Return the left pointer of the node
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Return the left pointer
 * End
 * ******************************************************************************************/

treeNode * treeNode::getLeft() {    //Begin
    return left;                        //Return the left pointer
}                                   //End

/*******************************************************************************************
 * Function Title: treeNode Left Pointer Setter
 *
 * Summary: Sets the left pointer for a tree node
 *
 * Inputs: The pointer to point left at
 * Outputs: The left pointer is pointed at the inputted pointer
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Point left at the inputted pointer location
 * End
 * ******************************************************************************************/

void treeNode::setLeft(treeNode * l) {  //Begin
    left = l;                               //Point left at the inputted pointer location
}                                       //End

/*******************************************************************************************
 * Function Title: treeNode Right Pointer Getter
 *
 * Summary: Returns the right pointer of a treeNode
 *
 * Inputs: The treeNode it is called on
 * Outputs: Returns the right pointer of a treeNode
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Return the right pointer
 * End
 * ******************************************************************************************/

treeNode * treeNode::getRight() {   //Begin
    return right;                       //Return the right pointer
}                                   //End

/*******************************************************************************************
 * Function Title: treeNode Right Pointer Setter
 *
 * Summary: Sets the right pointer of a treeNode
 *
 * Inputs: The pointer the right pointer is to be set to
 * Outputs: The right pointer is set to the inputted pointer
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Set right equal to the inputted value
 * End
 * ******************************************************************************************/

void treeNode::setRight(treeNode * r) { //Begin
    right = r;                              //Set right equal to the inputted value
}                                       //End

