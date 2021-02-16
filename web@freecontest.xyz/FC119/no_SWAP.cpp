#include <bits/stdc++.h>
using namespace std;

string s;
int n;
deque<int> pos[26];

int alpha_ord(char c) { return c - 'a'; }

const int N = 200010;
int indentLeft[N];

void updateL(int x, int v) { // 1-indexed
    x = (N - x + 1);
    for (; x < N; x += (x & -x)) indentLeft[x] += v;
}
long long prefixL(int x) {
    x = (N - x + 1);
    long long res = 0;
    for (; 0 < x; x -= (x & -x)) res += indentLeft[x];
    return res;
}

int indentRight[N]; 

void updateR(int x, int v) { // 1-indexed
    for (; x < N; x += (x & -x)) indentRight[x] += v;
}
long long prefixR(int x) {
    long long res = 0;
    for (; 0 < x; x -= (x & -x)) res += indentRight[x];
    return res;
}

int main() {
    cin >> s;
    n = (int) s.length();

    for (int i = 0; i < n; i++) {
        pos[alpha_ord(s[i])].push_back(i);
    }

    if (n % 2 == 0) {
        if ( all_of(pos, pos + 26, [&](deque<int> dq){ return dq.size() % 2 == 0; }) );
        else { cout << -1 << '\n'; return 0; }
    } else {
        if ( count_if(pos, pos+26, [&](deque<int> dq) { return dq.size() % 2 == 1; }) == 1 );
        else { cout << -1 << '\n'; return 0; }
    }

    int L = 0, R = n-1;
    int leftmost_i = 0, rightmost_i = n-1;
    long long ans = 0;
    while (L < R) {
        cerr << L << ' ' << R << '\n';
        int cL = alpha_ord(s[L]);
        int cR = alpha_ord(s[R]);
        int actual_index_R = pos[cR].front() - prefixR(pos[cR].front() + 1) + prefixL(pos[cR].front() + 1); 
        //+1 because my BIT is 1-indexed
        int actual_index_L = pos[cL].back() + prefixL(pos[cL].back() + 1) - prefixR(pos[cL].back() + 1);
        int mirror_R = actual_index_R - leftmost_i;
        int mirror_L = rightmost_i - actual_index_L;

        if (mirror_R <= mirror_L) { // move char to mirror char at R
            ans += mirror_R;
            // move char at pos[cR].front() to 0,
            // which is the same as moving it to leftmost_i, and increment some prefix
            updateL(pos[cR].front() - 1, 1);
            pos[cR].pop_front();
            leftmost_i++;
            R--;
        } else {
            ans += mirror_L;
            updateR(pos[cL].back() + 1, 1);
            pos[cL].pop_back();
            rightmost_i--;
            L++;
        }
    }
    cout << ans << '\n';
}