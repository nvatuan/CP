#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

long n, m;
vector<LL> va, vb;
long long s, t;

int main(){
	cin >> n >> m;
	while(s + (t+1) <= (n + m)){ s += ++t; }
	
	for(LL i = t; i >= 1; i-- ){
		if(n >= i){
			va.push_back(i);
			n -= i;
		}
		else vb.push_back(i);
	}

	cout << (long) va.size() << "\n";
	for( LL i : va ) cout << i << " ";
	cout << "\n" << (long) vb.size() << "\n";
	for( LL i : vb ) cout << i << " ";
	//With courtesy to cf.com/profile/Heltion
}