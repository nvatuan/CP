#include <bits/stdc++.h>
using namespace std;

class ZigZag {
    public:
    int dp[2][51];
    int longestZigZag(vector<int> seq) {

        int n = seq.size();
        //
        for(int i = 0; i < n; i++) dp[0][i] = dp[1][i] = 1;
        //
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if( seq[i] < seq[j] ) {
                    dp[0][j] = max( dp[0][j], dp[1][i] + 1 );
                } 
                if( seq[i] > seq[j] ) {
                    dp[1][j] = max( dp[1][j], dp[0][i] + 1 );
                }
            }
        }
        return max(dp[0][n-1], dp[1][n-1]);

    }
};

int main() {
    int tmp;
    vector<int> seq;
    while(cin >> tmp) seq.push_back(tmp);
    //
    ZigZag instance;
    cout << instance.longestZigZag(seq);
}