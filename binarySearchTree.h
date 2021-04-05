#include <iostream>
#include <cstdint> //多分ここにNULLが定義されているので<cstddef>はincludeしなくてもいい
#include <new>
#include <cmath>
#include <stack>
using namespace std;


//ノード変数の実装（双方向リストのように実装する）
struct node{
    int64_t key;
    node *parent;
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