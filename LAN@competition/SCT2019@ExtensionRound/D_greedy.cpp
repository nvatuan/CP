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
	vector<pair<int, int> > anomaly (n);
	//
	for(int i = 0; i < n; i++){
		cin >> anomaly[i].DLEVEL >> anomaly[i].EVALUE;
	}
	//--
	sort(anomaly.begin(), anomaly.end(), greater< pair<int, int> >());
	//--
	for(int i = 0; i < n; i++){
		if(c >= )
	}
}