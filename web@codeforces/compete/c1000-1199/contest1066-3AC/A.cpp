#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
#define BAC(i,a,b) for(i=a; i>b; i--)
#define br cout << endl
using namespace std;

long long t, i, strainl, strainr, L, v, ans;

int main(){
	cin >> t;
	while(t>0){
		ans = 0;
		t--;
		cin >> L >> v >> strainl >> strainr;
		ans += strainl/v - (strainl%v==0);
		ans += (L/v - strainr/v);
		cout << ans;
		br;
	}
}