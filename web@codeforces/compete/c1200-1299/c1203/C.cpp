#include <bits/stdc++.h>
using namespace std;

int n, q;

int main(){
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	//--
	long long G = a[0];
	for(long long x : a) G = __gcd(G, x);
	//--
	int factCount = 0;
	for( long long i = 1; i * i <= G; i++ ){
		if( !( G % i) ) {
			factCount++;
			if( i*i != G ) factCount++;
		}
	}
	//
	cout << factCount;
}
