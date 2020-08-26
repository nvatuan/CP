#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A (N);
    for(int i = 0; i < N; i++) cin >> A[i];
    //
    int maxTravel = 0;
    int subTravel = 0;
    for(int i = N-1; 0 < i; --i) {
        if( A[i-1] >= A[i] ) subTravel++;
        else {
            maxTravel = max(subTravel, maxTravel);
            subTravel = 0;
        }
    }
    maxTravel = max(subTravel, maxTravel);
    cout << maxTravel;
}
