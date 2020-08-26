#include <bits/stdc++.h>
using namespace std;

vector< int > visited;

vector< vector<int> > edgeList;

unordered_map<string, int> ID;
vector< int > Cost;

int globalMin;

void dfs(int x) {
    globalMin = min(globalMin, Cost[x]);
    visited[x] = 1;
    for(auto &v : edgeList[x]) 
        if(!visited[v]) dfs(v); 
}

int cinemasBuildingCost(vector<string> citiesList, vector<string> roads) {
    int cityCount = 1;
    Cost.push_back(0);
    //--
    for(auto &s: citiesList) {
        int idx = s.find(';');
        string cityName     = s.substr(0, idx);
        string buildCost    = s.substr(idx+1);
        if( ID[cityName] == 0 ) {
            ID[cityName] = cityCount;
            Cost.push_back(stoi(buildCost));
            cityCount++;
        }
    }
    //-- note: cities is 1-indexed
    edgeList = vector< vector<int> > (cityCount + 1, vector<int>());
    //
    for(auto &s: roads) {
        int idx = s.find(';');
        string cityFrom     = s.substr(0, idx);
        string cityTo       = s.substr(idx+1);
        //
        edgeList[ ID[cityFrom] ].push_back( ID[cityTo] );
        edgeList[ ID[cityTo] ].push_back( ID[cityFrom] );
    }
   //--
   long long ans = 0;
   visited = vector< int > (cityCount + 1, 0);
   for(int i = 1; i < cityCount; i++) {
       if( !visited[i] ) {
           globalMin = INT_MAX;
           dfs(i);
           ans += globalMin;
       }
   }
   //--
   return ans;
}


int main() {

}