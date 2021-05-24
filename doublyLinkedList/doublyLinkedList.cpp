#include "doublyLinkedList.h"
#include <iostream>


DLL::DLL(){
    head = new Node;
    pminimum = nullptr;
    pmaximum = nullptr;
}

//線形探索：計算量O(n)
//numという要素がこのリスト内に存在するかを判定するメソッド
bool DLL::search(int num){
    Node* ptemp = head;
    while(ptemp != nullptr){
        if(ptemp->value == num){
            return true;
        }
        ptemp = head->next;
    }
    return false;
}

void DLL::update(int num){
    if(pmaximum == nullptr){
        *pmaximum = num;
    }
    if(pminimum == nullptr){
        *pminimum = num;
    }
    if(*pmaximum < num){
        *pmaximum = num;
    }
    if(*pminimum > num){
        *pminimum = num;
    }
}

//ポインタの書き換え：計算量O(1)
//prenodeのポインタを受け取り、prenodeの前に要素を追加する
void DLL::insert(Node* pprenode, int num){
    update(num);
    Node* pnewnode = new Node;
    Node* pnextnode = pprenode->next;

    pnewnode->next = pnextnode;
    //headの次の要素だった場合の例外処理
    if(pprenode == head){
        pnewnode->prev = nullptr;
    }
    else{
        pnewnode->prev = pprenode; 
    }
    pnextnode->prev = pnewnode;
    pprenode->next = pnewnode;
}

//ポインタの書き換え:計算量O(1)
//prenodeのポインタを受け取り、prenodeの前の構造体を削除して、その次とつなぐ
void DLL::erase(Node* pprenode){
    Node* perasenode = pprenode->next;
    Node* pnextnode = perasenode->next;

    pprenode->next = pnextnode;
    pnextnode->prev = pprenode;

    delete perasenode;
}

//debug用関数
void DLL::showlist(){
    Node* ptemp = head->next;
    if(ptemp == nullptr){
        std::cout << "None" << std::endl;
        return;
    }
    std::cout << "[" << ptemp->value;
    ptemp = ptemp->next;
    while(ptemp != nullptr){
        std::cout << ", " << ptemp->value;
        ptemp = ptemp -> next;
    }
    std::cout << "]" << std::endl;

}