#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i<= b; i++)
using namespace std;

bool possible = false;
long n, k, i;
long a[21];

void retry(int i, long sum){
	if(sum == k) {possible = true; return;}
	if(i <= n){
		retry(i+1, sum + a[i]);
		retry(i+1, sum);
	}
}

int main(){
	cin >> n;
	for(i = 1; i<=n; i++) cin >> a[i];
	cin >> k;
	retry(1, 0);
	//
	if(possible) cout << "Yes";
	else cout << "No";
}