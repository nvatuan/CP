#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100], b[100];
int cnt1[100], cnt2[100];
int ed[100][100];
int n1, n2;
int chk[100], cc[100];
vector<int> lst;
int del[100];
int Visited[100], Assigned[100];
int t = 0;
bool visit(int u) {
    if (Visited[u]!=t) 
        Visited[u]=t; 
    else 
        return false;
        
    for (int v : b[u])
    if (!Assigned[v] || visit(Assigned[v])) { 
        Assigned[v]=u; 
        return true; 
    }
    return false;
}
int solve(int mask){
	t = 0;
	memset(del, 0, sizeof(del));
	memset(Visited, 0, sizeof(Visited));
	memset(Assigned, 0, sizeof(Assigned));
	memset(cc, 0, sizeof(cc));
	for(int i = 1; i <= n; i++) b[i].clear();
	vector<int> temp;
	for(int i = 0; i < lst.size(); i++){
		del[lst[i]] = 1;
		if(mask & (1 << i)) temp.push_back(lst[i]);
	}
	for(int x : temp){
		for(int y : temp){
			if(ed[x][y]) return 0;
		}
	}
	for(int u : temp){
		for(int i = 1; i <= n; i++){
			if(ed[u][i]) del[i] = 1;
		}
	}
	int n1 = 0, n2 = 0;
	for(int i = 1; i <= n; i++){
		if(del[i]) continue;
		for(int v : a[i]){
			if(del[v]) continue;
			b[i].push_back(v);
			if(cc[v] == 0){
				cc[v] = 1;
				n2++;
			}
		}
		if(!b[i].empty()){
			cc[i] = 1;
			n1++;
		}
	}
	int max_matching = 0;
	for(int i = 1; i <= n; i++){
		if(b[i].empty()) continue;
		t++;
		max_matching += visit(i);
	}
	int max_dependent_set = n1 + n2 - max_matching;
	int ans = max_dependent_set;
	for(int i = 1; i <= n; i++){
		if(del[i]) continue;
		if(cc[i] == 0) ans++;
	}
	return ans + __builtin_popcount(mask);
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		ed[x][y] = ed[y][x] = 1;
		if(cnt1[y]){
			if(chk[y] == 0){
				chk[y] = 1;
				lst.push_back(y);
			}
		}
		if(cnt2[x]){
			if(chk[x] == 0){
				chk[x] = 1;
				lst.push_back(x);
			}
		}
		cnt1[x]++;
		cnt2[y]++;
		if(cnt2[y] == 0){
			n2++;
			cnt2[y] = 1;
		}
	}
	//// Brute force
	int ans = 0;
	for(int i = 0; i < (1 << (int)lst.size()); i++){
		ans = max(ans, solve(i));
	}
	cout << ans + 1 << "\n";
}