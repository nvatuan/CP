#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> A(n, INT_MAX);
    vector<int> B(n+1);
    for(int i = 0; i < n-1; i++) cin >> B[i];
    B[n] = INT_MAX;
    //--
    for(int in = 1; in < n; in++) {
        int minB = n;
        for(int i = 0; i < n-1; i++) {
            minB = (B[minB] > B[i] ? i : minB);
        }
        //
        A[minB]    = min(A[minB], B[minB]);
        A[minB+1]  = min(A[minB+1], B[minB]);
        B[minB] = INT_MAX;
    }
    //
    long long sum = 0;
    for(int i = 0; i < n; i++) sum += A[i];
    cout << sum;
}
