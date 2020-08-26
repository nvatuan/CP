#include <bits/stdc++.h>
using namespace std;

string st = "abcdefghijklmnopq";

int l;

int val = 0;

void gen(int k, vector< string > bags){
	if(k >= l){
		val++;
		for(auto S : bags){
			cout << S << ' ';
		}
		cout << endl;
	}
	else {
		int lz = 0;
		bags.push_back("");

		while(1){
			if(k + lz >= l) break;
			//
			bags[bags.size() - 1] += st[k + lz];
			gen(k + lz + 1, bags);
			lz++;
		}
	}
}

int main(){
	l = 4;
	vector< string > vs;
	gen(0, vs);
	//
	cout << val;
}