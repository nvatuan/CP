#include <bits/stdc++.h>
using namespace std;

// -- Direction (D, L, U, R)
const pair<int, int> d[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

// -- Global countings
int GotKeyAt[51];
int GotGateAt[51];
int KeyCount    =  0;
int KeyTotal;
int GateCount   =  0;
int KeyPairGate[51];

int tick = 0;

// -- Map and location related
int startX, startY;
int H, W;
vector<vector<int>> Map, KeyOnlyMap, GateOnlyMap;

#define WALL    2
#define KEY     3
#define GATE    4

void conventional_map(vector<string> islandMap) {
    H = islandMap.size();
    W = islandMap[0].size();
    Map = vector< vector<int> > (H + 2, vector<int>(W + 2, WALL));
    KeyOnlyMap = GateOnlyMap = Map;
    // --
    int y = 1, x = 1;
    for(const string &S : islandMap) {
        x = 1;
        for(const char &c : S) {
            Map[y][x] = KeyOnlyMap[y][x] = GateOnlyMap[y][x] = 0;
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
                KeyOnlyMap[y][x]     = KeyCount;
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
}

// Wave class, with spreading behaviour
class Wave {
    public:
    // -- Variable member:
        int carryKey           =    0;
        vector< vector<int> >       Visited;
        vector< pair<int, int> >    positions;
        vector< pair<int, int> >    nextPositions;
    // -- Function member:
        Wave(int Y, int X, int isKey = 1) {
            (this->Visited)     = vector< vector<int> > (H + 2, vector<int>(W + 2, 0) );
            (this->nextPositions).push_back( {Y, X} );
            (this->carryKey)    = isKey;
            ////cout << "\n\tCreated Process.\n";
        }
        //
        int nextTick(vector<Wave*> &newProcess) {
            int affect = 0;
            if(nextPositions.size() == 0) return affect;
            // --
            this->positions = this->nextPositions;
            this->nextPositions.resize(0); //this->nextPositions.clear();
            // --
            for(const pair<int, int> &P : this->positions) {
                if( this->Visited[P.first][P.second] ) continue;
                this->Visited[P.first][P.second] = 1;
                // ====== Check if hit Stations ================================
                if(this->carryKey) {    // This wave is carrying a Key
                    // P.first, P.second
                    if(Map[P.first][P.second] == GATE) {
                        if( !GotGateAt[ GateOnlyMap[P.first][P.second] ] ) {
                            GotGateAt[ GateOnlyMap[P.first][P.second] ] = tick;
                            GateCount--;
                        }
                        if(!KeyPairGate[this->carryKey]) {
                            KeyPairGate[this->carryKey] = 1;
                        }
                    }
                } else {                // This wave is the Original Wave
                    if(Map[P.first][P.second] == KEY) {
                        if( !GotKeyAt[ KeyOnlyMap[P.first][P.second] ] ) {  // been reached before.
                            GotKeyAt[ KeyOnlyMap[P.first][P.second] ] = tick;
                            KeyCount--;
                            //
                            newProcess.push_back( new Wave(P.first, P.second, KeyOnlyMap[P.first][P.second]) );
                        }
                    }
                }
                // ======== Next wave positions ================================
                for(const pair<int, int> &Pd : d)
                    if( Map[P.first + Pd.first][P.second + Pd.second] != WALL ) {
                        if( !this->Visited[P.first + Pd.first][P.second + Pd.second] ) {
                            affect = 1;
                            this->nextPositions.push_back( {P.first + Pd.first, P.second + Pd.second} );
                        }
                    }
                // --
            }
            // --
            return affect;
        }
        //
        // ~Wave(){
        //     this->Visited.clear();
        //     this->positions.clear();
        //     this->nextPositions.clear();
        // }
};

int treasurePath(vector<string> islandMap) {
    conventional_map(islandMap);
    KeyTotal = KeyCount;
    // -- ALL MAPs ARE 1-INDEXED

    tick = 0;
    vector<Wave*> process, newProcess;
    newProcess.push_back( new Wave(startY, startX, 0) );

    do {
        process = newProcess;
        if( !process.size() ) {
            tick = (H+W)*2;
            break;
        }
        newProcess.resize(0); //newProcess.clear();
        // --
        for(Wave* &wave : process) {
            if(wave->nextTick(newProcess)) {
                newProcess.push_back(wave);
            }
        }
        // --
        if( !KeyCount and !GateCount) {
            bool logic = 1;
            for(int i = 1; i <= KeyTotal; i++) {
                logic &= KeyPairGate[i];
            }
            if(logic) break;
        }
        // --
        tick++;
    } while( tick < (H+W)*2 );
    if(tick == (H+W)*2) return -1;
    else return tick-1;
}

int main() {
    //vector<string> M = {"01111322224", "11111112221", "11111111111", "34222222211"};
    vector<string> M = {"0111134","1113142","1111112","1114132"};
    cout << "Answer = " << treasurePath(M);
    //cout << endl << GotKeyAt[1] << " " << GotKeyAt[2];
    
}