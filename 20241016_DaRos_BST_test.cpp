#include <iostream>
#include <vector>
#include "BST_library_DaRos.h"
using namespace std;

int main(){
    Node * root = new Node(49);
    root = insert_recursive(root, 55);
    root = insert_recursive(root, 15);
    root = insert_recursive(root, 54);
    root = insert_recursive(root, 22);
    root = insert_recursive(root, 78);
    root = insert_recursive(root, 103);
    root = insert_recursive(root, 69);
    insert_iteractive(root, 55);
    insert_iteractive(root, 54);
    insert_iteractive(root, 23);
    insert_iteractive(root, 911);
    insert_iteractive(root, 6);
    search_iteractive(root, 55);
    delete_iteractive(root, 911);
    cout << endl << "PREORDER: ";
    preOrder(root);
    cout << endl<< "INORDER: ";
    inOrder(root);
    cout << endl<< "POSTORDER: ";
    postOrder(root);
    cout << endl;
    cout  << "HEIGHT: " << height(root) << endl;
    if (isBST(root)== true){
        cout << "is bst";
    }
    else {
        cout << "not un bst";
    }


    return 0;
}