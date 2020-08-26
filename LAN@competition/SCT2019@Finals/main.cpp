#include <bits/stdc++.h>
using namespace std;

long long a[30001];

int L, R, k;
int N, Q;

long long sumMin(){
	vector<long long> v;
	for(int i = L-1; i < R; i++){
		v.push_back(a[i]);
	}
	//--
	sort(v.begin(), v.end());
	//
	long long res = 0;
	for(int i = 0; i < k; i++){
		res += v[i];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//
	cin >> N >> Q;
	for(int i = 0; i < N; i++) cin >> a[i]; //scanf("%lld", &a[i]);	
	//--
	int type;
	long long v;
	while(Q--){
		cin >> type;
		switch(type){
			case 1:
				cin >> type >> v;
				a[type] += v;
				break;
			case 2:
				cin >> L >> R >> k;
				//printf("%lld\n", sumMin());
				cout << sumMin() << '\n';
				break;
			default: assert(0);
		}
	}
}