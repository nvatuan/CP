#include <bits/stdc++.h>
using namespace std;

class BadNeighbors {
    public:
    int n;

    int dynamic( vector<int> dono, int L, int R ) {
        int address[43];
        int *dp = address + 2;
        dp[L-2] = 0;
        dp[L-1] = 0;
        //
        for(int i = L; i <= R; i++) dp[i] = dono[i];
        for(int i = L; i <= R; i++) {
            for(int j = i-1; L <= j; --j) {
                dp[i] = max( dp[i-1], dp[i-2] + dono[i] );
            }
        }
        //
        return dp[R];
    }

    int maxDonations(vector<int> dono) {
        n = dono.size();
        return max(dynamic(dono, 0, n-2), dynamic(dono, 1, n-1));
    }
};

int main() {
    BadNeighbors instance;
    vector<int> v \
     { 10, 3, 2, 5, 7, 8 }
     ;
    cout << instance.maxDonations(v);
}