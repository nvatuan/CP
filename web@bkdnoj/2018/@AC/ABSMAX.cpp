#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long a[200000];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);

	cout << max(abs(a[0]+a[1]), a[n-2]+a[n-1]);
}