#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5;
int n;

int size[N];
int notes[N][7];

int noteLabel(int x) {
    return (x-1) % 7;
}


int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> size[i];
        for (int j=0; j<size[i]; j++) {
            int x; cin >> x;
            x = noteLabel(x);
            notes[i][x]++;
        }
    }

    bool flag = true;
    for (int i=1; i<n; i++) {
        int same = 0;
        for (int d=0; d<7; d++) same += (min(notes[i-1][d], notes[i][d]) > 0);
        int n_1 = size[i-1]/2; 
        flag &= (same >= n_1);
    }
    cout << (flag ? "YES\n" : "NO\n");
}