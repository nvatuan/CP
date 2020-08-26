#include <bits/stdc++.h>
using namespace std;

int t;
int n, k, d;

//int counter[1000005];

int a[200001];

int main() {
	for(cin >> t; t; t--) {
		//fill(counter, counter + 1000001, 0);
		vector<int> counter (1000005, 0);
		set<int> distinct;
		//
		scanf("%d%d%d", &n, &k, &d);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		//
		int L = 0, R = 0;
		for(; R < d; R++) {
			if( counter[a[R]] == 0) distinct.insert(a[R]);
			counter[a[R]]++;
		}
		//
		unsigned ans = distinct.size();
		for(; R < n; L++, R++) {
			counter[a[L]]--;
			if( !counter[a[L]] ) distinct.erase( a[L] );

			counter[a[R]]++;
			if( counter[a[R]] == 1) distinct.insert(a[R]);
			
			ans = min(ans, distinct.size() );
		}
		//
		printf("%d\n", ans);
	}
}