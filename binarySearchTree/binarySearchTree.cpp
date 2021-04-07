#include "binarySearchTree.h"
/*
二分探索木(binarySearchTree)の実装
    *挿入insert()
    *探索search()
    *削除erase()

<, >=で実装
*/

Node::Node(int64_t key){
    this->key = key;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

//目的のノードまで木を降りて、そのノードのポインタを返す
/*
返り値
    *対象の値があるとき：対象の値のノードのポインタ
    *対象の値がないとき：対象の値が追加されるべきノードの親ノードのポインタ
*/
void Node::getNode(int64_t target, Node **res){
    Node* now = this;
    Node* prev = parent;
    while(now != nullptr && now->key != target){
        prev = now;
        if(target < now->key){
            now = now->left;
        }
        else{
            now = now->right;
        }
    }

    if(now == nullptr){
        *res = prev;
    }
    else{
        *res = now;
    }
}

//部分木内の最小値のノードのポインタを返す関数
void Node::minNd(Node *parentNd, Node** res){
    Node *nd = parentNd;
    while(nd->left != nullptr || nd->right != nullptr){
        //left優先で木を降りる
        if(nd->left != nullptr){
            nd = nd->left;
        }
        else{
            nd = nd->right;
        }
    }
    *res = nd;
}

void Node::insert(int64_t target){
    Node* nd = nullptr;
    getNode(target, &nd);

    if(nd->key == target){
        //すでにtargetは存在するので何もしない
    }
    else{
        if(target < nd->key){
            nd->left = new Node(target);
            nd->left->parent = nd;
        }
        else{
			nd->right = new Node(target);
            nd->right->parent = nd;
        }
    }
}

bool Node::search(int64_t target){
    //while文で木を降りる
    Node *nd;
    getNode(target, &nd);

    if(nd->key == target){
        return true;
    }
    else{
        return false;
    }
}


void Node::erase(int64_t target){
    //まずはそもそも存在するのかを考える
    if(!search(target)){
        return;
    }

    Node *nd = nullptr;
    getNode(target, &nd);
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
        }
        else{
            nd->parent->right = nd->right;
        }
        delete nd;
    }
    else if (nd->right == nullptr){
        if(nd->parent->left->key == nd->key){
            nd->parent->left = nd->left;
        }
        else{
            nd->parent->right = nd->left;
        }
        delete nd;
    }
    else{
        Node *tempNd = nullptr;
        minNd(nd->right, &tempNd);
        nd->key = tempNd->key;
        if(tempNd->parent->left->key == tempNd->key){
            tempNd->parent->left = nullptr;
        }
        else{
            tempNd->parent->right == nullptr;
        }
        delete tempNd;
    }
}

//sort済みの数字を表示
string Node::showall(){
	string res = "";
	if(this->left != nullptr){
        res += this->left->showall();
    }
    res += " " + to_string(this->key) + " ";
    if(this->right != nullptr){
        res += this->right->showall();
    }
    return res;
}
