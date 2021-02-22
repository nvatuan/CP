#include <bits/stdc++.h>
using namespace std;

int prob, subb;

bool ac[100001];
int pen[100001];

int TotalPen;
int TotalAC;

int main() {
    cin >> prob >> subb;
    int    pi;
    string verdict;
    while(subb--) {
        cin >> pi >> verdict;
        if(verdict == "AC" && ac[pi]) continue;
        if(verdict == "WA" && ac[pi]) continue;
        if(verdict == "AC" && !ac[pi]) {
            ac[pi] = true;
            continue;
        }
        if(verdict == "WA" && !ac[pi]) {
            pen[pi]++;
            continue;
        }
    }
    for(int i = 1; i <= prob; i++) {
        TotalAC  += ac[i];
        if(ac[i]) TotalPen += pen[i];
    }
    cout << TotalAC << " " << TotalPen << endl;
    return 0;
}
