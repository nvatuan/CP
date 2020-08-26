#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int N;
long long L, R;

const int SIZE = 1000001;

long long a[SIZE];
long long prf_a[SIZE];

long long dp[SIZE];
long long prf_dp[SIZE];

long long prefix_sum(long long *a, int i, int j){
	return *(a + j) - *(a + i - 1);
}

int index_bs(int val, int L, int R, long long *a){
	int mid;
	//
	while(L < R){
		mid = (L + R + 1) / 2;
		if(a[mid] > val) R = mid - 1;
		else L = mid;
		//
	}
	//--
	if(a[L] <= val) return L;
	return -1;
}

int main(){
	// long long ar[] = {1, 3, 5, 7, 9, 11};
	// cout << index_bs(15, 0, 5, ar);
	// return 0;
	//
	freopen("in", "r", stdin);
	cin >> N >> L >> R;	
	for(int i = 1; i <= N; i++){
		cin >> a[i];
		prf_a[i] = a[i];
		prf_a[i] += prf_a[i-1];
	}
	//--------
	for(int i = 1; i <= N; i++){
		int LL = index_bs(R, 1, i, prf_a);
		int RR = index_bs(L, 1, i, prf_a);
		cout << LL << ' ' << RR << endl;
		//--
		if(RR == 0 || LL == 1) dp[i] = 1;
		else dp[i] = prf_dp[RR - 1] - prf_dp[LL - 2];
		//
		prf_dp[i] = prf_dp[i-1] + dp[i];
	}
	//--
	for(int i = 1; i <= N; i++){
		cout << prf_dp[i] << ' ';
	}
}