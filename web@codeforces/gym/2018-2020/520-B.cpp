#include <bits/stdc++.h>
using namespace std;

int n, m;

int v[20002];

int bfs(){
	queue< pair<int, int> > qi;
	qi.push({n, 0});
	//
	while(!qi.empty()){	
		auto p = qi.front();
		qi.pop();
		//
		if(v[p.first]) continue;
		v[p.first] = 1;
		//--
		if(p.first == m) return p.second;
		//
		if(p.first*2 <= m*2) qi.push({p.first * 2, p.second + 1});
		if(p.first > 1) qi.push({p.first - 1, p.second + 1});
	}
	return -1;
}

int main(){
	cin >> n >> m;
	//
	cout << bfs();
}