#include <bits/stdc++.h>
using namespace std;

int t;
long long N;

int main() {
    ios::sync_with_stdio(0);
    
    long long turn, delta;
    long long result = 0;
    for (cin >> t; t; t--) {
        cin >> N;
        result = 0;    
        turn = 1;
        while (N > 0) {
            if ((N > 4 and N % 4 == 0) or N % 2 == 1) delta = 1;
            else delta = N/2;

            if (turn) result += delta;

            turn ^= 1;
            N -= delta;
        }
        cout << result << '\n';
    }
}