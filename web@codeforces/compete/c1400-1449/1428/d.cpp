#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5) + 10;
int n;
int bounces[N];
set<pair<int, int>> targets;

void die() {
    cout << -1 << '\n';
    exit(0);
}

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> bounces[i];

    map<int, int> fixed;
    set<int> heights;
    set<pair<int, int>> targets;
    for (int y=1; y<=n; y++) heights.insert(y);

    { // place 0 first
        for (int i=0; i<n; i++)
            if (bounces[i] == 0) fixed[i] = -1;
    }
    auto get_index_of = [&](int from, int value) -> int {
        return find(bounces + from, bounces + n, value) - bounces;
    };
    { // place 2-1 
        int pTwo = get_index_of(0, 2),
        pOne = get_index_of(pTwo + 1, 1); 
        if (pTwo < n and pOne == n) die();

        while (pTwo < n) {
            auto it = heights.rbegin();

            fixed[pTwo] = fixed[pOne] = *it;
            targets.insert({*it, pTwo+1});
            targets.insert({*it, pOne+1});
            heights.erase(*it);

            pTwo = get_index_of(pTwo + 1, 2);
            pOne = get_index_of(max(pOne+1, pTwo + 1), 1);
            if (pTwo < n and pOne == n) die();
        }
    }
    
    if ( any_of(bounces, bounces + n, [&](int x)->bool{return x == 3;}) ) { // place 3 - 3 - 3 .. 1
        stack<int> posOfThrees;
        for (int pThree = -1, prevPThree; ; ) {
            prevPThree = pThree;
            pThree = get_index_of(pThree + 1, 3);

            if (pThree < n) {
                posOfThrees.push(pThree);
            } else {
                int pNzAfterLastThree = prevPThree+1;
                for (; pNzAfterLastThree < n and (bounces[pNzAfterLastThree] == 0
                    or (bounces[pNzAfterLastThree] == 1 and fixed[pNzAfterLastThree] != 0)
                ); pNzAfterLastThree++);
                if (pNzAfterLastThree == n) die();
                posOfThrees.push(pNzAfterLastThree);
                break;
            }
        }
        
        int fTop = posOfThrees.top();
        posOfThrees.pop();
        int sTop = posOfThrees.top();
        posOfThrees.pop();
        int fHeight = *heights.rbegin(); heights.erase(*heights.rbegin());
        int sHeight = *heights.rbegin(); heights.erase(*heights.rbegin());

        if (fixed[fTop] == 0) {
            targets.insert({fHeight, fTop+1});
        }
        targets.insert({sHeight, fTop+1});
        targets.insert({sHeight, sTop+1});

        fixed[fTop] = fHeight;
        fixed[sTop] = sHeight;

        while (!posOfThrees.empty()) {
            fTop = sTop;
            sTop = posOfThrees.top();
            posOfThrees.pop();

            fHeight = sHeight;
            sHeight = *heights.rbegin(); heights.erase(*heights.rbegin());
            fixed[fTop] = fHeight;
            fixed[sTop] = sHeight;
            
            targets.insert({fHeight, fTop+1});
            targets.insert({sHeight, fTop+1});
            targets.insert({sHeight, sTop+1});
        }
    }
    { // places 1 1 1
        for (int i=0; i<n; i++)
            if (fixed[i] == 0) {
                if (bounces[i] != 1) die();
                targets.insert({*heights.begin(), i+1});
                heights.erase(heights.begin());
            }
    }

    // print
    cout << targets.size() << '\n';
    for (auto p : targets) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    solve();
}