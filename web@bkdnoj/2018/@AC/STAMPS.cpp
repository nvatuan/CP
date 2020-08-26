#include <bits/stdc++.h>
using namespace std;

int main(){
	long s;
	int n, i;
	int a[10000];
	int ans = 0;

	cin >> s >> n;
	for(i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	//cout << i;

	while(s > 0){
		i--;
		if(i < 0) break;
		s -= a[i];
		ans++;
		//cout << ans << endl;
	}
	cout << ((s <= 0) ? ans : 0);
}