#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    cin >> S;

    int one = 0, zero = 0;
    for(const char &c : S) {
        one     += (c == '1');
        zero    += (c == '0');
    }

    if(zero < one) {
        cout << string( S.length(), '0');
        return 0;
    } 
    if(zero > one) {
        cout << string( S.length(), '1');
        return 0;
    }
    if(zero == one) {
        string s;
        int n = S.length() - 1;
        if( S[n] == '1' ) {
            s = string( S.length(), '1' );
            s.back() = '0';
        } else {
            s = string( S.length(), '0' );
            s.back() = '1';
        }
        cout << s;
    }
}