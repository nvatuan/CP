#include <bits/stdc++.h>
using namespace std;

int main(){
	int i, n, a[10000];

	cin>>n;
	for(i = 0; i < n; i++) cin>>a[i];
	sort(a, a+n);
	
	cout<< max( max( max(a[n-1]*a[n-2]*a[n-3], a[n-1]*a[0]*a[1]), a[n-1]*a[n-2]), a[0]*a[1]);
}