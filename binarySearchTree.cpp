#include <iostream>
#include <cstdint> //多分ここにNULLが定義されているので<cstddef>はincludeしなくてもいい
#include <new>
#include <cmath>
using namespace std;


//ノード変数の実装
struct node{
    int64_t key;
    node *left;
    node *right;
};

//一つのクラスとして二分木を実装
class Node{
private:
    node tree;
    node *goDown(int64_t);
    node *minNd(node*);
public:
    Node(int64_t);
    ~Node();
    void insert(int64_t);
    bool search(int64_t);
    void erase(int64_t);
    
};

/*
二分探索木(binarySearchTree)の実装
    *挿入insert()
    *探索search()
    *削除erase()

<, >=で実装
*/

Node::Node(int64_t iniv){
    tree = {iniv, NULL, NULL};
}

//目的のノードまで木を降りて、そのノードのポインタを返す
/*
返り値
    *対象の値があるとき：対象の値のノードのポインタ
    *対象の値がないとき：対象の値が追加されるべきノードのNULLポインタ
*/
node *Node::goDown(int64_t target){
    node *nd = &tree;
    while(nd != NULL || nd->key != target){
        if(target < nd->key){
            nd = nd->left;
        }
        else{
            nd = nd->right;
        }
    }

    return nd;
}

//部分木内の最小値のノードのポインタを返す関数
node *Node::minNd(node *parentNd){
    node *nd = parentNd;
    while(nd->left == NULL && nd->right == NULL){
        //left優先で木を降りる
        if(nd->left != NULL){
            nd = nd->left;
        }
        else{
            nd = nd->right;
        }
    }
    return nd;
}

void Node::insert(int64_t target){
    node *nd = goDown(target);

    if(nd == NULL){
        node *nd = new node;
        nd->key = target;
        nd->left = NULL;
        nd->right = NULL;
    }
    else{
        //値はすでにあるので何もしない
    }
}

bool Node::search(int64_t target){
    //while文で木を降りる
    node *nd = goDown(target);

    if(nd == NULL){
        return false;
    }
    else{
        return true;
    }
}


void Node::erase(int64_t target){
    //まずはそもそも存在するのかを考える
    node *nd = goDown(target);
    while(nd != NULL){

    }

}
