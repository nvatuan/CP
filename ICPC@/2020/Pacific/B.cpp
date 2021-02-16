#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[(int)(2e5) + 10];

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];

    map<int, int> cnt;
    for (int i=0; i<n; i++) {
        cnt[a[i]]++;
    }

    set<int> nums;
    for (int i=1; i<=k; i++) nums.insert(i);
    
    for (int i=0; i<n; i++) {
        if (nums.size() > 0 and a[i] == *nums.begin()) {
            nums.erase(a[i]);
            printf("%d ", a[i]);
            cnt[a[i]] = -1;
        } else
        if (cnt[a[i]] == 1) {
            nums.erase(a[i]);
            printf("%d ", a[i]);
            cnt[a[i]] = 0;
        } else {
            cnt[a[i]]--;
        }
        if (nums.size() == 0) break;
    }
    printf("\n");
}