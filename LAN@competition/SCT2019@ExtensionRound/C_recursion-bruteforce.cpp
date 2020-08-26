#include <bits/stdc++.h>
using namespace std;

#define ATK first
#define HP second

int n, m;
pair<int, int> cardA[61], cardB[61];

int maxVal = 0;

void Try(int k, int subVal){
	if(k == n){
		maxVal = max(maxVal, subVal);
	}
	else{
		for(int i = 0; i < m; i++){
			if(cardB[i].HP > 0){
				cardB[i].HP -= cardA[k].ATK;
				cardA[k].HP -= cardB[i].ATK;
				//--
				if((cardB[i].HP <= 0) && (cardA[k].HP > 0)){
					Try(k+1, subVal + 1);
				}
				else Try(k+1, subVal);
				//--
				cardB[i].HP += cardA[k].ATK;
				cardA[k].HP += cardB[i].ATK;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> cardA[i].ATK >> cardA[i].HP;
	cin >> m;
	for(int i = 0; i < m; i++) cin >> cardB[i].ATK >> cardB[i].HP;
	//--
	Try(0, 0);
	cout << maxVal;
}