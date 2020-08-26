#include <bits/stdc++.h>
#define FOR(i, a, b) for(i=a;i<b;i++)
#define BAC(i, b, a) for(i=b;i>a;i--)
using namespace std;

int main(){
	long n;
	cin >> n;
	cout << (n/7)*2+(n%7==6) << ' ';
	if(n%7 <= 1)
		cout << ((n/7)*2+(n%7));
	else cout << ((n/7)*2+2);
}