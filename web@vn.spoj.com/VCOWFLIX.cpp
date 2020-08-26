#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i<= b; i++)
using namespace std;

int n, c, i;
int w[17];
int ans;

void retry(int k, int weight){
	if(k > n) ans = max(ans, weight);
	else{
		if(weight + w[k] <= c) retry(k+1, weight + w[k]);
		retry(k+1, weight);
	}
}

int main(){
	cin >> c >> n;
	for(i = 1; i<=n; i++) cin >> w[i];
	retry(1, 0);
	cout << ans;
}