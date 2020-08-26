#include <bits/stdc++.h>
using namespace std;

string S;
int N;
int vector<int> compress;

int main() {
    cin >> S;
    N = S.length();
    // --
    S = S[0] + S;
    char sign = '?';
    for(int i = 0; i < N; i++) {
        if(sign == S[i]) {
            if(S[i] == '>') Seg[i+1] = Seg[i] - 1;
            else            Seg[i+1] = Seg[i] + 1;
        } else {
            compress.push_back(0);
            
        }
    }
}