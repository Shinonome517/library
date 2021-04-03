#include "binarySearchTree.h"

string TorF(bool flag){
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    Node tree(7);

    tree.insert(4);
    tree.insert(12);
    tree.insert(3);
    tree.insert(5);
    tree.insert(9);
    tree.insert(15);

    TorF(tree.search(9)); //Yes
    TorF(tree.search(7)); //Yes
    TorF(tree.search(10)); //No

    tree.erase(9);
    TorF(tree.search(9)); //No
}