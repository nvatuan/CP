#include <bits/stdc++.h>
using namespace std;

long long t, n, m, k;

int a[101];

int main(){
	for(cin >> t; t; t--){
		cin >> n >> m >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		//--
		int i = 0;
		while(i < (n-1) ){
			if(a[i] >= (a[i+1] - k) ){
				m += (a[i] - max(a[i+1] - k, 0LL) );
				i++;
			}
			else{
				m -= ( (a[i+1] - k) - a[i] );
				if( m < 0 ){
					break;
				}
				i++;
			}
		}
		//--
		cout << (i == (n-1) ? "YES\n" : "NO\n");
	}	
}
