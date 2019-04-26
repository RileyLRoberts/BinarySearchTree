#include <iostream>
#include <fstream>
#include "treeNode.h"
#include "tree.h"

/*******************************************************************************************
 * Function Title: Main
 *
 * Summary: Reads a series of characters and integers from an input file, and then adds or deletes
 * those values to a binary search tree, based on the input. After the input file has been fully read,
 * prints the values and there logs onto an output file in ascending sorted order
 *
 * Inputs: The name of the input and output files
 * Outputs: A sorted list of values and their logs
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  If an incorrect number of command line arguments is used
 *  Then
 *      Print an error message
 *      End the program
 *  EndIf
 *  Create an input stream called inpfile
 *  Open the file inputted by the user and set it to inpfile
 *  If the file failed to open
 *  Then
 *      Print an error message
 *      End the program
 *  EndIf
 *  Declare variable and a tree object
 *  Loop until the end of the input file is reached
 *      Store the character and the integer
 *      If the character is an a
 *      Then
 *          Add a node with that value to the tree
 *      Else If the character is a d
 *      Then
 *          Delete the node with that value
 *      Else
 *          Print an error message for invalid operator
 *          End the program
 *      EndIf
 *  EndLoop when the end of the file is reached
 *  Close the input file
 *  Create an output file stream
 *  Open the output file indicated by the user
 *  If the file failed to open
 *  Then
 *      Print an error message
 *      Exit the Program
 *  EndIf
 *  Print the tree to the output file in sorted order
 *  Close the output file
 *  Delete the tree
 * End
 * ******************************************************************************************/

int main(int argc, char* argv[]) {                                      //Begin

    if (argc != 3) {                                                        //If an incorrect number of command line arguments is used
                                                                            //Then
        cout << "Error: Usage ./Tree.exe input.txt output.txt" << endl;         //Print an error message
        exit(1);                                                                //End the program
    }                                                                       //EndIf

    ifstream inpfile;                                                       //Create an input stream called inpfile
    inpfile.open(argv[1]);                                                  //Open the file inputted by the user and set it to inpfile

    if (!inpfile.is_open()) {                                               //If the file failed to open
                                                                            //Then
        cout << "Error: input file failed to open" << endl;                     //Print an error message
        exit(1);                                                                //End the program
    }                                                                       //EndIf

    char op;                                                                //Declare variable and a tree object
    int val;
    tree t;

    while(!inpfile.eof()) {                                                 //Loop until the end of the input file is reached
        inpfile >> op >> val;                                                   //Store the character and the integer

        if (op == 'a') {                                                        //If the character is an a
                                                                                //Then
            t.addNode(val);                                                         //Add a node with that value to the tree
        }
        else if (op == 'd') {                                                   //Else If the character is a d
                                                                                //Then
            t.deleteNode(val);                                                      //Delete the node with that value
        }
        else {                                                                  //Else
            cout << "Invalid operator, please only use a or d" << endl;             //Print an error message for invalid operator
            exit(1);                                                                //End the program
        }                                                                       //EndIf
    }                                                                       //EndLoop when the end of the file is reached

    inpfile.close();                                                        //Close the input file
    ofstream outfile;                                                       //Create an output file stream
    outfile.open(argv[2]);                                                  //Open the output file indicated by the user

    if (!outfile.is_open()) {                                               //If the file failed to open
                                                                            //Then
        cout << "Error: output file failed to open" << endl;                    //Print an error message
        exit(1);                                                                //Exit the program
    }                                                                       //EndIf

    t.printTree(t.getRoot(), outfile);                                      //Print the tree to the output file in sorted order
    outfile.close();                                                        //Close the output file
    t.~tree();                                                              //Delete the tree

}                                                                       //End