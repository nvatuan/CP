#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> p[2];
    cin >> p[0].first >> p[0].second >> p[1].first >> p[1].second;
    long long area = abs(p[0].first - p[1].first) * abs(p[0].second - p[1].second);
    cout << area << '\n';
}