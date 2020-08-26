#include <bits/stdc++.h>
using namespace std;

int n, q;

int clock(vector<int> v){
	int a = v[0];
	for(int x : v){
		if( a == x ){
			a++;
			if(a > n) a = 1;
		}
		else return 0;
	}
	return 1;
}

int cclock( vector<int> v ){
	reverse(v.begin(), v.end());
	return clock(v);
}

int main(){
	for(cin >> q; q; q--){
		cin >> n;
		vector<int> p (n);
		for(int i = 0; i < n; i++) cin >> p[i];
		//--
		cout << ((clock(p) || cclock(p)) ? "YES\n" : "NO\n");
	}
}
