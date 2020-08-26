#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    //
    vector<int> M (n+1, 0);
    //
    queue<int> Q;
    for(int a, i = 0; i < n; i++) {
        cin >> a;
        Q.push(a);
    }
    //
    int fined = 0;
    vector<int> ignored (n+1, 0);
    for(int a, i = 0; i < n; i++) {
        cin >> a;
        //
        if( Q.front() != a ) {
            fined++;
            ignored[a] = 1;
        } else {
            Q.pop();
        }
        //
        while( !Q.empty() && ignored[Q.front()] ) Q.pop();
    }
    //
    cout << fined; 
}