#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

//計算量O(sqrt(N))

bool isPrime(int64_t N){
    if(N == 1){
        return false;
    }
    else{
        for(int i = 2; i <= sqrt(N); i++){
            //N == 2, 3のときもうまく機能（ループが一回も起こらない）
            if(N % i == 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int64_t N;
    cin >> N;

    if(isPrime(N)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}