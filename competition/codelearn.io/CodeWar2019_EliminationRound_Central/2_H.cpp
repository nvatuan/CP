#include <bits/stdc++.h>
using namespace std;

// -- Direction (D, L, U, R)
const pair<int, int> d[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int KeyCount    =  0;
int M;
int GateCount   =  0;

int startX, startY;
int H, W;
vector<vector<int>> Map, GateOnlyMap;

#define WALL    2
#define KEY     3
#define GATE    4

void conventional_map(vector<string> islandMap) {
    H = islandMap.size();
    W = islandMap[0].size();
    Map = vector< vector<int> > (H + 2, vector<int>(W + 2, WALL));
    GateOnlyMap = Map;
    // --
    int y = 1, x = 1;
    for(const string &S : islandMap) {
        x = 1;
        for(const char &c : S) {
            Map[y][x] =  GateOnlyMap[y][x] = 0;
            //
            Map[y][x] = (c - '0');
            if(Map[y][x] == 0) {
                startX = x, startY = y;
            }
            if(Map[y][x] == 1) {
                Map[y][x] = 0;
            }
            if(Map[y][x] == WALL) {
                Map[y][x] = WALL;
            }
            if(Map[y][x] == KEY) {
                KeyCount++;
                //KeyOnlyMap[y][x]     = KeyCount;
            }
            if(Map[y][x] == GATE) {
                GateCount++;
                GateOnlyMap[y][x]    = GateCount;
            }
            // -- Increment
            x++;
        }
        // -- Increment
        y++;
    }
    M = KeyCount;
}

int KeyID = 0;

void key_BFS(int Y, int X, int t, vector< pair<int, pair<int, int>> > &A) {
    KeyID++;
    int GateID = 0;
    //
    vector< vector<int> > Visited(H+2, vector<int>(W+2, 0) );
    //
    queue< pair< pair<int, int>, int> > Q;
    Q.push( {{Y, X}, t} );
    // --
    while( !Q.empty() ) {
        int Y = Q.front().first.first;
        int X = Q.front().first.second;
        int t = Q.front().second;
        Q.pop();
        //
        if(Visited[Y][X]) continue;
        Visited[Y][X] = 1;

        if(Map[Y][X] == GATE) {
            GateID++;
            A.push_back( {t, {KeyID, GateOnlyMap[Y][X]}} );
        }
        //
        for(const auto &Pd : d) {
            if( (!Visited[Y + Pd.first][X + Pd.second]) && (Map[Y + Pd.first][X + Pd.second] != WALL) ) {
                Q.push( {{Y + Pd.first, X + Pd.second }, t + 1} );
            }
        }
    }
}

void debug() {
    cout << "\nWall = " << WALL << ", Key = " << KEY << ", Gate = " << GATE << endl;
    for(auto v : Map) {
        for(auto i : v) {
           cout << i << ' ';
        }
       cout << endl;
    }
}

bool maximal_matching_exist(vector< pair<int, pair<int, int>> >::iterator L, vector< pair<int, pair<int, int>> >::iterator R) {
    // -- Check if all keys and gates have been reached in chosen timemark yet
    //  Construct bipartite graph in the meanwhile..
    vector<vector<int>> edgeList ( M+1, vector<int>() );
    //
    unordered_set<int> ALLKEY, ALLGATE;
    for(int i = 1; i <= M; i++) {
        ALLKEY.insert(i);
        ALLGATE.insert(i);
    }
    for(auto it = L; it != R; it++) {
        int keyID   = (it->second).first;
        int gateID  = (it->second).second;
        ALLKEY.erase(   keyID );
        ALLGATE.erase(  gateID );
        // -- append to List;
        if(edgeList[keyID].size() == 0) edgeList[keyID].push_back(-1);
        edgeList[keyID].push_back(gateID);
    }
    if( !!ALLKEY.size() || !!ALLGATE.size() ) return 0;
    // -- Actual DFS to check if matching exists.. O(V * E)
    //   
    vector<int> Key_assign  (M+1, -1);
    vector<int> Gate_assign (M+1, -1);
    // --
    vector<int> Visited (M+1, 0);
    function< bool (int, vector<int>) > reroute = 
        [=, &Gate_assign, &Key_assign, &edgeList](int K, vector<int> Visited) -> bool {

            for(int idx = Key_assign[K]; idx < edges[K].size(); idx++) {
                const int &g = edgeList[idx];
                
                if( not Visited[g] ) {
                    if( Gate_assign[g] == -1) {
                        Gate_assign[g]  = K;
                        Key_assign[K]   = idx;
                        return 1;
                    } else {
                        Visisted[ g ] = true;
                        if( reroute( Gate_assign[g], Visited ) ) {
                            Gate_assign[g]  = K;
                            Key_assign[K]   = idx;
                            return 1;
                        }
                        Visisted[ g ] = false;
                    }
                } 
            }

            return 0;
        };
    //
    for(int k = 1; k <= M; k++) {
        if(Key_assign[k] == -1) {
            Key_assign[k] = 1;
            for(;Key_assign[k] < edgeList[k].size(); Key_assign[k]++) {
                int g = edgeList[k][ Key_assign[k] ];
                if( Gate_assign[g] == -1) {
                    Gate_assign[g] = k;
                    break;
                } else {
                    Visited[g] = 1;
                    if( reroute(Gate_assign[g], Visited) ) {
                        Gate_assign[g] = k;
                    } else return 0;
                    Visited[g] = 0;
                }
            }
        }
    }
}

int treasurePath(vector<string> islandMap) {
    conventional_map(islandMap);
    //debug();
    //
    vector< vector<int> > Visited(H+2, vector<int>(W+2, 0) );
    //
    queue< pair< pair<int, int>, int > >    Q;
    vector< pair< pair<int,int>, int > >    Keys;
    // -- BFS to find Keys
    Q.push( {{startY, startX}, 0} );
    while( !Q.empty() ) {
        //
        int Y = Q.front().first.first;
        int X = Q.front().first.second;
        int t = Q.front().second;
        Q.pop();
        //
        if(Visited[Y][X]) continue;
        Visited[Y][X] = 1;

        if(Map[Y][X] == KEY) Keys.push_back( {{Y, X}, t} );
        // --
        for(const auto &Pd : d) {
            if( (!Visited[Y + Pd.first][X + Pd.second]) && (Map[Y + Pd.first][X + Pd.second] != WALL) ) {
                Q.push( {{ Y + Pd.first, X + Pd.second }, t + 1} );
            }
        }
    }
    // -- Found all keys.
    vector< pair<int, pair<int, int>> > Arrival;
    for( pair<pair<int, int>, int> &Pp : Keys ) {
        key_BFS( Pp.first.first, Pp.first.second, Pp.second, Arrival);
    }
    // -- 
    if( Arrival.size() != M*M ) return -1;
    else {
        sort(Arrival.begin(), Arrival.end());
        // -- maximal bipartite matching check:
        for(auto it = Arrival.begin(); it != Arrival.end(); it++) 
            if( maximal_matching_exist(Arrival.begin(), next(it)) )
                return it->first;
        // -- Not found.
        return -1;
    }
}

int main() {
    vector<string> M = {"034","342","341"};
    cout << "Answer = " << treasurePath(M);
    //cout << endl << GotKeyAt[1] << " " << GotKeyAt[2];
}

/*
cout << "\nTime: ";
for( auto &P : Arrival ) {
    int time = P.first;
    cout << time << " ";
}
cout << "\nKey: ";
for( auto &P : Arrival ) {
    int key  = P.second.first;
    cout << key << " ";
}
cout << "\nGate: ";
for( auto &P : Arrival ) {
    int gate = P.second.second;
    cout << gate << " ";
}

*/