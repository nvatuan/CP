#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define BAC(i, b, a) for(i = b; i >= a; i--)
#define br cout << "\n"
using namespace std;

long n;
long long s[1000001];
long i, j, tmp, prv;
long ans;

int main(){
	cin >> n;
	FOR(i, 1, n){
		cin >> tmp;
		s[i] = s[i-1] + tmp;
	}
	sort(s, s+n+1);

	//FOR(i, 0, n) cout << s[i] << " ";
	//br;

	prv = s[0]; tmp = 1;
	FOR(i, 1, n){
		if(s[i] == prv) {ans += tmp; tmp++;}
		else {prv = s[i]; tmp = 1;}
	}
	cout << ans;
}