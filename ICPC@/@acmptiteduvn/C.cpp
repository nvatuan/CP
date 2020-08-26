#include <bits/stdc++.h>
using namespace std;

string mir;
long long emit[3], ray[3];
bool mirror[3];
long long mr, sr1, sr2;
long long me, se1, se2;

bool possible(){
	if(mir == "110"){
		mr = 2; sr1 = 0; sr2 = 1;
		me = 2; se1 = 0; se2 = 1;
	}
	if(mir == "011"){
		mr = 0; sr1 = 1; sr2 = 2;
		me = 0; se1 = 1; se2 = 2;
	}
	if(mir == "101"){
		mr = 1; sr1 = 0; sr2 = 2;
		me = 1; se1 = 0; se2 = 2;
	}
	if(ray[mr] == 0) return(false);
	if(ray[mr] * emit[me] > 0)	return(false);
	ray[mr] *= -1;
	cout << ray[0] << ' ' << ray[1] << ' ' << ray[2];
	return(true);
}

int main(){
	int n;
	cin >> n;
	while(n > 0){
		n--;
		cin >> emit[0] >> emit[1] >> emit[2];
		cin >> ray[0] >> ray[1] >> ray[2];
		cin >> mir;
		//mirror[0] = (mir[0]=='1');
		//mirror[1] = (mir[1]=='1');
		//mirror[2] = (mir[2]=='1');
		if(!possible()) cout << "-1";
	}	
}