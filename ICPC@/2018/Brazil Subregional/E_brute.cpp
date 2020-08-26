#include <bits/stdc++.h>
using namespace std;

string S, s;

int main() {
    cin >> S >> s;

    int Count = 0;
    for(int offset = 0; offset + s.length() <= S.length(); offset++) {
        for(int ic = 0; ic < s.length(); ic++) {
            if( S[offset+ic] == s[ic] ) {
                Count++;
                break;
            }
        }
    }

    cout << (S.length() - s.length() + 1) - Count;
}