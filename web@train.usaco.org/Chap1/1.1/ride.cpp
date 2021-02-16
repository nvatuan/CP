/*
ID: nvatuan2
PROG: ride
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

string S1, S2;

int main() {
    ifstream F ("ride.in");
    ofstream f ("ride.out");
    //
    F >> S1 >> S2;
    long long m1 = 1, m2 = 1;
    for(char& c : S1) m1 *= int(c - 'A') + 1;
    for(char& c : S2) m2 *= int(c - 'A') + 1;
    // for(int i = 0; i < S1.length(); i++) m1 *= int(S1[i]);
    // for(int i = 0; i < S2.length(); i++) m2 *= int(S2[i]);
    //
    f << (m1 % 47 == m2 % 47 ? "GO" : "STAY") << endl;
    return 0;
}