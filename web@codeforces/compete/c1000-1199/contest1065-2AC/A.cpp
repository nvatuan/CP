#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	long long s, a, b, c;
	cin >> t;
	while(t > 0){
		t--;
		cin >> s >> a >> b >> c;
		cout << s/c + ((s/c)/a*b) << endl;
	}
}