#include <iostream>
#include <vector>
using namespace std;

int cnts, cntw;
int s, w;

int a, b;

void solve() {
    cin >> a >> b;
    cin >> cnts >> cntw;
    cin >> s >> w;
    if (s > w) {
        swap(s, w);
        swap(cnts, cntw);
    }

    int ts = min(cnts, a/s);
    int ans = 0;
    for (; ts >= 0; ts--) {
        int tw = min(cntw, (a - ts*s)/w);
        
        int ls = cnts - ts;
        int lw = cntw - tw;
        
        int tts = min(ls, b/s);
        int ttw = min(lw, (b - tts*s)/w); 
        ans = max(ans, ts + tw + tts + ttw);
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}