#include<iostream>
#include<string>
using namespace std;
class Node {
    public:
    char data;
    Node * left;
    Node * right;

    Node (char c){
        this->data = c;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isOperator(char c){
    return c=='+' || c== '-' || c=='*' ||c=='/';

   
}
Node * constructBT(const string& postfix , int& index){

if(index<0){
    return NULL;
    }

    char c = postfix[index--];

    Node * n = new Node(c);

     if(isOperator(c)){
        n->right = constructBT(postfix, index);
        n->left = constructBT(postfix, index);


    }

    return n;

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
    string postfix = "abc*+de*f*+";
    int index = postfix.size() -1;
    Node *root = constructBT(postfix,index);

     cout<<"\nPreOrder : ";
    preOrder(root);
    cout<<"\ninOrder : ";
    inOrder(root);
    cout<<"\nPostOrder : ";
    postOrder(root);

}