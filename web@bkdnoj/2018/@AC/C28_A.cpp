#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i < b; i++)

using namespace std;

int abs(int k){
	return (k>0) ? k : k*-1;
}

int main(){
	int n, i, j;
	string route;
	int cx = 0, cy = 0;
	string yes = "-1";
	int mx = 0, my = 0;

	cin >> cx >> cy >> route;
	//cin.ignore();
	//getline(cin, route);

	FOR(i, 0, route.length()){
		if( (abs(cx-mx) <= 1) && (abs(cy-my) <= 1) )
			{ cout << i << endl;
			  yes = "";
			}

		switch(route[i]){
			case 'U' :	my++;
					 	break;
			case 'D' :	my--;
						break;
			case 'L' :	mx--;
						break;
			case 'R' :	mx++;
						break;
		}
		
		//cout << "  x: " << mx << " y: " << my <<endl;
	}
	if( (abs(cx-mx) <= 1) && (abs(cy-my) <= 1) ) {cout << i;}
	else cout << yes;

	//thoi nghi khong lam nua
}