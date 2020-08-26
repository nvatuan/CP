///https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/

#include <bits/stdc++.h>
using namespace std;

bool travelPath(std::vector<std::string> pathList)
{
    std::function<std::string (std::string)> toLower;
    toLower = [](std::string orig) -> std::string {
        for(char &c : orig) {
            if('A' <= c && c <= 'Z') c += ('a' - 'A');
        }
        return orig;
    };
    //
    unordered_map<string, int> cityID;
    unordered_map<string, int> duplicate;
    //
    int cityCount = 0;
    // --
    vector< vector<int> > edge;
    // --
    for(string path : pathList) {
        int split = path.find('-');
        string city1 = path.substr(0, split);
        string city2 = path.substr(split+1, (path.size() - split - 1) );
        //
        city1 = toLower(city1);
        city2 = toLower(city2);
        //
        string concat = (min(city1, city2)+max(city1,city2));
        if( duplicate[ concat ] ) continue;
        duplicate[concat] = 1;
        //
        if( !cityID[city1] ) {
            cityCount++;
            cityID[city1] = cityCount;
        }
        if( !cityID[city2] ) {
            cityCount++;
            cityID[city2] = cityCount;
        }
        int c1 = cityID[city1];
        int c2 = cityID[city2];
        //
        while( int(edge.size()) < (cityCount + 1) ) edge.push_back( vector<int>() );
        edge[c1].push_back(c2);
        edge[c2].push_back(c1);
    }
    // --
    vector<int> city (cityCount+1, 0);
    //
    std::function<bool (int, int) > dfs;
    dfs = [&](int c, int depth) -> bool {
        city[c] = 1;
        //
        for( int nextCity : edge[c] ) {
            if(!city[nextCity]) {
                if( dfs(nextCity, depth + 1) ) return 1;
            }
        }
        if( depth == cityCount  ) {
            for(int nC : edge[c] ) if( nC == 1 ) return 1;
        }
        //
        city[c] = 0;
        //
        return 0;
    };
    //
    return dfs(1, 1);
}

int main() {
    vector<string> p = {"ab-bc", "bc-cd", "cd-de", "de-ab"};
    cout << (travelPath(p) ? "yes" : "nah");
}