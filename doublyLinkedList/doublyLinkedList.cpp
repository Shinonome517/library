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

void DLL::updatemax(int num){
    if(pmaximum == nullptr){
        *pmaximum = num;
    }
    else{
        if(*pmaximum < num){
            *pmaximum = num;
        }
    }
}

void DLL::updatemin(int num){
    if(pminimum == nullptr){
        *pminimum = num;
    }
    else{
        if(*pminimum > num){
            *pminimum = num;
        }
    }
}

//ポインタの書き換え：計算量O(1)
//prenodeのポインタを受け取り、prenodeの前に要素を追加する
void DLL::insert(Node* pprenode, int num){
    updatemax(num);
    updatemin(num);
    if(pprenode = head){
        Node* pnewnode = new Node;
        head -> prev = pnewnode;
        pnewnode->value = num;
        pnewnode->next = head;
        pnewnode->prev = nullptr;
        head = pnewnode;
    }
    else{
        Node* pnewnode = new Node ;
        pprenode -> next -> prev = pnewnode;
        pnewnode->value = num;
        pnewnode->prev = pprenode;
        pnewnode->next = pprenode->next;
        pprenode->next = pnewnode;
        
    }
}

//ポインタの書き換え:計算量O(1)
//prenodeのポインタを受け取り、prenodeの前の構造体を削除して、その次とつなぐ
void DLL::erase(Node* pprenode){

}