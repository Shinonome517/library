#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

DLL::DLL(){
    head = new Node*;
}

//線形探索：計算量O(n)
bool DLL::search(int num){
    Node* ptemp = head;
    while(ptemp != nullptr){
        if(ptemp* == num){
            return true;
        }
        ptemp = head->next;
    }
    return false;
}

//prenodeの前に要素を追加する
//ポインタの書き換え：計算量O(1)
void DLL::insert(Node* pprenode, int num){
    if(pprenode = head){
        Node newnode = new Node;
        head -> prev = &newnode;
        newnode.value = num;
        newnode.next = head;
        newnode.prev = nullptr;
        head = &newnode;
    }
    else{
        Node newnode = new Node ;
        pprenode -> next -> prev = &nownode;
        newnode.value = num;
        newnode.prev = pprenode;
        newnode.next = pprenode->next;
        pprenode->next = &newnode;
        
    }
}


void DLL::erase(Node* pprenode){

}