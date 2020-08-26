#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i < b; i++)
#define BAC(i, b, a) for(i = b; i > a; i--)
using namespace std;
 
int main(){
	int n, i, j, k;
	long ans = 0;
	cin >> n;

	long edges[100];
	FOR(i, 0, n){ cin >> edges[i]; }
	sort(edges, edges + n);

	BAC(i, n-1, 1){ 
		BAC(j, i-1, 0){
			BAC(k, j-1, -1){
				if(edges[i] < edges[j] + edges[k])
					ans = max(ans, edges[i] + edges[j] + edges[k]);
	}}}

	cout << ans;
}