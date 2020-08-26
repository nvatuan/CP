#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
#define BAC(i,a,b) for(i=a; i>b; i--)
#define br cout << endl
#define llong long long
using namespace std;

llong a;
int t;

int one_in_a(llong a){
	llong b = pow(2, 30);
	int one = 0;
	while(b > 0){
		if(a>=b){a -= b; one++;}
		b /= 2;
		//cout << b; br;
	}
	return one;
}

int main(){
	//pls dont hack :((
	cin >> t;
	while(t > 0){
		t--;
		cin >> a;
		cout << (llong) pow(2, one_in_a(a)); br;
	}
}