#include<iostream>
using namespace std;

class Node {
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

Node * createBST(Node * root , int data){
    
    if(root == NULL){
        Node * temp = new Node(data);
        root = temp;
        return root;
    }

     else if(root->data >  data ){
        root ->left = createBST(root->left, data);
    }
    else if (root->data <  data){
        root->right = createBST(root->right, data);
    }


    return root;

}

void inOrder(Node * root){
    Node* temp = root;
    if(temp == NULL){
        return;
    }

    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);

    
}

int minElement(Node * root ){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int maxElement(Node * root ){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int main(){
    Node * root = NULL;
    int choice;

    do{
        cout<<"\nEnter the data : ";
        int data;
        cin>>data;
        root = createBST(root, data);
        cout<<"\nEnter : \n1:Enter more element. \n0.To exit \nEnter choice : ";
        cin>>choice;
    }while(choice != 0);

    cout<<"\ninOrder : ";
    inOrder(root);

    cout<<"\nMax Element : "<<maxElement(root);
    cout<<"\nMin Element : "<<minElement(root);
}