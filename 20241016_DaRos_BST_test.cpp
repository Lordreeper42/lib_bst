#include <iostream>
#include <vector>
#include "BST_library_DaRos.h"
using namespace std;

int main(){
    Node root;
    cin >> root;
    cout << root;
    root.insertI(55);
    root.insertI(54);
    root.insertI(23);
    root.insertI(911);
    root.insertI(6);
   
    root.insertI(6);
    root.insertI(33);
    root.insertI(45);
    root.insertI(111);
    root.insertI(777);

    cout << endl<< "INORDER: ";
    root.inOrder();
    cout << endl<< "PREORDER: ";
    root.preOrder();
    cout << endl<< "POSTORDER: ";
    root.postOrder();


    if (root.isBst()==true){
        cout << endl << "The tree is a BST" << endl;
    }
    else {
        cout << endl << "The tree is not a BST" << endl;
    }


    if (root.searchR(55)==true){
        cout << endl << "The value 55 is in the tree" << endl;
    }
    else {
        cout << endl << "The value 55 is not in the tree" << endl;
    }
    if (root.searchR(7)==true){
        cout << endl << "The value 7 is in the tree" << endl;
    }
    else {
        cout << endl << "The value 7 is not in the tree" << endl;
    }
    if (root.searchI(777)==true){
        cout << endl << "The value 777 is in the tree" << endl;
    }
    else {
        cout << endl << "The value 777 is not in the tree" << endl;
    }
    if (root.searchI(12)==true){
        cout << endl << "The value 12 is in the tree" << endl;
    }
    else {
        cout << endl << "The value 12 is not in the tree" << endl;
    }


    cout << endl<< "INORDER: ";
    root.inOrder();

    cout << root;



    return 0;
}