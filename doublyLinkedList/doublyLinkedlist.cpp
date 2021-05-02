#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

DLL::DLL(int initialvalue){
    head = new int;
    cell = {initialvalue, head, nullptr};
}