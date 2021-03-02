#include <bits/stdc++.h>
using namespace std;
#ifndef PI
#define PI (3.14159265358979323846)
#endif

#define eps (1e-9)

struct Fighter {
    int x, y, a, r;

    int hasVisionOf(Fighter fo) {
        double lower = a - r;
        double upper = a + r;
        double ang = atan2(fo.y - this->y, fo.x - this->x);
        // if (ang < 0.0) ang += PI*2;
        ang = ang / PI * 180;

        // fprintf(stderr, "lower=%lf, upper=%lf\n", lower, upper);

        for (int delta=-360*2; delta <= 360*2; delta += 360) {
            double newang = ang + delta;

            // fprintf(stderr, "newang = %lf\n", newang);
            if (lower <= newang + eps && newang-eps <= upper) return true;
        }
        return false;

        // int dx=fo.x-x, dy=fo.y-y;
        // double ang=atan2(dy,dx);
        // if(ang<0) ang +=2*PI;
        // ang*=180/PI;
        // bool in=0;
        //     int ll = (a - r + 360) % 360;
        //     int rr = (a + r + 360) % 360;
        // if(ll>rr){
        //     if(ang+eps>=ll || ang-eps<=rr)
        //         in=1;
        // } else if(ang+eps>=ll && ang-eps<=rr) in=1;
        // return in;
    }
};

int N;
vector<Fighter> fs;

vector<vector<int>> G;
int poss = 1;

int main() {
    cin >> N;
    fs.resize(N);
    G.assign(N, vector<int>());
    for (Fighter &f : fs) {
        cin >> f.x >> f.y >> f.a >> f.r;
    }

    unordered_map<int, int> indeg;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            if (i != j) {
                // fprintf(stderr, "Checking %d and %d\n", i, j);
                if (fs[i].hasVisionOf(fs[j])) {
                    // fprintf(stderr, "#%d nhin thay #%d\n", i, j);
                    G[i].push_back(j);
                    indeg[j]++;
                }
            }
    }

    // topological_sort();
    queue<int> q;
    for (int i=0; i<N; i++) q.push(i);
    int timeout = q.size();
    int poss=1;

    vector<int> ans;
    while (not q.empty()) {
        // cerr << q.size() << endl;
        // for (int i=0; i<N; i++) {
        //     cerr << i << ' ' << indeg[i] << endl;
        // }

        int fr = q.front(); q.pop();
        if (indeg[fr] > 0) {
            if (!timeout) {
                poss = 0;
                break;
            }
            timeout--;

            q.push(fr);
            continue;
        } else {
            timeout = q.size();

            ans.push_back(fr);
            for (int nxt : G[fr]) {
                indeg[nxt]--;
            }
        }
    }
    
    if (poss) {
        for (int i : ans) printf("%d ", i+1);
        printf("\n");
    } else {
        printf("-1\n");
        return 0;
    }
}