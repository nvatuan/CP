/*
ID: nvatuan2
PROG: gift1
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stdlib.h>
using namespace std;

int n, k;
vector<string>              names;
vector<int>                 balances;
unordered_map<string, int>  INDEX;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    //
    cin >> n;
    names.resize(n);
    balances.resize(n, 0);
    //
    int ind = 0;
    for(string& S : names) {
        cin >> S;
        cin.ignore();
        INDEX[S] = ind++;
    }
    //
    string giver;
    int amount, no_receiver;
    for(int i = 0; i < n; i++) {
        cin >> giver;
        cin.ignore();

        cin >> amount >> no_receiver;
        cin.ignore();
        // --
        if(no_receiver == 0) continue;
        //
        balances[INDEX[giver]] -= (amount - amount % no_receiver);
        amount = amount / no_receiver;
        //
        for(string recipient; no_receiver; no_receiver--) {
            cin >> recipient;
            cin.ignore();
            balances[INDEX[recipient]] += amount;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << names[i] << ' ' << balances[i] << '\n';
    }
    return 0;
}