#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;

struct gae{
	int val;
	int fre;
};

int a[200001];
gae freq[200009];
long uniq;

bool comp(gae a, gae b){
	return (a.fre > b.fre);
}

int an[200001];
int ans;

int foo(int idx){
	int ans = 0;
	for(int i = 0; i <= idx; i++){
		ans += freq[a[i]].fre / freq[a[idx]].fre;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i;
	cin >> n >> k;
	for(i = 1; i<=n; i++) {
		cin >> a[i]; 
		freq[a[i]].val = a[i];
		if(freq[a[i]].fre == 0) uniq++;
		(freq[a[i]].fre)++;
	}

	sort(freq+1, freq+200001, comp);

	 // for(i = 1; i<=n; i++) cout << freq[i].val << " ";
	 // cout << "\n";
	 // for(i = 1; i<=n; i++) cout << freq[i].fre << " ";
	 // cout << "\n";

	int tmp;
	freq[0].fre = freq[1].fre;

	int val = foo(k);
	int L = 0, R = k;
	while(L < R){
		mid = (L+R)/2;
		if(val < foo(mid)){
			R = mid;
		}
		else{
			
		}

	}

	for(i = 1; i<=uniq; i++) {
		cout << freq[a[i]].fre << " ";
	}
	//cout << "\n";
	for(i = 0; i<ans; i++) cout << an[i] << " ";
}