#include <bits/stdc++.h>
using namespace std;

int n, q;

int yn( vector<int> a ){
	int L = 0, R = n-1;
	int area = a[0] * a[n-1];
	//--
	while(L < R){
		if( a[L] * a[R] != area ) return 0;
		if( a[L] != a[L+1] ) return 0;
		if( a[R] != a[R-1] ) return 0;
		L += 2;
		R -= 2;
	}
	return 1;
}

int main(){
	for(cin >> q; q; q--){
		cin >> n;
		n = n*4;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		//---
		sort(a.begin(), a.end());
		//
		cout << (yn(a) ? "YES\n" : "NO\n");
	}
}