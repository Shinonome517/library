#include <stdlib.h>
#include <time.h>
#include "binarySearchTree.h"
using namespace std;

constexpr int MAX = 100000000; //10^8
constexpr int MIN = 0;
constexpr int INIV = 50000000; //5.0*10^7

int getRandom(int min, int max){
    //まず、0~(max-min)を作成して最後にminを足す
    return (int)rand() % (max - min + 1) + min;
}

int main(){
    //おまじない
    srand((unsigned int)time(NULL));

    Node tree = Node(INIV);

    for(int i = 0; i < pow(10, 2); i++){
        tree.insert(getRandom(MIN, MAX));
    }

    cout << tree.showall() << endl;
}