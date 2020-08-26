#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, w;
    cin >> N >> w;
    vector<int> horn(N);
    for(int i = 0; i < N; i++) cin >> horn[i];

    vector< pair<int, int> > hornOrder( N );
    for(int i = 0; i < N; i++) hornOrder[i] = {horn[i], i};
    sort(hornOrder.begin(), hornOrder.end(), greater< pair<int,int> >() );
    //
    vector<int> form(N, 0);
    //
    for(int k = 0; k < N; k++) {
        int i = hornOrder[k].second;
        for(int j = max(i-w, 0); j <= min(i+w, N-1); j++)
            if(i != j) {
                if( horn[i] < horn[j] ) form[i] = max(form[i], form[j] + 1);
            }
    }
    cout << *max_element(form.begin(), form.end());
}
