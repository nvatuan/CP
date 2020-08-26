#include <bits/stdc++.h>
#define FOR(i, a, b) for( int i = a; i <= b; i++)
using namespace std;

int DPL[10000][10000];
int lmax, la, lb;
string a, b;

void debug_console(){
	cout << "\n\n";

	cout << "  " << b << "\n\n";
	FOR(i, 1, la){
		cout << a[i-1] << " ";
		FOR(j, 1, lb) cout << DPL[i][j];
		cout << "\n";
	}
	cout << "\n";
}

int main(){

	cin >> a;
	cin >> b;
	
	la = a.length();
	lb = b.length();
	if(la < lb){
		a.swap(b);
		la^=lb^=la^=lb;
	}

	FOR(i, 1, la){
		DPL[i][0] = DPL[i-1][0];
		FOR(j, 1, lb){
			if(a[i-1] == b[j-1]) DPL[i][j] = DPL[i-1][j-1] + 1;
			else DPL[i][j] = max(DPL[i-1][j], DPL[i][j-1]);
		}
	}
	cout << DPL[la][lb];
}