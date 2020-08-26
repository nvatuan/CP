#include <bits/stdc++.h>
using namespace std;
#define br cout << endl

int main(){
	long long n, k;
	long h[200001];
	long sH[200001] = {0};
	long i;

	cin >> n >> k;
	for(i = 0; i < n; i++) cin >> h[i];
	sort(h, h+n);
	for(i = n-1; i > -1; i--) sH[h[i]]++;
	for(i = h[n-1]-1; i >= h[0]; i--) 
		sH[i] += sH[i+1];


	long long cum = 0;
	long ans = 0;
	for(i = h[n-1]; i > h[0]; i--){
		if(cum + sH[i] > k){
			cum = 0;
			ans++;
		}
		cum += sH[i];
		//cout << "SH[" << i << "]: " << sH[i]; br;
		//cout << i << " c: " << cum; br;
	}

	//cout << ans + (cum%k!=0); br; 
	cout << (ans + (cum/k) + (cum%k!=0));
}