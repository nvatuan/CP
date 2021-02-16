#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> q;

int main() {
    scanf("%d%d", &N, &K);
    while (N--) {
        int type;
        scanf("%d", &type);
        // for (int i : q) cout << i << ' ';
        // cout << endl;
        switch (type) {
            case 1: {
                int att; scanf("%d", &att);
                q.push_back(att);
            }
                break;
            case 2: {
                int L = (q.size() >= K ? K : q.size());
                auto it = max_element(q.end()-L, q.end());
                printf("%d\n", *it);
                q.erase(it);
            }
                break;
            case 3: {
                int pos; scanf("%d", &pos);
                q.push_back(q[pos-1]);
                q.erase(q.begin() + pos-1);
            }
                break;
        }
        
    }
}