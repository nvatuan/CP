#include <bits/stdc++.h>
using namespace std;

#define DLEVEL first
#define EVALUE second

int n, c;
void debug(vector< pair<int, int> > vp){
	for(auto p : vp){
		cout << p.DLEVEL << ' ' << p.EVALUE << endl;
	}
}



int main(){
	cin >> n >> c;
	vector< long long > ano1 (c+10, 0);
	vector< long long > ano2 (c+10, 0);
	//
	int d, v;
	for(int i = 0; i < n; i++){
		cin >> d >> v;
		if(d == 1) ano1.push_back(v);
		else ano2.push_back(v);
	}
	sort(ano1.begin(), ano1.end(), greater<long long>());
	sort(ano2.begin(), ano2.end(), greater<long long>());

	if(c == 1){
		cout << ano1[0];
		return 0;
	}
	if(c == 2){
		cout << max(ano2[0], ano1[1]);
		return 0;
	}
	//
	for(int i = 1; i <= c; i++){
		ano1[i] += ano1[i-1];
	}
	for(int i = 1; i <= c; i++){
		ano2[i] += ano2[i-1];
	}
	//--
	//
	long long maxV = ano1[c];
	if(c > 1){
		maxV = max(maxV, ano2[c]);
	}
	for(int i2 = 2; i2 < c; i2 += 2){
		maxV = max(maxV,
				ano2[i2/2 - 1] + ano1[c - (i2) - 1]
			);
		//cout << i2 << ' ' << maxV << endl;
	}
	//
	cout << maxV;
}

	// for(int i = 0; i < n; i++){
	// 	cin >> anomaly[i].DLEVEL >> anomaly[i].EVALUE;
	// }