#include <bits/stdc++.h>
using namespace std;

int main(){
	long long mmin, d, v, x, trip;
    cin >> d >> v >> x;
	
    if (d == 0 or v == 0 or x == 0) {
        long long i = 0;
        i += d/3;
        i += v/3;
        i += x/3;
        cout << i << endl;
    } else {
        mmin = min({d, v, x});

        d -= mmin;
        v -= mmin;
        x -= mmin;

        trip = (d/3 + v/3 + x/3);
        d %= 3;
        v %= 3;
        x %= 3;

        cout << mmin + trip + (d+v+x)/4 << endl;
    }
}