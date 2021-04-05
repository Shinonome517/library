#include "binarySearchTree.h"
/*
二分探索木(binarySearchTree)の実装
    *挿入insert()
    *探索search()
    *削除erase()

<, >=で実装
*/

Node::Node(int64_t iniv){
    cout << "constructor" << endl;
    tree = {iniv, nullptr, nullptr, nullptr};
}

//目的のノードまで木を降りて、そのノードのポインタを返す
/*
返り値
    *対象の値があるとき：対象の値のノードのポインタ
    *対象の値がないとき：対象の値が追加されるべきノードの親ノードのポインタ
*/
node *Node::goDown(int64_t target){
    //cout << "godown" << endl;
    node *nd = &tree;
    node *ndParent = tree.parent;
    //cout << nd << endl;
    //cout << nd->left << endl;
    while(nd != nullptr && nd->key != target){
        if(target < nd->key){
            ndParent = nd;
            //nd->parent = nd;
            nd = nd->left;
            //cout << nd << endl;
        }
        else{
            ndParent = nd;
            //nd->parent = nd;
            nd = nd->right;
            //cout << nd << endl;
        }
    }

    //cout << "end godown" << endl;
    if(nd == nullptr){
        return ndParent;
    }
    else{
        return nd;
    }
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
    //cout << "insert" << endl;
    node *nd = goDown(target);

    if(nd->key == target){
        //すでにtargetは存在するので何もしない
    }
    else{
        if(target < nd->key){
            nd->left = new node;
            nd->left->key = target;
            nd->left->parent = nd;
            nd->left->left = nullptr;
            nd->left->right = nullptr;
        }
        else{
            nd->right = new node;
            nd->right->key = target;
            nd->right->parent = nd;
            nd->right->left = nullptr;
            nd->right->right = nullptr;
        }
    }
}

bool Node::search(int64_t target){
    //cout << "search" << endl;
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
    //cout << "erase" << endl;
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

void Node::showall(){

    stack<node*> st;

    //深さ優先で末端からdelete
    st.push(&tree);
    while(!st.empty()){

        node *tempNd = st.top();
        st.pop();

        if(tempNd == nullptr){
            //末端に到達したので何もしない
        }
        else{
            //left優先でスタックに格納
            st.push(tempNd->left);
            st.push(tempNd->right);
            //格納後にcout
            cout << tempNd->key << " ";
        }
    }
    cout << endl;
}

Node::~Node(){
    cout << "destructor" << endl;

    stack<node*> st;

    //深さ優先で末端からdelete
    st.push(&tree);
    while(!st.empty()){

        node *tempNd = st.top();
        st.pop();

        if(tempNd == nullptr){
            //末端に到達したので何もしない
        }
        else{
            //left優先でスタックに格納
            st.push(tempNd->left);
            st.push(tempNd->right);
            //格納後にdelete
            delete tempNd;
        }
    }
}
