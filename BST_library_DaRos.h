#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * l_child;
    Node * r_child;
    Node (int value){
        data = value;
        l_child = nullptr;
        r_child = nullptr;
    }
};

void preOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->l_child);
    preOrder(node->r_child);
}

void inOrder(Node* node) {
    if (node == nullptr) return; 
    inOrder(node->l_child);
    cout << node->data << " ";
    inOrder(node->r_child);
}

void postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->l_child);
    postOrder(node->r_child);
    cout << node->data << " ";
}

Node* insert_recursive (Node* branch, int N){
    if (branch == NULL){
        return new  Node(N);
    }
    if (branch->data == N){
        cout << "Value |" << N <<  "| already exists in the tree" << endl;
        return branch;
    }
    if (branch->data  > N){
        branch->l_child = insert_recursive (branch->l_child, N);
    }
    else {
        branch->r_child = insert_recursive (branch->r_child, N);
    }
    return branch;
}

void insert_iteractive(Node *root, int value){
    Node * current = root ;
    Node * father = nullptr;
    while  (current != nullptr){
        if  (value < current->data){
            father =  current;
            current = current->l_child;
            if(current ==  nullptr){
                father->l_child = new Node(value);
            }
        }
        else if  (value > current->data){
            father = current;
            current =  current->r_child;
            if(current ==  nullptr){
                father->r_child = new Node(value);
            }
        }
        else  {
            cout << "Value |" << value <<  "| already exists in the tree" << endl;
            current =  nullptr;
        }
    }
}

Node* search_recursive (Node* branch, int N){
    if (branch == NULL){
        cout  << "Value |" << N <<  "| NOT found in the tree" << endl;
        return  nullptr;
    }
    if (branch->data == N){
        cout << "Value |" << branch->data <<  "| found at "<<  branch << endl;

        return branch;
    }
    if (branch->data  > N){
        branch->l_child = search_recursive (branch->l_child, N);
    }
    else {
        branch->r_child = search_recursive (branch->r_child, N);
    }
    return branch;
}

void search_iteractive(Node *root, int value){
    Node * current = root ;
    Node * father = nullptr;
    while  (current != nullptr){
        if  (value < current->data){
            father =  current;
            current = current->l_child;
            if(current ==  nullptr){
                cout  << "Value |" << current->data <<  "| NOT found in the tree" << endl;
            }
        }
        else if  (value > current->data){
            father = current;
            current =  current->r_child;
            if(current ==  nullptr){
                cout  << "Value |" << current->data <<  "| NOT found in the tree" << endl;
            }
        }
        else  {
            cout << "Value |" << current->data <<  "| found at "<< current << endl;

            current =  nullptr;
        }
    }
}

Node* delete_recursive (Node* branch, int N){
    if (branch == NULL){
        cout  << "Value |" << N <<  "| couldn't be deleted, NOT found in the tree" << endl;
        return  nullptr;
    }
    if (branch->data == N){
        if (branch->l_child == nullptr && branch->r_child == nullptr){
        branch =  nullptr;
        cout << "Value |" << branch->data <<  "| has been deleted " << endl;
        return branch;
        }
        else if (branch->r_child == nullptr){
            branch = branch->l_child;
        }
    }
    if (branch->data  > N){
        branch->l_child = delete_recursive (branch->l_child, N);
    }
    else {
        branch->r_child = delete_recursive (branch->r_child, N);
    }
    return branch;
}

void delete_iteractive(Node *root, int value){
    Node * current = root ;
    Node * father = nullptr;
    while  (current != nullptr){
        if  (value < current->data){
            father =  current;
            current = current->l_child;
            if(current ==  nullptr){
                cout  << "Value |" << current->data <<  "| couldn't be deleted, NOT found in the tree" << endl;
            }
        }
        else if  (value > current->data){
            father = current;
            current =  current->r_child;
            if(current ==  nullptr){
                cout  << "Value |" << current->data <<  "| couldn't be deleted, NOT found in the tree" << endl;
            }
        }
        else  {
            cout << "Value |" << current->data <<  "| has been deleted " << endl;
            current =  nullptr;
        }
    }
}

int height(Node  *root){
    if(root ==  nullptr){
        return 0;
    }
    int l = height(root->l_child);
    int r  = height(root->r_child);
    if  (l > r){
        return l+1;
    }
    else {
        return r+1;
    }
}

