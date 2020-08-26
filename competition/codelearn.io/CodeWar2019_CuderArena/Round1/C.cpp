#include <bits/stdc++.h>
using namespace std;

int numberSteps(int n, std::vector<int> arr, int m)
{
    if(m == n)  return 0;
    if(m == 0) {
        for( int x : arr ) if(x == 0) return 1;
        return -1;
    }
    if(m < n)   return -1;
    sort(arr.begin(), arr.end());
    // dp
    vector<int> step (m+1, INT_MAX);
    step[n] = 0;
    for(int i = n; i <= m; i++) {
        if(step[i] != INT_MAX) {
            for(int x : arr) {
                if(1LL*i + x <= m) step[i+x] = min(step[i+x], step[i] + 1);
                else break;
            }
            for(int x : arr) {
                if(1LL*i * x <= m) step[i*x] = min(step[i*x], step[i] + 1);
                else break;
            }
        }
    }
    //
    if(step[m] == INT_MAX) return -1;
    return step[m];
}

int main() {
    vector<int> arr {1, 2, 3, 4};
    cout << numberSteps(0, arr, 0);
}