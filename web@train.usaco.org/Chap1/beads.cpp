/*
ID: nvatuan2
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    //
    int N;
    string S;
    cin >> N;
    cin >> S;

    auto Prev = [&](int i) -> int{
        return (i-1 + S.length()) % S.length();
    };
    auto Next = [&](int i) -> int{
        return ((i+1) % S.length());
    };

    // --
    int ans = 0;
    for(int i = 0; i < int(S.length()); i++) {
        // cout << i << " "<< ans << " ";
        //
        char sample;
        sample = S[i];
        // cout << sample << "\n";
        //
        int  b1 = 1;
        int  anc = i;
        for( int j = Next(i); j != i; j = Next(j) ) {
            if(sample == 'w' && S[j] != sample) sample = S[j];
            // cout << j << ":" << S[j] <<"|";
            if(S[j] == 'w' || S[j] == sample) b1++;
            else break;
            //
            anc = j;
        }
        // cout << '\n' << b1 << " "; 
        // --
        sample = S[Prev(i)];
        // cout << sample << "\n";
        //
        int  b2 = 1;
        if(anc == Prev(i)) b2 = 0;
        else {
            for( int j = Prev(Prev(i)); j != anc; j = Prev(j) ) {
                if(sample == 'w' && S[j] != sample) sample = S[j];
                // cout << j << ":" << S[j] <<"|";
                if(S[j] == 'w' || S[j] == sample) b2++;
                else break;
            }
        }
        //
        // cout << '\n' << b2 << "\n";
        ans = max(ans, b1+b2);
    }
    //
    cout << ans << '\n';
}