#include "binarySearchTree.h"

void TorF(bool flag){
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    cout << "start" << endl;
    Node tree(7); tree.showall();

    tree.insert(4); tree.showall();
    tree.insert(12); tree.showall();
    tree.insert(3); tree.showall();
    tree.insert(5); tree.showall();
    tree.insert(9); tree.showall();
    tree.insert(15); tree.showall();

    TorF(tree.search(9)); //Yes
    TorF(tree.search(7)); //Yes
    TorF(tree.search(10)); //No

    tree.erase(9);
    TorF(tree.search(9)); //No
}