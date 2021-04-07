#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//素数テープルの作成
//計算量O(Nloglog(N))

//indexと扱う数字を対応
void eratosthenes(vector<bool> &sieve){

    for(int i = 0; i < sieve.size(); i++){
        if(i == 0 || i == 1){
            sieve.at(i) = false;
        }
        else if(sieve.at(i)){
            for(int j = 2; i*j <= sieve.size() - 1; j++){
                sieve.at(i*j) = false;
            }
        }
    }
}


int main(){
    
    int N;
    cin >> N;

    vector<bool> sieve(ceil(N) + 1, true);

    eratosthenes(sieve);

    for(int i = 0; i < sieve.size(); i++){
        if(sieve.at(i)){
            cout << i << " true" << endl;
        }
        else{
            cout << i << " false" << endl;
        }
    }

}