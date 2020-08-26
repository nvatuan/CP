#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long (i) = (a); (i) <= (b); (i)++)
#define BAC(i, a, b) for(long long (i) = (a); (i) >= (b); (i)--)
#define br cout << "\n"
using namespace std;
typedef long long ll;

struct wbrand{
	int alco;
	int id;
} w;

bool comp(wbrand a, wbrand b){
	return a.alco < b.alco;
}

wbrand bottle[1001];
int used[1001];
int n, q, k;

void specialCase(){
	cout << "YES"; br;
	used[bottle[k].id]++;
	FOR(i, 1, n){
		cout << used[i] << " ";
	}
}

long long dq()

int main(){
//	ios::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> q;
	FOR(i, 1, n){ 
		cin >> w.alco;
		w.id = i;
		bottle[i] = w;
	}

	sort(bottle+1, bottle+1+n, comp);
	FOR(i, 1, n) cout << bottle[i].alco << " ";br;

	k = n;
	while(k){
		if(bottle[k].alco <= q) break;
		k--;
	}

	if(bottle[k].alco == q) specialCase();
	else{

		ll val = q;
		BAC(i, k, 1){
			val = val % bottle[i].alco;
		}
		if(!!val) {cout << "NO"; return 0;}

		val = q;
		BAC(i, k, 1){
			used[bottle[i].id] += (val/bottle[i].alco);
			val = val % bottle[i].alco;
		}
	}
	cout << "YES"; br;
	FOR(i, 1, n){
		cout << used[bottle[i].id] << " ";
	}
}