#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define br cout << "\n"
using namespace std;

long n;
int a[100001], b[100001];
int t[100001];
bool imp;

bool retry(){
	FOR(k, 2, n){
		imp = true;
		FOR(i, 0, 3){
			if( (a[k] == (i|t[k]) )&&(b[k] == (i&t[k])) ){
				t[k+1] = i; 
				imp = false;
				break;
			}
		}
		if(imp) return false;
	}

	cout << "YES"; br;
	FOR(k, 1, n+1)
		cout << t[k] << " ";
	return true;
}

int main(){
	cin >> n;

	n--;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	t[1] = -1;

	FOR(i, 0, 3){
		FOR(j, 0, 3){
			if( ((i&j) == b[1])&&((i|j)==a[1]) ){
				t[1] = i;
				t[2] = j;
				if(retry()) return 0;
			}
		}
	}
	cout << "NO";
}