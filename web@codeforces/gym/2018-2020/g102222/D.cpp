#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int n;

int ans     = 1;
int Omega   = 2;

void check() {
    if( A.front() == 1 ) return;
    if( A.back() == 1 ) return;
    Omega++;
    if(A.back() == n) ans++;
}

int main() {
    //cin >> n;
    for(n = 1; n < 10; n++) {
        ans = 1;
        Omega = 2;
        //
        A = vector<int> (n, 0);
        for(int i = 0; i < n; i++) A[i] = i+1;
        // --
        do {
            check();
        } while(  next_permutation(A.begin(), A.end()) );
        // --
        printf("With n = %d, ans = %d / Omega = %d\n", n, ans, Omega);
        printf("Prob == %.9lf\n", double(ans)/Omega);
    }
}