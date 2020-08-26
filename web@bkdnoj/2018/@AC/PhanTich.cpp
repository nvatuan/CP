#include <bits/stdc++.h>
using namespace std;

bool no[100000] = {false};
int comp[100000] = {0};

int main(){
	int n, i;
	cin >> n;
	long long pwr;

	for(i = 2; i <= n; i++){
		if(!no[i]){
			pwr = (long long) i*i;
			//if(pwr <= 0) continue;
			while(pwr <= n){
				no[pwr] = true;
				pwr += i;
			}
		}
	}

	for(i = 2; i <= n; i++)
		if(!no[i]){
			pwr = i;
			do {
				comp[i] += n/pwr;
				pwr *= i;
			} while(pwr <= n);
		}

	for(i = 2; i <= n; i++)
		if(!no[i]) cout << i << ' ' << comp[i] << endl;
}