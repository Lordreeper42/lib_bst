#include <iostream>
#include <vector>
#include "BST_library_DaRos.h"
using namespace std;

int main(){
    Node root {49};
    root.insert_iteractive(55);
    root.insert_iteractive(54);
    root.insert_iteractive(23);
    root.insert_iteractive(911);
    root.insert_iteractive(6);
   
    cout << endl<< "INORDER: ";
    root.inOrder();
 


    return 0;
}