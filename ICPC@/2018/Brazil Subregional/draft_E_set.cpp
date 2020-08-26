#include <bits/stdc++.h>
using namespace std;

vector<set<int>> index ( 26, set<int>() );
string Cyp, Crib;

int main() {
    cin >> Cyp >> Crib;
    //
    for(int i = 0; i < Cyp.length(); i++) {
        index[Cyp[i] - 'A'].insert(i);
    }
    //
    for(int off = 0; off < (Cyp.length() - Crib.length() + 1); off++) {
        for(int alpha = 0; alpha < 26; alpha++) {
            
        }
    }
}