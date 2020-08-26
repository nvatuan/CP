#include <bits/stdc++.h>
using namespace std;

string Add(string a, string b){
	int ia = a.length() - 1;
	int carry = 0;

	string res = "";

	for(int i = b.length()-1; (i > -1) || (ia > -1); i--, ia--){
		int bita;
		int bitb;
		//
		if(ia < 0) bita = 0;
		else bita = a[ia] - '0';
		if(i < 0) bitb = 0;
		else bitb = b[i] - '0';
		//
		int bitr = bita + bitb + carry;
		//--
		if(bitr == 0) res = '0' + res, carry = 0;
		if(bitr == 1) res = '1' + res, carry = 0;
		if(bitr == 2) res = '0' + res, carry = 1;
		if(bitr == 3) res = '1' + res, carry = 1;
		//--
	}
	if(carry) res = '1' + res;
	return res;
}

int lexi(string a, string b){
	int ia = 0, ib = 0;
	while(ia < a.length() && ib < b.length()){
		if(a[ia] != b[ib]){
			return a[ia] < b[ib];
		}
		ia++, ib++;
	}
	//--
	if(ia == a.length()) return 1;
	return 0;
}

int main(){
	//
	int T;
	string x, y;
	string minK;
	//--
	for(cin >> T; T; T--){
		cin >> x;
		cin >> y;
		//--
		int ans = 0;
		int k = 0;
		int notset = 0;

		while(k <= max(x.length(), y.length()) ){
			string subK;
			subK = Add(x, y);
			//
			reverse(subK.begin(), subK.end());
			//
			if(!notset){
				minK = subK;	
				notset = 1;
				ans = 0;
			}
			else{

				//
				if( lexi(subK, minK) ){
					minK = subK;
					ans = k;
				}	
			}
//			cout << minK << " : " << subK << " @" << k << endl;
			//
			k++;
			y += '0';
		}
		//--
		cout << ans << '\n';
	}	
}
