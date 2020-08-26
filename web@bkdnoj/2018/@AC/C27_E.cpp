#include <bits/stdc++.h>
using namespace std;

int a[100001] = {0};

int main(){
	int m, n, k;
	int inp;
	cin >> m >> n >> k;
	for(int i = 0; i < m*n; i++) {cin >> inp; a[inp]++;}

	inp = 0;
	sort(a, a+100001);
	for(int i = 0; i < k; i++) inp+=a[100000-i];
	cout << inp;
}