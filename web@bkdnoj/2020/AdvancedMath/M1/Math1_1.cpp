// http://bkdnoj.dut.udn.vn/public/submit.php?id=Math1_1
#include <bits/stdc++.h>
using namespace std;

int n;
int a[101];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>() );
	//
	int G = a[0] - a[1];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			G = __gcd(G, a[i]-a[j]);
	//
	vector<int> answers;
	for(long long i = 1; i*i <= G; i++){
		if( G % i == 0 ) {
			answers.push_back(i);
			if( i*i != G ) answers.push_back(G/i);
		}
	}
	sort(answers.begin(), answers.end());
	for(int x : answers){
		if(x != 1) cout << x << ' ';
	}
}
