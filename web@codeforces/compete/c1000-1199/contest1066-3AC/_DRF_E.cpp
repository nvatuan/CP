#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
#define BAC(i,a,b) for(i=a; i>b; i--)
#define br cout << endl
using namespace std;

long to_dec(string bin, int len){
	long a = 0, b = 1;
	if (len == 0) return 0;
	else{
		do {
			len--;
			a = a + b*(bin[len] == '1');
			b *= 2;
		} while(len > 0);
		return a;
	}
}

int main(){
	//God dammit learnt C/C++ for like what? 2-3 weeks now i have to do all sort of thing with zero knowledge about standard functions and lib
	//tfw code is a fucking essay feelsgoodman
	long i, n, m;
	long modu = 998244353;
	long long ans = 0;
	long long
	cin >> n >> m;
	string a, b;
	cin >> a;
	cin >> b;
	
	while(m > 0){
		m--;
		FOR(i, 0, m)

	}
	
	
	//cout << b;
}