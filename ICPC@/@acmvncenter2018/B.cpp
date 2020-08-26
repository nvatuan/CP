#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
#define BAC(i,a,b) for(i=a; i>b; i--)
#define br cout << endl
using namespace std;

int main(){
	int i, j, bi, bj;
	string a[4];
	int d, t;
	//bool cld = false;

	FOR(i, 0, 4) cin >> a[i];
	FOR(i, 0, 3)
	  FOR(j, 0, 3)
	  	{d = 0, t = 0;
		    FOR(bi, 0, 2)
		       FOR(bj, 0, 2){
		       	if(a[i+bi][j+bj]=='.') d++;
		       	else t++;
		       }
		    if((d >= 3)||(t>=3)) {cout << "YES"; return 0;}
	    }
	cout << "NO";
}