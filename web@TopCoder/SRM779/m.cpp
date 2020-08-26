#include <bits/stdc++.h>
using namespace std;

class OperateString {
	public:
		string operate(string S, vector<int> arg) {
			long long sum = 0;
			for(int&i : arg) sum += i;
			//
			sum %= S.length();
			//
			if( sum < 0 ) sum += S.length();
			//
			string res = 
			string(S.begin() + sum, S.end()) + string(S.begin(), S.begin() + sum);
			return res;
		}
};

// --


class OneGcd {
	public:
		long long CountDivides(long long L, long long R, int K) {
			return (R/K) - (L-1)/K;
		}
		vector<int> solve(vector<long long> X, vector<int> Y) {
			vector<int> factor {2, 3, 5, 7};
			// --
			unordered_map<int, int> SET;
			for(int subset = 0; subset < (1<<4); subset++) {
				int mul = 1;
				for(int i = 0; i < 4; i++)
					if( subset & (1<<i) ) mul *= factor[i];
				SET[subset] = mul;
			}
			//
			vector<int> vans;

			for(int i = 0; i < X.size(); i++) {
				long long xx = X[i];
				long long yy = Y[i];
				int ans = 0;
				//
				int state = 0;
				for(int i = 0; i < 4; i++) {
					if(yy % factor[i] != 0) continue;
					state |= (1 << i);
				}
				//cerr << yy << " has state " << state << endl;
				//
				for(int subset = 1; subset < (1<<4); subset++) {
					bool next = false;
					if( (subset ^ (state & subset)) != 0 ) next = true;
					if(next) continue;
					
					//cerr << SET[subset] << " | subset: " << subset << endl;
					int C = __builtin_popcount(subset);
					//cerr << CountDivides(xx, xx+yy-1, SET[subset]) << endl;
					if( C & 1 )
						ans += CountDivides(xx, xx+yy-1, SET[subset]);
					else
						ans -= CountDivides(xx, xx+yy-1, SET[subset]);
				}
				//
				vans.push_back(yy - ans);
			}
			return vans;
		}
};

int main() {
	OneGcd gg;
	vector<long long> X {10};
	vector<int>       Y {15};
	auto v = gg.solve(X, Y);
	for(int i : v) cout << i << " ";
}
