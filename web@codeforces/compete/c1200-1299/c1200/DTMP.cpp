#include <bits/stdc++.h>
using namespace std;

int n, k;

#define DB if(1)

int bR[2002], bC[2002];
int bB[2002][2002];

int WR[2002], WC[2002];

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			bB[i][j] = (c == 'B');
			bR[i] += (c == 'B');
			bC[j] += (c == 'B');
		}
	}
	// 
	int alreadyW = 0;
	for(int i = 1; i <= n; i++){
		alreadyW += (bR[i] == 0);
		alreadyW += (bC[i] == 0);
		//
		WR[i] = (bR[i] == 0);
		WC[i] = (bC[i] == 0);
	}
	// -- prefix
	for(int i = 1; i <= n; i++) bR[i] += bR[i-1], bC[i] += bC[i-1];
	for(int i = 1; i <= n; i++) WR[i] += WR[i-1], WC[i] += WC[i-1];
	// -- 2d prefix
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			bB[i][j] += (bB[i-1][j] + bB[i][j-1] - bB[i-1][j-1]);
		}
	}
	//
	DB{
		for(int i = 1; i <= n; i++){
			cout << "bR[" << i << "] " << bR[i] << endl;
		}	

		for(int i = 1; i <= n; i++){
			cout << "bC[" << i << "] " << bC[i] << endl;
		}	

		for(int i = 1; i <= n; i++){
			cout << endl;
			for(int j = 1; j <= n; j++){
				cout << bB[i][j] << ' ';
			}
		}
	}

	//--
	int maxAns = alreadyW;
	for(int i = 1; i <= n-k+1; i++){
		for(int j = 1; j <= n-k+1; j++){
			int B_tiles = (
				bB[i+k-1][j+k-1] 
				- bB[i+k-1][j-1] 
				- bB[i-1][j+k-1] 
				+ bB[i-1][j-1]
			);
			if( 
				B_tiles*2 == 
				(bR[i+k-1] - bR[i-1]) + (bC[j+k-1] - bC[j-1]) 
			){
				int subAns = (
					alreadyW 
					- (WR[i+k-1] - WR[i-1]) 
					- (WC[j+k-1] - WC[j-1])
					+ k + k
				);
				maxAns = max(maxAns, subAns);
			}
		}
	}
	//--
	cout << maxAns;
}
