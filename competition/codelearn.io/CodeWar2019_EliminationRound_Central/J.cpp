#include <bits/stdc++.h>
using namespace std;

vector<vector< vector<int> >> tetromino[8] {
    {
        {      // I piece
            {   
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0},     
            },
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1},     
            }
        }
    }, {
        {  // O piece
            {   
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {1, 1, 0, 0}, 
            }
        }
    }, { 
        {  // L piece
            {   
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 0, 0}, 
            }, {  
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 1, 0},
                {1, 1, 1, 0}, 
            }, {   
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0}, 
            }, {   
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {1, 0, 0, 0}, 
            }
        }
    }, {
        {  // s piece
            {   
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 1, 0},
                {1, 1, 0, 0}, 
            }, { 
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0},              
            }
        }
    }, {
        {  // z piece
            {   
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 1, 0},  
            }, {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 0},  
            }
        }
    }, {
        {  // J piece
            {   
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0}, 
            }, {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 1, 0}, 
            }, {
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0}, 
            }, {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 1, 0}, 
            }
        }
    }, {
        {  // T piece
            {   
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0}, 
            }, {
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 0}, 
            }, {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 1, 0}, 
            }, {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0}, 
            }
        }
    }
};

int TForm[7] = {2, 1, 4, 2, 2, 4, 4};

pair<int,int> t_offset[8][4][4] = {
    {
            { { 3, 0}, { 2, 0}, { 1, 0}, { 0, 0}, 
            },      { { 0, 0}, { 0, 1}, { 0, 2}, { 0, 3},
            }, 
    },
    {
            { { 1, 0}, { 1, 1}, { 0, 0}, { 0, 1},
            }, 
    },
    {
            { { 2, 0}, { 1, 0}, { 0, 0}, { 0, 1},
            },      { { 1, 2}, { 0, 0}, { 0, 1}, { 0, 2}, 
            },      { { 2, -1}, { 2, 0}, { 1, 0}, { 0, 0}, 
            },      { { 1, 0}, { 1, 1}, { 1, 2}, { 0, 0},
            },
    },
    {
            { { 1, 1}, { 1, 2}, { 0, 0}, { 0, 1}, 
            },      { { 2, -1}, { 1, -1}, { 1, 0}, { 0, 0}, 
            },
    },
    {
            { { 1, -1}, { 1, 0}, { 0, 0}, { 0, 1},
            },      { { 2, 1}, { 1, 0}, { 1, 1}, { 0, 0}, 
            },
    },
    {
            { { 2, 1}, { 1, 1}, { 0, 0}, { 0, 1},
            },      { { 1, -2}, { 1, -1}, { 1, 0}, { 0, 0}, 
            },      { { 2, 0}, { 2, 1}, { 1, 0}, { 0, 0},
            },      { { 1, 0}, { 0, 0}, { 0, 1}, { 0, 2},
            },
    },
    {
            { { 1, -1}, { 1, 0}, { 1, 1}, { 0, 0}, 
            },      { { 2, 0}, { 1, 0}, { 1, 1}, { 0, 0}, 
            },      { { 1, 1}, { 0, 0}, { 0, 1}, { 0, 2}, 
            },      { { 2, 0}, { 1, -1}, { 1, 0}, { 0, 0}, 
            },
    }
};

const int HEIGHT = 26;
vector< vector<int> > Playzone;

int checkIfRec(const vector< vector<int> > &Playzone, const int &startingToLookH) {
    //--
    int w = Playzone.size();
    int hOne = startingToLookH;

    for(int h = startingToLookH; h < HEIGHT; h++) {
        int hashsum = 0;

        for(int w = 0; w < Playzone.size(); w++)
            hashsum += Playzone[w][h];    
        

        if( hashsum == Playzone.size()) hOne++;
        else    if( hashsum == 0 ) {
                    return hOne * w;
                } else return 0;
    }
    // -- 
    assert(0);
}

int placed(vector<vector<int>> &Playzone, const int ID, const int form, int y, int x) {
    int minoes = 4;
    //
    for(auto &p : t_offset[ID][form]){
        const int &oy = p.first;
        const int &ox = p.second;

        //cout << "Checking playzone: Y = " << y + oy << " X = " << x + ox << endl;

        if( (oy + y >= HEIGHT) or (x + ox >= Playzone.size()) ) return 0;
        if( !Playzone[ox + x][y + oy] ) {
            Playzone[ox + x][y + oy] = 1;
            minoes--;
        }
        if(minoes == 0) return 1;  
    }
    return 0;
}

int Trying(int depth, vector<int> blockNumber, int pieceID, const int N, vector< vector<int> > Playzone, int startingToLookH){
    // --
    int hashprod = 1;
    do {
        for(int w = 0; w < Playzone.size(); w++)
            hashprod *= Playzone[w][startingToLookH];
        if(hashprod) startingToLookH++;
        else break;
    } while (startingToLookH < HEIGHT);
    // --
    const int &y = startingToLookH;
    // --
    if(depth == N) return checkIfRec(Playzone, startingToLookH);
    else {
        if(depth > 0) blockNumber[pieceID]--;
        //
        int subAnswer = 0;
        // --
        for(int x = 0; x < Playzone.size(); x++) {
            if( Playzone[x][y] == 0 ) {

                for(int ID = 0; ID < 7; ID++) {
                    if(blockNumber[ID]) {
                        for(int form = 0; form < TForm[ID]; form++) {

                            vector< vector<int> >   newZone     = Playzone;
                            if( placed(newZone, ID, form, y, x) ){
                                subAnswer = max( subAnswer, Trying(depth+1, blockNumber, ID, N, newZone, startingToLookH) );
                            }
                            
                        }
                    }
                }

            }
        }
        // --
        return max( subAnswer, checkIfRec(Playzone, startingToLookH) );
    }
}

int findLargestRectangle(vector<int> blockNumber) {
    int N = 0;
    for(auto &i : blockNumber) N += i;
    //
    //HEIGHT = N*4;
    int answer = 0;
    for(int w = 2; w <= 4; w++) {
        Playzone = vector< vector<int> > ( w, vector<int> (HEIGHT, 0) );
        answer = max( Trying(0, blockNumber, -1, N, Playzone, 0), answer );
    }
    //
    return answer;
}


int main(){
    clock_t now = clock();
    vector<int> b {6,0,1,0,0,0,0};
    cerr << "\nLargest Area can make: " << findLargestRectangle(b);
    cout << "\n" << (clock() - now*1.0)/CLOCKS_PER_SEC;
    return 0;
}