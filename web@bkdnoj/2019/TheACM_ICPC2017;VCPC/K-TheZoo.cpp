#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m;
	cin >> n >> m;

	if((n > m) || (m > n*2)) cout << "IMPOSSIBLE";
	else if( (n%2 == 1)||(m%2 == 1) ) cout << "IMPOSSIBLE";
		 else cout << (m-n)/2 << " " << (2*n - m)/2;
}