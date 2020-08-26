#include <bits/stdc++.h>
using namespace std;

long long sum(vector<long long> a){
	long long s = 0;
	for(auto x : a) s += x;
	return s;
}

int n, l, r;

int main(){
	cin >> n >> l >> r;
	vector<long long> a (n, 1);
	//--
	int i = 1;
	l--;
	r--;
	while(l--){
		a[i] = a[i-1]*2;
		i++;
		r--;
	}
	cout << sum(a) << ' ';
	//
	while(r--){
		a[i] = a[i-1]*2;
		i++;
	}
	while(i < n){
		a[i] = a[i-1];
		i++;
	}
	//
	cout << sum(a);
}

