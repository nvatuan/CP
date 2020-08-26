#include <bits/stdc++.h>
using namespace std;

map<string, int> Index;
long long timeleft[52];

int N;

int main() {
    string S;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> S >> timeleft[i];
        Index[S] = i;
    }
    for(int i = N-2; i >= 0; i--) {
        timeleft[i] += timeleft[i+1];
    }
    cin >> S;
    cout << timeleft[Index[S] + 1];
}