#include <bits/stdc++.h>
using namespace std;

int covered[64001];
int complement = 32000;

int main(){
	int n;
	int a, b;
	cin >> n;
	while(n > 0){
		n--;
		cin >> a >> b;
		covered[a+complement]++;
		covered[b+complement]--;
	}

	long status = 0, cvr = 0, max_cvr = 0;
	for(int i = 0; i < 64001; i++){
		status += covered[i];
		if(!!status) cvr++;
		else { max_cvr = max(max_cvr, cvr); cvr = 0; }
	}
	cout << max_cvr;
}