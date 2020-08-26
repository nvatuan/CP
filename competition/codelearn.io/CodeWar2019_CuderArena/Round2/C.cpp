#include <bits/stdc++.h>
using namespace std;

long long intTime(std::string A) {
    //vector<int> dayInMonth  = {0,   31,    28,  31,   30,     31,     30,     31,     31,     30,     31,     30,     31};
    vector<int> sumDay      = {31,    59,  90,   120,    151,    181,    212,    243,    273,    304,    334,    365};
    // cout << "String that was passed to intTime: " << A << endl;
    //--
    long long yA = (int(A[0]-'0')*10 + int(A[1]-'0') - 17);
    long long mA = (int(A[2]-'0')*10 + int(A[3]-'0') - 01);
    long long dA = (int(A[4]-'0')*10 + int(A[5]-'0') - 01);
    long long hA = (int(A[6]-'0')*10 + int(A[7]-'0'));
    long long miA = (int(A[8]-'0')*10 + int(A[9]-'0'));
    long long sA = (int(A[10]-'0')*10 + int(A[11]-'0'));
    long long atA = sA + miA*60 + hA*3600 + dA*86400 + sumDay[mA]*86400 + yA*365*86400;
    //
    // cout << "Converted to " << atA << endl;
    // cout << "===================\n";
    //
    return atA;
}

std::vector<std::string> attackList(std::vector<std::string> accessList, long long m, long long n)
{
    // cout << "Start\n";
    m *= 60;    //to sec
    //--
    int userCount = 0;
    map<std::string, int> ID;
    //
    vector< std::string > userList;
    vector< vector<long long> > accessLog;
    userList.push_back("");
    accessLog.push_back( vector<long long>() );
    //--
    // cout << "Indexing..\n";
    for(std::string st : accessList) {
        std::stringstream ss(st);
        std::string Time, User;
        ss >> Time >> User;
        // cout << Time << ' ' << User << endl;
        //
        if( !ID[User] ) {
            userCount++;
            ID[User] = userCount;
            userList.push_back(User);
            accessLog.push_back( vector<long long>() );
        }
        int id = ID[User];
        // cout << "Appending " << intTime(Time) << " to user " << userList[id] <<endl;;
        accessLog[ id ].push_back( intTime(Time) );
        //
    }
    //
    // cout << "Debugging..\n";
    // for( int id = 1; id <= userCount; id++ ){
    //     cout << "User ID: " << id << " with username [" << userList[id] << "] has accessed at these time:\n";
    //     for(long long value : accessLog[id]) {
    //         cout << value << ' ';
    //     }
    //     cout << endl;
    // }

    //--
    // cout << "Building results..\n";
    vector< std::string > suspicious;
    //
    for( int id = 1; id <= userCount; id++ ){
        // cout << id << endl;
        //
        sort(accessLog[id].begin(), accessLog[id].end());
        //
        int L = 0, R = n-1;
        while( R < int(accessLog[id].size()) ) {
            // if(accessLog[id].size() == 2) cout << "User " << userList[id] << " accessed twiced!\n";
            // cout << "\tChecking user " << userList[id] << endl;
            // cout << "Different between 2 time:" << L << ' ' << R << " is " << accessLog[id][R] << " & " << accessLog[id][L] << endl;
            if( (L == R) || (accessLog[id][R] - accessLog[id][L] <= m)  ) {
                suspicious.push_back( userList[id] );
                //cout << userList[id] << endl;
                break;
            }
            L++;
            R++;
        }
    }
    //
    // cout << "Sorting..\n";
    sort(suspicious.begin(), suspicious.end());
    return suspicious;
}

int main(){
    // cout << "190920175601" << " == " << intTime("190920175601") << endl;
    // cout << "190920175501" << " == " << intTime("190920175501") << endl;
    // return 0;
    // //
    // std::vector< std::string > al = {"190920175601 1vietcv", "190920175501 1vietcv"};
    // std::vector< std::string > res = attackList(al, 2, 2);
    std::vector< std::string > res = attackList(al, 1440, 50);
    //
    cout << "\nOutside\n";
    for(std::string S : res) {
        cout << S << endl;
    }
}
