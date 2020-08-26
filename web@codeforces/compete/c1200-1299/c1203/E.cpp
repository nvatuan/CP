#include <bits/stdc++.h>
using namespace std;

int m[150003];

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];	
	//
	sort(a.begin(), a.end());
	int ans = 0;
	for(auto x : a){
		if( x > 1 && !m[x-1] ) m[x-1]++, ans++;
		else{
			if( !m[x] ) m[x]++, ans++;
			else if( !m[x + 1] ) m[x+1]++, ans++;
		}
	}
	//
	cout << ans;
}
