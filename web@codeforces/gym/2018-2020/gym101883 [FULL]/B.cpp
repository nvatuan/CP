#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, x, y;
    ll t;
    cin>>a>>b;
    x = a;
    y = b;
    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    cout<<(x*y)/a;
    return 0;
}
