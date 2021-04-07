#include <iostream>
#include <cstdint> //多分ここにNULLが定義されているので<cstddef>はincludeしなくてもいい
#include <new>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

//一つのクラスとして二分木を実装
class Node{
private:
    int64_t key;
    Node *parent;
    Node *left;
    Node *right;
    void getNode(int64_t, Node**);
    void minNd(Node*, Node**);
public:
    Node(int64_t);
    void insert(int64_t);
    bool search(int64_t);
    void erase(int64_t);
    string showall();
    
};