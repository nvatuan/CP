#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int turn = 0;
    while (a != b) {
        if (a % 2 == 1) {
            a += 1;
        } else {
            if (a > b) a /= 2;
            else a++;
        }
        turn++;
    }
    cout << turn << endl;
}