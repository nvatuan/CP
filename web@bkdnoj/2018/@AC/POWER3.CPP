#include <bits/stdc++.h>
using namespace std;

int main(){
	int tmp, base;
	cin>>base;
	if(base==1){cin>>base; cout<<(base%3);}
	else{
		cin>>base;
		if(base%3 == 2){
			cin >> base;
			if(base%2) cout<<2;
			else cout<<1;
		}
		else cout << (base%3);
	}
}