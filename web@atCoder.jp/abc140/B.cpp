#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A (n+1), B (n+1), C(n+1);
    for(int i = 1; i <= n; i++)      cin >> A[i];
    for(int i = 1; i <= n; i++)      cin >> B[i];
    for(int i = 1; i <= n-1; i++)    cin >> C[i];
    //
    long long sat = 0;
    int prevDish = -9;
    for(int i = 1; i <= n; i++) {
        if( A[i]-1 == prevDish ) sat += C[prevDish];
        sat += B[A[i]];
        prevDish = A[i];
    }
    cout << sat;
}