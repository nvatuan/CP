#include<bits/stdc++.h>
using namespace std;
#define ll long long 
set<pair<pair<string,string>,string>> m;
map<string,ll> mm;

int main(){
    ll n;
    cin>>n;
    ll i;
    string a,b,c;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
         m.insert({{a,b},c}) ;
        //cout<<a<<" "<<b<<" "<<c<<'\n';
    }
    for(auto p: m){
        mm[p.second]++;
    }
    for(auto h: mm ){
        ll check = 0;
        if(h.second>=10) check=1;
        cout<<h.first<<" "<<h.second<<" ";
        if(check==1) cout<<"YES"<<'\n';
        else cout<<"NO\n";
    }
}
