#include <bits/stdc++.h>
using namespace std;

int L, G;

pair<int, int> p[100002];
pair<int, int> anchor = {1000000000, 1000000000};

void input() {
    cin >> L >> G;
    if (L == 0 && G == 0) exit(0);
    for (int i = 0; i < G; i++) {
        cin >> p[i].first >> p[i].second;
        p[i].first -= p[i].second;
        p[i].second = (p[i].first + 2*p[i].second);
    }
}

void solve() {
    sort(p, p + G, [&](pair<int, int> p1, pair<int, int> p2) -> bool {
            if (p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }
    );

    int Left = 0, Right = 0;
    int segUsed = 0;

    for (int i = 0; i < G; i++) {
        if (Left < p[i].first) {
            Left = Right;
            segUsed++;
        }
        if (p[i].first <= Left && Right <= p[i].second) {
            Right = max(Right, p[i].second);
        }
    }

    if (Left < L && Left < Right) {
        Left = Right; segUsed++;
    }

    if (Left < L) printf("-1\n");
    else printf("%d\n", G - segUsed);
}

int main() {
    int t = 0;
    while (true) {
        // t++;
        input();
        solve();
        // if (t == 665) {
        //     cerr << L << ' ' << G << endl;
        //     for (int i = 0; i < G; i++)
        //         cerr << p[i].first << ' ' << p[i].second << endl;
        // }
    }
}