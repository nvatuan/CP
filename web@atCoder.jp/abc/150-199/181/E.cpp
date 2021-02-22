    #include <bits/stdc++.h>
    using namespace std;

    int n, f;

    const int N = (int)(1e6);
    int child[N], form[N];

    const int INF = (int)2e9;

    int main() {
        cin >> n >> f;
        for (int i=1; i<=n; i++) cin >> child[i];
        child[0] = -INF;
        child[n+1] = INF;
        n+=2;

        for (int i=0; i<f; i++) cin >> form[i];
        sort(child, child+n);
        sort(form, form+f);

        unordered_map<int, int> ansLR, ansRL;
        for (int i=2; i<n-1; i+=2) {
            ansLR[i] = ansLR[i-1] + (child[i] - child[i-1]);
            ansLR[i+1] = ansLR[i];
        }
        for (int i=n-3; i>0; i-=2) {
            ansRL[i] = ansRL[i+1] + (child[i+1] - child[i]);
            ansRL[i-1] = ansRL[i];
        }


        int start = 0;
        for (; start < f and form[start] < child[1]; start++);
        int finish = f-1;
        for (; 0 <= finish and child[n-2] < form[finish]; finish--);
        
        int ans = INF;

        if (0 < start) ans = min(ans, child[1] - form[start-1] + ansRL[2]);
        if (finish + 1 < f) ans = min(ans, form[finish+1] - child[n-2] + ansLR[n-3]);
        
        // cout << start << ' '<< finish << endl;
        // cout << ans << endl;

        int t = start;
        int l = 1;
        while (t <= finish) {
            int subans=ans;
            while (child[l] <= form[t]) {
                if (child[l] <= form[t] and form[t] <= child[l+1])
                    if (l & 1) {
                        subans = ansLR[l-1] + form[t] - child[l] + ansRL[l+1];
                    } else {
                        subans = ansLR[l] + child[l+1] - form[t] + ansRL[l+2];
                    }
                // printf("%d -> %d\n", l, subans);
                l++;
            }
            ans = min(ans, subans);
            t++;
        }
        cout << ans << endl;
    }