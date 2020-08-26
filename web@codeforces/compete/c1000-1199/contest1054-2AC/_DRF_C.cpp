#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define BAC(i, a, b) for(int i = a; i >= b; i--)
using namespace std;

int id[1001][1001];
int cdy[1001];
int incre;

int main(){
	int n;
	int l[1001], r[1001];
	cin >> n;
	FOR(i, 1, n) cdy[i] = 1;

	FOR(i, 1, n){
		cin >> l[i];
		if(l[i] == incre){
			id[incre][0]++;
			id[incre][ id[incre][0] ] =  i;
		}
		else{
			int rp, cp = incre;
			FOR(j, 1, l[i]){
				rp = id[cp][0];
				if(rp == 0) {cp--; j--; continue;}
				
			}
			incre++;
		}
	}
}