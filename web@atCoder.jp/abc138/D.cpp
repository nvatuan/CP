#include <bits/stdc++.h>
using namespace std;

int n;
int q;

vector<int> E[200001];

long long addUp[200001];
long long res[200001];

int main(){
	cin >> n;
	cin >> q;
	//
	long long a, b;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		E[a].push_back(b);
	}
	while(q--){
		cin >> a >> b;
		addUp[a] += b;
	}
	//
	queue< pair<int, long long> > Q;
	Q.push( {1, addUp[1]} );
	//
	while(!Q.empty()){
		int V = Q.front().first;
		long long val = Q.front().second;
		Q.pop();
		//
		res[V] = val;
		//
		for(int x : E[V]){
			Q.push( {x, val + addUp[x]} );
		}
		//
	}
	//
	for(int i = 1; i <= n; i++) cout << res[i] << ' ';
}
