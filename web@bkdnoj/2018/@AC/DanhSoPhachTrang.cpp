#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int d[10] = {0};

	for(int i = 1; i <= n; i++){
		int page = i;
		while(page > 0){
			d[page % 10]++;
			page /= 10;
		}
	}
	for(int i = 0; i < 10; i++)
		cout << i << ' ' << d[i] << endl;
}