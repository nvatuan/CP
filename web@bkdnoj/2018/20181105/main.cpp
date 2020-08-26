#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long (i) = (a); (i) <= (b); (i)++)
#define BAC(i, a, b) for(long long (i) = (a); (i) >= (b); (i)--)
#define br cout << "\n"
using namespace std;
typedef long long ll;
ll n, e;
//////////////////////////////////////////////
long long luythua(long long k, int exp){
	cout << n<<"^"<<e<<"= "<< k<<"^"<<exp<< "\n"; 
	if(exp == 0) return 1;
	if(exp == 1) return k;
	else if(exp%2 == 1) return luythua(k*k, exp/2)*n;
		 else return luythua(k*k, exp/2);
}
int main(){
	n = 3;
	e = 20;
	luythua(n, e);	
	return 0;
}
