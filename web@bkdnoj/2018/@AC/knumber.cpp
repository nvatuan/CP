#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin>>n>>k;
    ll a[100000];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    cout<<a[k-1];
    return 0;
}
