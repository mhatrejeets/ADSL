#include <iostream> 
using namespace std; 
class ThreadedNode { 
public: 
int key; 
ThreadedNode *left, *right; 
bool isThreaded; 
ThreadedNode(int item) { 
key = item; 
left = right = nullptr; 
isThreaded = false; 
} 
}; 
class ThreadedBST { 
public: 
ThreadedNode *root; 
    ThreadedNode *prev; 
 
    ThreadedNode *insertRecursive(ThreadedNode *root, int key) { 
        if (root == nullptr) 
            return new ThreadedNode(key); 
 
        if (key < root->key) 
            root->left = insertRecursive(root->left, key); 
        else if (key > root->key) 
            root->right = insertRecursive(root->right, key); 
 
        return root; 
    } 
 
    void inorderThreadingUtil(ThreadedNode *node) { 
        if (node == nullptr) 
            return; 
 
        inorderThreadingUtil(node->left); 
 
        if (prev != nullptr && prev->right == nullptr) { 
            prev->right = node; 
            prev->isThreaded = true; 
        } 
 
        prev = node; 
 
        inorderThreadingUtil(node->right); 
    } 
 
    ThreadedNode *leftmostChild(ThreadedNode *node) { 
        while (node != nullptr && node->left != nullptr) 
            node = node->left; 
        return node; 
    } 
 
 
    ThreadedBST() { 
        root = nullptr; 
        prev = nullptr; 
    } 
 
    void insert(int key) { 
        root = insertRecursive(root, key); 
    } 
 
    void inorderThreading() { 
        inorderThreadingUtil(root); 
    } 
 
    void inorderTraversal() { 
        ThreadedNode *current = leftmostChild(root); 
 
        while (current != nullptr) { 
            cout << current->key << " "; 
 
            if (current->isThreaded) 
                current = current->right; 
            else 
                current = leftmostChild(current->right); 
        } 
    } 
}; 
 
int main() { 
    ThreadedBST tree; 
 
    tree.insert(5); 
    tree.insert(3); 
    tree.insert(8); 
    tree.insert(2); 
    tree.insert(4); 
    tree.insert(7); 
    tree.insert(9); 
 
    tree.inorderThreading(); 
 
    cout << "Inorder Traversal: "; 
    tree.inorderTraversal(); 
 
    return 0; 
}


