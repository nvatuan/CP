#include <bits/stdc++.h>
using namespace std;

#define DB if(0)

inline void no(){
	cout << "No";
	exit(0);
}

int main(){
	int n;	cin >> n;
	vector<int> a (n+1);
	for(int i = 0; i < n; i++) cin >> a[i];
	a[n] = INT_MAX;
	//-----------------------------
	for( int i = n-1 ; i > 0; i-- ){
		if(a[i-1] - 1 > a[i]) no();
		if(a[i-1] > a[i]){
			a[i-1]--;
		}
	}
	if(a[0] - 1 > a[1]) no();
	//
	cout << "Yes";
}
