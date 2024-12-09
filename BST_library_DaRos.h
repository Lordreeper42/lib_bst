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
    void insertI(int k){
    Node * current = this;
    Node * father = nullptr;
    while  (current != nullptr){
        if  (k < current->data){
            father =  current;
            current = current->l_child;
            if(current ==  nullptr){
                father->l_child = new Node(k);
            }
        }
        else if  (k > current->data){
            father = current;
            current =  current->r_child;
            if(current ==  nullptr){
                father->r_child = new Node(k);
            }
        }
        else  {
            cout << "Value |" << k <<  "| already exists in the tree" << endl;
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


    Node* insert_R (int k){
        if (this == NULL){
            return new  Node(k);
        }
        if (this->data == k){
            cout << "Value |" << k <<  "| already exists in the tree" << endl;
            return this;
        }
        if (this->data  > k){
            this->l_child->insert_R(k);
        }
        else {
            this->r_child->insert_R(k);;
        }
        return this;
    }


    bool searchR (int k){
        if (this == NULL){
            cout  << "Value |" << k <<  "| NOT found in the tree" << endl;
            return  false;
        }
        if (this->data == k){
            cout << "Value |" << this->data <<  "| found at "<<  this << endl;
            return true;
        }
        if (this->data  > k){
            this->l_child->insert_R(k);
        }
        else {
            this->r_child->insert_R(k);;
        }
        return this;
    }

    bool searchI(int k) {
    Node* current = this;
    Node* father = nullptr;

    while (current != nullptr) {
        if (k < current->data) {
            father = current;
            current = current->l_child;
        } else if (k > current->data) {
            father = current;
            current = current->r_child;
        } else {
            current = nullptr; 
            return true;
        }
    }
    return false;
}

    Node* deleteNode (int k){
        if (this == NULL){
            cout  << "Value |" << k <<  "| couldn't be deleted, NOT found in the tree" << endl;
            return  nullptr;
        }
        if (this->data == k){
            cout << "Value |" << k <<  "| has been deleted from "<<  this << endl;
            delete this;
            return nullptr;
        }
        if (this->data  > k){
            this->l_child->deleteNode (k);
        }
        else {
            this->r_child->deleteNode (k);
        }
        return this;
    }

/*

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

*/

void order_for_BST(vector <int> &BST_controller) {
        if (this == nullptr) return; 
        l_child->order_for_BST(BST_controller);
        cout << this->data << " ";
        r_child->order_for_BST(BST_controller);
    }

bool isBst (){
    vector <int> BST_controller;
    bool check(true);
    this->order_for_BST(BST_controller);
    int temp{0};
    for (int i{1}; i< BST_controller.size(); i++){
        if (BST_controller[temp]>BST_controller[i]){
            check = false;
        }
        temp++;
    }
    return check;
}

};