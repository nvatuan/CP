#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define br cout << "\n"
using namespace std;

int n, k;
int a[10001];
int occurence[1001];
bool a_max, a_min;

void solve(int max, int min){
	int omax=0, omin=0;
	int maxid=0, minid=0;
	FOR(i, 1, k){
		if(occurence[i] == max){
			omax++;
			maxid = i;
		}
		if(occurence[i] == min){
			omin++;
			minid = i;
		}
	}

	if((omax>1)&&(omin>1)) {cout << '*'; return;}
	if(!((omax==1)&&((max==2)||(min==0))&&(omin==1))) {cout << '*'; return;}
	if(omax == 1) cout << '-' << maxid;
	if((omax==1)&&(omin==1)) cout << ' ';
	if(omin == 1) cout << '+' << minid;
}

int main(){
	cin >> k >> n;
	FOR(i, 1, n) {cin >> a[i]; occurence[a[i]]++;}
	//
	FOR(i, 2, k) {occurence[i] -= occurence[1];} //
	occurence[1] = 0;

	int mmax = occurence[1], mmin = occurence[1];
	FOR(i, 2, k) {
		mmax = max(mmax, occurence[i]);
		mmin = min(mmin, occurence[i]);
	}

	if((abs(mmax)>2)||(abs(mmin)>2)) {cout << '*'; return 0;}
	else{
		solve(mmax, mmin);
	}
}
