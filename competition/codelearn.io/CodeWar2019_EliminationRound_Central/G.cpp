#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> pieceType {
    {99, "KING"}, {1, "QUEEN"}, {2, "ROOK"}, {3, "BISHOP"}, {4, "KNIGHT"}
};

#define db 0

#define eKING   -99
#define KING    99
#define QUEEN   1
#define ROOK    2
#define BISHOP  3
#define KNIGHT  4

#define X first
#define Y second


class ChessPiece {
    public:
        int ID = -1;
        int R = -1;
        int C = -1;
        int occID = 1;
};

ostream& operator<<(ostream & o, ChessPiece * c){
    o << "Examined piece is " << pieceType[c->ID] << " is at " << c->R << ' ' << c->C << endl;
    return o;
}

vector<ChessPiece*> whitePieces;
ChessPiece* blackKing;

void debug(){
    cout << "White pieces are:\n";
    for(ChessPiece* c : whitePieces) {
        cout << pieceType[c->ID] << " at " << c->R << ' ' << c->C;
        cout << endl;
    }
    cout << "Black pieces are:\n";
    ChessPiece *c = blackKing;
    cout << pieceType[c->ID] << " at " << c->R << ' ' << c->C;
    cout << endl;
}

// --
void getPieces(vector<string> pos);
void makePossibleMove();
// --

// ============ occupied  =====================================
void markOccupied(vector< vector<int> > &occupied);
// --------------------------------------------------------------------
vector< pair<int, int> > possibleMove(ChessPiece *c, vector< vector<int> > occupied);

// ============ checker function =====================================
bool inBoard(int x, int y) {
    return (1 <= x && x <= 8) && (1 <= y && y <= 8);
}
bool valid(int x, int y, int occid, vector< vector<int> > &occupied){
    return inBoard(x, y) && occupied[x][y] != occid;
}
// --------------------------------------------------------------------

// ======================== MAIN FUNCTION ========================
vector< vector<int> > occupiedAfterMove(vector< vector<int> > occupied, int occid, int fromX, int fromY, int toX, int toY ){
    occupied[fromX][fromY]  = 0;
    occupied[toX][toY]      = occid;
    return occupied;
}

bool play(int turn, vector< vector<int> > occupied){
    //cout << "@ " << turn << endl;
    if(turn == 0){
        for(ChessPiece *Piece : whitePieces) {
            vector< pair<int, int> > nextMoves = possibleMove(Piece, occupied);
            //--
            if(db) cout << Piece;
            int RR = Piece->R, CC = Piece->C;
            //
            for(auto &p : nextMoves) {
                int nR = p.X, nC = p.Y;
                Piece->R = nR; Piece->C = nC;
            
                if(db) {
                    cout << "Moving piece to ";
                    cout << nR << ' ' << nC << endl;
                }

                auto nextOcc = occupiedAfterMove(occupied, 1, RR, CC, nR, nC);
                if( play(turn + 1, nextOcc) ) return 1;
            }
            //
            Piece->R = RR; Piece->C = CC;
            //--
        }
        return 0;
    }
    if(turn == 1){
        vector< pair<int, int> > V = possibleMove(blackKing, occupied);
        set< pair<int, int> > kingPlace;
        for(auto p : V) kingPlace.insert(p);
        kingPlace.insert({blackKing->R, blackKing->C});
        // --
                // if(db){
                //     cout << "The black King legal move:\n";
                //     for(auto p : kingPlace) {
                //         cout << "> " << p.X << ' ' << p.Y << endl;
                //     }
                // }

        for(ChessPiece *Piece : whitePieces) {
            vector< pair<int, int> > nextMoves = possibleMove(Piece, occupied);
            for(auto p : nextMoves) kingPlace.erase(p);
        }
        //
                if(db){
                    cout << "The black King can stil move:\n";
                    for(auto p : kingPlace) {
                        cout << "> " << p.X << ' ' << p.Y << endl;
                    }
                }
        // -- Check if blackKing can run
        if (kingPlace.size() == 0) return 1;
        else {
            int RR = blackKing->R, CC = blackKing->C;
            // --
            for(auto p : kingPlace) {
                int nR = p.X, nC = p.Y;
                //
                blackKing->R = nR;
                blackKing->C = nC;
                auto nextOcc = occupiedAfterMove(occupied, -1, RR, CC, nR, nC);
                if( play(turn+1, nextOcc) == 0 ) {
                    blackKing->R = RR; blackKing->C = CC;        
                    return 0;
                }
                //
            }
            // --
            blackKing->R = RR; blackKing->C = CC;
            return 1;
        }
    }
    if (turn == 2) {
        for(ChessPiece *Piece : whitePieces) {
            int RR = Piece->R, CC = Piece->C;
            if(occupied[RR][CC] == 1) {
                vector< pair<int, int> > nextMoves = possibleMove(Piece, occupied);
                for(auto &p : nextMoves) {
                    if( p.X == blackKing->R && p.Y == blackKing->C ) return 1;
                }
            }
        }
        return 0;
    }
    assert(0);
}

bool isOneMoveCheckMate(vector<string> pos){
    vector< vector<int> > occupied (9, vector<int>(9, 0)); 
    getPieces(pos);
    markOccupied(occupied);
    // debug();
    // vector< pair<int, int> > P = possibleMove(whitePieces[3]);
    // for(auto p : P) {
    //     cout << p.X << ' ' << p.Y << endl;
    // }
    return play(0, occupied);
}
// ======================== MAIN FUNCTION ========================
void markOccupied(vector< vector<int> > &occupied){
    for(ChessPiece * c : whitePieces) {
        int Row = c->R, Col = c->C;
        occupied[Row][Col] = 1;
    }
    int Row = blackKing->R, Col = blackKing->C;
    occupied[Row][Col] = -1;
}

void getPieces(vector<string> pos) {
    for(string &s : pos){    
        //cout << "processing " << s << endl; 
        ChessPiece *tmp = new ChessPiece;

        if (s[0]=='K') {
            tmp->ID = KING;
            tmp->C = s[1] - 'a' + 1;
            tmp->R = s[2] - '0';
            tmp->occID = -1;
            blackKing = tmp;
            continue;
        }

        if (s[0]=='q') tmp->ID = QUEEN;
        if (s[0]=='r') tmp->ID = ROOK;
        if (s[0]=='b') tmp->ID = BISHOP;
        if (s[0]=='n') tmp->ID = KNIGHT;
        if (s[0]=='k') tmp->ID = KING;

        tmp->C = s[1] - 'a' + 1;
        tmp->R = s[2] - '0';

        whitePieces.push_back(tmp);
    }
}

vector< pair<int, int> > possibleMove(ChessPiece *c, vector<vector<int>> occupied) {
    int occid = c->occID;
    //
    vector< pair<int, int> > nextMoves;
    int Row = c->R, Col = c->C;
    if(c->ID == KING) {
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) 
                if( !((i == 0) && (j == 0)) )
                    if(valid(Row+i, Col+j, occid, occupied)) nextMoves.push_back({Row+i, Col+j});
    }
    if(c->ID == KNIGHT) {
        for(int i = -2; i <= 2; i++)
            if(i != 0)
                for(int j = -2; j <= 2; j++)
                    if(j != 0 && abs(j) != abs(i))
                        if(valid(Row+i, Col+j, occid, occupied)) nextMoves.push_back({Row+i, Col+j});
    }
    if(c->ID == BISHOP || c->ID == QUEEN) {
        for(int r = Row+1, c = Col+1;; r++, c++)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
        for(int r = Row+1, c = Col-1;; r++, c--)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
        for(int r = Row-1, c = Col-1;; r--, c--)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
        for(int r = Row-1, c = Col+1;; r--, c++)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
    }
    if(c->ID == ROOK || c->ID == QUEEN) {
        for(int r = Row+1, c = Col;; r++)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
        for(int c = Col+1, r = Row;; c++)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
        for(int r = Row-1, c = Col;; r--)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
        for(int c = Col-1, r = Row;; c--)
            if(valid(r, c, occid, occupied)) nextMoves.push_back({r, c});
            else break;
    }
    return nextMoves;
}

int main(){
    vector<string> P = {"qa6","Kb8","kd1"};
    cout << (isOneMoveCheckMate(P) ? "true" : "false");
}