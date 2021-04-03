#include "binarySearchTree.h"
/*
二分探索木(binarySearchTree)の実装
    *挿入insert()
    *探索search()
    *削除erase()

<, >=で実装
*/

Node::Node(int64_t iniv){
    tree = {iniv, nullptr, nullptr, nullptr};
}

//目的のノードまで木を降りて、そのノードのポインタを返す
/*
返り値
    *対象の値があるとき：対象の値のノードのポインタ
    *対象の値がないとき：対象の値が追加されるべきノードのnullptrポインタ
*/
node *Node::goDown(int64_t target){
    node *nd = &tree;
    while(nd != nullptr || nd->key != target){
        if(target < nd->key){
            nd->parent = nd;
            nd = nd->left;
        }
        else{
            nd->parent = nd;
            nd = nd->right;
        }
    }

    return nd;
}

//部分木内の最小値のノードのポインタを返す関数
node *Node::minNd(node *parentNd){
    node *nd = parentNd;
    while(nd->left == nullptr && nd->right == nullptr){
        //left優先で木を降りる
        if(nd->left != nullptr){
            nd->parent = nd;
            nd = nd->left;
        }
        else{
            nd->parent = nd;
            nd = nd->right;
        }
    }
    return nd;
}

void Node::insert(int64_t target){
    node *nd = goDown(target);

    if(nd == nullptr){
        node *nd = new node;
        nd->key = target;
        nd->left = nullptr;
        nd->right = nullptr;
    }
    else{
        //値はすでにあるので何もしない
    }
}

bool Node::search(int64_t target){
    //while文で木を降りる
    node *nd = goDown(target);

    if(nd == nullptr){
        return false;
    }
    else{
        return true;
    }
}


void Node::erase(int64_t target){
    //まずはそもそも存在するのかを考える
    node *nd = goDown(target);
    if(nd->left == nullptr && nd->right == nullptr){
        //親ノード枝先のポインタをnullptrで初期化しておく必要がある
        if(nd->parent->left->key == nd->key){
            nd->parent->left = nullptr;
        }
        else{
            nd->parent->right = nullptr;
        }
        delete nd;
    }
    else if(nd->left == nullptr){
        if(nd->parent->left->key == nd->key){
            nd->parent->left = nd->right;
            delete nd;
        }
        else{
            nd->parent->right = nd->right;
            delete nd;
        }
    }
    else if (nd->right == nullptr){
        if(nd->parent->left->key == nd->key){
            nd->parent->left = nd->left;
            delete nd;
        }
        else{
            nd->parent->right = nd->left;
            delete nd;
        }
    }
    else{
        node *tempNd = minNd(nd);
        nd->key = tempNd->key;
        if(tempNd->parent->left->key == tempNd->key){
            tempNd->parent->left = nullptr;
            delete tempNd;
        }
        else{
            tempNd->parent->right == nullptr;
            delete tempNd;
        }
    }
}
