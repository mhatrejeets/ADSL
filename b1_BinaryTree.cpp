#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(Node * root){
    Node* temp = root;
    if(temp == NULL){
        return;
    }

    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);

    
}

void preOrder(Node * root){
    Node* temp = root;
    if(temp == NULL){
        return;
    }

    cout<<temp->data<<" ";
    preOrder(temp->left);
    preOrder(temp->right);
    
    
}

void postOrder(Node * root){
    Node* temp = root;
    if(temp == NULL){
        return;
    }

    postOrder(temp->left);
    postOrder(temp->right);
    cout<<temp->data<<" ";
    
    
}

int main(){
    Node * root = new Node(0);
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n8 = new Node(8);


    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n4->right = n7;
    n5->left = n8;

    /*              0
                1       2
              3   4   5   6
                   7  8
                   */

    cout<<"\nPreOrder : ";
    preOrder(root);
    cout<<"\ninOrder : ";
    inOrder(root);
    cout<<"\nPostOrder : ";
    postOrder(root);

    
}