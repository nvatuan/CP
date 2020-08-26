#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define BAC(i,a,b) for(i=a; i>=b; i--)
#define br cout << endl
using namespace std;

int n, r, i, j, ans, counter;
int a[1001], c[1001];

int main(){
	cin >> n >> r;
	bool heated;
	FOR(i, 0, n-1) cin>>a[i];
	i = 0;
		//cout << i << "->";
	while(i < n){
		heated = false;
		BAC(j, r-1, -r+1){
			if((0<=i+j)&&(i+j<=1000))
				if(a[i+j]){
					heated = true;
					ans++;
					i = i+j+r-1;
					break;
					//cout << i << ' '; br;
				}
		}
		if(!heated) {cout << -1; return 0;}
		i++;
	}
	cout << ans;
}