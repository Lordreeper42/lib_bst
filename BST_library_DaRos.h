#include <iostream>
#include <vector>
using namespace std;

class Node{
    private:
    int data;
    int weight;
    Node * l_child;
    Node * r_child;
    public:
    Node (int value){
        data = value;
        l_child = nullptr;
        r_child = nullptr;
    }
    void insert_iteractive(int value){
    Node * current = this;
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
    void preOrder() {
        if (this == nullptr) return;
        cout << this->data << " ";
        l_child->preOrder();
        r_child->preOrder();
    }

    void inOrder() {
        if (this == nullptr) return; 
        l_child->inOrder();
        cout << this->data << " ";
        r_child->inOrder();
    }

    void postOrder() {
        if (this == nullptr) return;
        l_child->postOrder();
        r_child->postOrder();
        cout << this->data << " ";
    }
};




/*
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


void order_for_BST(Node *root, vector <int> &BST_controller) {
         if (root == nullptr) return; 
         order_for_BST(root->l_child, BST_controller);
         BST_controller.push_back(root->data);
         order_for_BST(root->r_child, BST_controller);
    }

bool isBST (Node *root){
    vector <int> BST_controller;
    bool check(true);
    order_for_BST(root, BST_controller);
    int temp{0};
    for (int i{1}; i< BST_controller.size(); i++){
        if (BST_controller[temp]>BST_controller[i]){
            check = false;
        }
        temp++;
    }
    return check;
}

*/