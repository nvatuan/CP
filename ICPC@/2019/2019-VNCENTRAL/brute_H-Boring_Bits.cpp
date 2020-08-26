#include <bits/stdc++.h>
using namespace std;

const long long M = 666777;

void showD(deque<long long> v) {
    cout << "deque = ";
    for(auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    int N, K;
    cin >> N >> K;  
    K++;
    
    deque<long long> D;

    for(int i = 1; i <= N+K+1; i++){
        if(i < K) {
            D.push_back(0);
        } 
        if(i == K) {
            D.push_back(1);
        }
        if(i > K) {
            long long fib = 0;
            for(int i : D) fib = (fib + i) % M;
            //cout << fib << endl;
            D.pop_front();
            D.push_back(fib);
        }
        //showD(D);
    }
    cout << D.back();
}