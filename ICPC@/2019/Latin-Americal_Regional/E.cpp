#include <bits/stdc++.h>
using namespace std;

string Cake;
int S;

long long ans = 0;

int main() {
    cin >> Cake;
    cin >> S;
    // --
    string C = Cake + Cake + Cake;
    int L = Cake.length();
    int R = 2*Cake.length();
    // --
    queue<int> Q;
    for(int i = L; !(i >= R && Q.empty()); i++) {
        if(!Q.empty())
            if(i - Q.front() >= S) Q.pop();
        if(C[i] == 'E') {
            if((L <= i && i < R)) Q.push(i);
            else break;
        }
        if(!Q.empty())
            ans += max( 0, S - (i - Q.back()) );
    }
    //
    cout << ans;
}