///https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/

#include <bits/stdc++.h>
using namespace std;

int A[21][21];
int dp[21][(1<<21)];

bool travelPath(std::vector<std::string> pathList)
{
    std::function<std::string (std::string)> toLower;
    toLower = [](std::string orig) -> std::string{
        for(char &c : orig) {
            if('A' <= c && c <= 'Z') c += ('a' - 'A');
        }
        return orig;
    };
    //
    unordered_map<string, int> cityID;
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
    //cerr << "Init graph\n";
    int N = cityCount;
    // vector< vector<int> > A  ( N+1, vector<int> ( N+1       , 0 ) );
    // vector< vector<int> > dp ( N+1, vector<int> ( 1 << (N+1), 0 ) );
    //cerr << "Init adjacent list\n";
    for( int i = 1; i <= N; i++ ) {
        for( int &c : edge[i] ) {
            A[i][c] = A[c][i] = 1;
        }
    }
    //
    //cerr << "DP'ing..\n";
    for(int i = 1; i <= N; i++) 
        dp[i][1<<(i-1)] = i;
    //
    for(int state = 0; state < (1<<N); state++) {
        for(int i = 1; i <= N; i++)
            if( (state >> (i-1)) & 1 ) {
                for(int j = 1; j <= N; j++)
                    if( ((state >> (j-1)) & 1) && A[i][j] && i != j && dp[j][ state^(1 << (i-1)) ]) {
                        dp[i][state] = dp[j][ state^(1 << (i-1)) ];
                        break;
                    }
            }
    }
    //--
    for(int end = 1; end <= N; end++)
        if( dp[end][(1<<N)-1] ) {
            int start = dp[end][(1<<N)-1];
            if(A[start][end]) return 1;
        }
    return 0;            
}

int main() {
    vector<string> p = {"ab-bc", "bc-cd", "cd-de", "de-ab"};
    cout << (travelPath(p) ? "yes" : "nah");
}