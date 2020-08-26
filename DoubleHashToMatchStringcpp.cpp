#include <bits/stdc++.h>
using namespace std;

const long long MOD  = 1000000123;
const long long MOD2 = 1000000321;
const int P = 27;

string st;
int stLen = 0;

long long expo[1000001], expo2[1000001];

int answer = 0;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a < b) return 1;
    else{
        if(a == b){
            return a.first < b.first;
        }
    }
    return 0;
}

int rollingHash(int len){
    vector<pair<int, int> > hashes, hashes2;
    int times = 0;
    //
    long long lengthy = expo[len-1];
    long long lengthy2 = expo2[len-1];
    //--

    long long hash = 0, hash2 = 0;
    for(int i = 0; i < len; i++){
        hash = hash * P;
        hash = hash + (st[i] - 'a' + 1);
        hash = hash % MOD;
        //
        hash2 = hash2 * P;
        hash2 = hash2 + (st[i] - 'a' + 1);
        hash2 = hash2 % MOD2;
    }

    int j = len;
    while(j < stLen){
        hashes.push_back(  {hash, times}  );
        hashes2.push_back( {hash2, times} );
        times++;
        //--
        hash = hash - ((st[j-len] - 'a' + 1) * lengthy);
        hash =  hash * P;
        hash = (hash + (st[j] - 'a' + 1));
        hash =  hash % MOD;
        //==
        hash2 = hash2 - ((st[j-len] - 'a' + 1) * lengthy2);
        hash2 =  hash2 * P;
        hash2 = (hash2 + (st[j] - 'a' + 1));
        hash2 =  hash2 % MOD2;
        //
        j++;
    }
    hashes.push_back( {hash, times} ); hashes2.push_back( {hash2, times} );
    //-- Check hash
    sort(hashes.begin(),  hashes.end(),  cmp);
    sort(hashes2.begin(), hashes2.end(), cmp);
    //
    pair<int, int> pi;
    map< pair<int, int>, int> ID;
    for(auto it = next(hashes.begin()); it != hashes.end(); it++){
        if( (it-1)->first == (it)->first ){
            pi = make_pair( (it-1)->second, (it)->second );
            ID[pi]++;
        }
    }
    for(auto it = next(hashes2.begin()); it != hashes2.end(); it++){
        if( (it-1)->first == (it)->first ){
            pi = make_pair( (it-1)->second, (it)->second);
            if(ID[ pi ]) return 1;
        }
    }
    //
    return 0;
}

int main(){
    //freopen("t.txt", "r", stdin);
    //
    expo[0] = 1;
    for(int i = 1; i < 1000001; i++){
        expo[i] = expo[i-1] * P % MOD;
    }
    expo2[0] = 1;
    for(int i = 1; i < 1000001; i++){
        expo2[i] = expo2[i-1] * P % MOD2;
    }
    //
    ios::sync_with_stdio(0);
    //cin >> st;
    getline(cin, st);
    stLen = st.length();
    //--
    int L = 0, R = stLen;
    while( L < R ){
        int mid = (L+R+1)/2;
        //
        if(rollingHash(mid)){
            L = mid;
        }
        else{
            R = mid - 1;
        }
    }
    //--
    cout << L;
}