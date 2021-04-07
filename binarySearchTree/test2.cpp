#include <bits/stdc++.h>
using namespace std;

int main(){
    struct node {
        int key;
        node *parent;
        node *left;
        node *right;
    };

    node tree = {7, nullptr, nullptr, nullptr};

    if(tree.left == nullptr){
        cout << "nullptr!!" << endl;
    }

    cout << tree.key << endl;

    tree.left = new node;
    tree.left->parent = &tree;
    tree.left->left = nullptr;
    tree.left->right = nullptr;
    tree.left->key = 5;

    cout << &tree << endl
        << tree.left->parent << endl
        << tree.left << endl
        << tree.left->key << endl;

    node *tempNd = nullptr;
    tempNd = &tree;
    tempNd->parent = &tree;
    tempNd = tempNd->left;

    cout << "============" << endl;
    cout << &tree << endl
        << tree.left->parent << endl
        << tree.left << endl
        << tree.left->key << endl;

    cout << "===========" << endl;
    cout << tempNd << endl
        << tempNd->left << endl
        << tempNd->key << endl;
}
