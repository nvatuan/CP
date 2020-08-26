#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll distance(int x1, int y1, int x2, int y2){
	return pow(x1-x2, 2) + pow(y1-y2, 2);
}

int main(){
	int i, n, j, k = 0;
	int righttri = 0;
	long x[1500], y[1500];
	unsigned long d[2248500];

	cin >> n;
	for(i = 0; i < n; i++) cin >> x[i] >> y[i];

	for(i = 0; i < n-1; i++)
		for(j = i+1; j < n; j++){
			d[k] = distance(x[i], y[i], x[j], y[j]);
			k++;
		}
	sort(d, d+k);
	
	

	cout << righttri;
	return 0;
}