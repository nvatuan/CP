#include <bits/stdc++.h>
using namespace std;

const int __debug_mode = 1;
const int __multitest = 0;
#define db if(__debug_mode)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- template ends here
int counter;
int N, M;
int park[100001];

void solve() {
    counter = 0;
    cin >> N >> M;
    for (int t, v, i = 0; i < M; i++) {
        cin >> t >> v;
        if (t == 1) {
            if (counter == 0) {
                park[0] = v;
                cout << 1;
            } else
            if (counter == 1) {
                for (int i = 0; i < N; i++)
                    if (park[i] != 0) {
                        if (i-1 < N-i) {
                            park[N-1] = v;
                            cout << N;
                        } else {
                            park[0] = v;
                            cout << 1;
                        }
                        break;
                    }
            } else {
                int maxDist = 0;
                int parkIndex = 0;
                int firstParked = 0;  while(park[firstParked] == 0) firstParked++;
                maxDist = (firstParked);
                int lastParked = N-1; while(park[lastParked] == 0) lastParked--;
                if (maxDist < (N - lastParked - 1)) {
                    maxDist = (N - lastParked - 1);
                    parkIndex = (N-1);
                }

                int l = firstParked;
                int i = l;

                while (l < N) {
                    int r = l + 1;
                    while (r < N and park[r] == 0) r++;
                    if (r == N) break;
                    if (maxDist < (r-l)/2) {
                        maxDist = (r-l)/2;
                        parkIndex = (r+l)/2;
                    }
                    l = r;
                }
                park[parkIndex] = v;
                cout << parkIndex + 1;
            }
            counter++;
            cout << '\n';
        } else {
            for (int i = 0; i < N; i++) {
                if (park[i] == v) {
                    park[i] = 0;
                    counter--;
                    break;
                }
            }
        }
    }
}

int main() {
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}

