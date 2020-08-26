#include <bits/stdc++.h>
using namespace std;
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
    int y = 1, x = 1;
    for(const string &S : islandMap) {
        x = 1;
        for(const char &c : S) {
            Map[y][x] =  GateOnlyMap[y][x] = 0;
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
            x++;
        }
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

bool reroute(int K, vector<int> Visited, vector<int> &Gate_assign, vector<int> &Key_assign, const vector<vector<int>> &edgeList, int depth = 0) {
    for(int idx = 1; idx < edgeList[K].size(); idx++) {
        const int &g = edgeList[K][idx];
        
        if( not Visited[g] ) {
            if( Gate_assign[g] == -1) {
                Gate_assign[g]  = K;
                Key_assign[K]   = idx;
                return 1;
            } else {
                Visited[ g ] = true;

                if( reroute( Gate_assign[g], Visited, Gate_assign, Key_assign, edgeList, depth + 1 ) ) {
                    Gate_assign[g]  = K;
                    Key_assign[K]   = idx;
                    Visited[ g ] = false;

                    return 1;
                }
                Visited[ g ] = false;
            }
        } 
    }

    return 0;
}

bool maximal_matching_exist(vector< pair<int, pair<int, int>> >::iterator L, vector< pair<int, pair<int, int>> >::iterator R) {
    vector<vector<int>> edgeList ( M+1, vector<int>() );
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
        if(edgeList[keyID].size() == 0) edgeList[keyID].push_back(-1);
        edgeList[keyID].push_back(gateID);
    }
    if( !!ALLKEY.size() || !!ALLGATE.size() ) return 0;
    vector<int> Key_assign  (M+1, -1);
    vector<int> Gate_assign (M+1, -1);
    vector<int> Visited (M+1, 0);

    for(int k = 1; k <= M; k++) {
        if(Key_assign[k] == -1) {
            int rerouted = 0;

            for(Key_assign[k] = 1; Key_assign[k] < edgeList[k].size(); Key_assign[k]++) {

                int g = edgeList[k][ Key_assign[k] ];
                if( Gate_assign[g] == -1) {
                    Gate_assign[g] = k;
                    rerouted = 1;
                    break;
                } else {
                    Visited[g] = 1;
                    if( reroute(Gate_assign[g], Visited, Gate_assign, Key_assign, edgeList) ) {
                        Gate_assign[g] = k;
                        rerouted = 1;
                        Visited[g] = 0;
                        break;
                    }
                    Visited[g] = 0;
                }

            }

            if( not rerouted ) return 0;
        }
    }
    return 1;
}

int treasurePath(vector<string> islandMap) {
    conventional_map(islandMap);
    vector< vector<int> > Visited(H+2, vector<int>(W+2, 0) );
    queue< pair< pair<int, int>, int > >    Q;
    vector< pair< pair<int,int>, int > >    Keys;
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
    vector< pair<int, pair<int, int>> > Arrival;
    for( pair<pair<int, int>, int> &Pp : Keys ) {
        key_BFS( Pp.first.first, Pp.first.second, Pp.second, Arrival);
    }
    if( Arrival.size() != M*M ) return -1;
    else {
        sort(Arrival.begin(), Arrival.end());

        auto L = Arrival.begin();
        auto R = Arrival.end();

        do {
            auto mid = L + (R - L)/2;
            //--
            int exitcode = maximal_matching_exist( Arrival.begin() , next(mid) );
            if( exitcode ) {
                R = mid;
            } else {
                L = mid + 1;
            }
            //--
        } while (L < R);

        if( maximal_matching_exist( Arrival.begin() , next(R) ) ) return R->first;
        return -1;
    }
}

int main() {
    vector<string> M = {    
                            "4111111111",
                            "3111131111",
                            "1111101111",
                            "4113131111",
                            "1114141111"
                        };
    cerr << "Answer = " << treasurePath(M);
    // cerr << endl << GotKeyAt[1] << " " << GotKeyAt[2];
}

/*
// cerr << "\nTime: ";
for( auto &P : Arrival ) {
    int time = P.first;
   //  // cerr << time << " ";
}
// cerr << "\nKey: ";
for( auto &P : Arrival ) {
    int key  = P.second.first;
   //  // cerr << key << " ";
}
// cerr << "\nGate: ";
for( auto &P : Arrival ) {
    int gate = P.second.second;
   //  // cerr << gate << " ";
}

*/