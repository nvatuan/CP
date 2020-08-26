#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> housesList(std::vector<std::string> houseColors, std::vector<std::string> houseConditions)
{
    // cerr << "Start of program\n"; // Debug
    vector< tuple<string, string, string, int> > conditions;
    // --------------------------------------------------------------------------
    // cerr << "Lambdas initializing\n"; // Debug
    vector< std::function<bool(int, int)> > lambdas;
    lambdas.push_back( [&](int condi, int x) -> bool { 
        if( x + 1 >= int(houseColors.size()) ) return 0;
        if( houseColors[x+1] == std::get<1>(conditions[condi]) ) return 1;
        return 0;
    } );
    lambdas.push_back( [&](int condi, int x) -> bool { 
        while( x <= int(houseColors.size() - 1) ) {
            if( houseColors[x+1] == std::get<1>(conditions[condi]) ) return 1;
        }
        return 0;
    } );
    lambdas.push_back( [&](int condi, int x) -> bool { 
        int x1 = x+1, x2 = x+2;
        while(x2 < int(houseColors.size())) {
            if( (houseColors[x1] == std::get<1>(conditions[condi])) && (houseColors[x2] == std::get<2>(conditions[condi])) ) return 1;
            x1 += 1;
            x2 += 2;
        }
        return 0;
    } );
    // --------------------------------------------------------------------------
    // cerr << "Standardization of tasks\n"; // Debug
    for(string &s : houseConditions) {
        stringstream ss (s); string word; vector<string> vs;
        while(ss >> word) vs.push_back(word);
        // unsigned status;
        // status = s.find(" is next to the right of ");
        if( vs[2] == "next" && vs[5] == "right" ) {
            string house1 = vs[0]; //s.substr(0, status);
            string house2 = vs[7] ;//s.substr(status + 25, string::npos);
            //
            conditions.push_back( make_tuple(house2, house1, "", 0) );
            continue;
        }
        //
        // status = s.find(" is next to the left of ");
        if( vs[2] == "next" && vs[5] == "left" ) {
            string house1 = vs[0]; //s.substr(0, status);
            string house2 = vs[7]; //s.substr(status + 24, string::npos);
            //
            conditions.push_back( make_tuple(house1, house2, "", 0) );
            continue;
        }
        //
        // status = s.find(" is on the right of ");
        if( vs[2] == "on" && vs[4] == "right" ) {
            string house1 = vs[0]; //s.substr(0, status);
            string house2 = vs[6]; //s.substr(status + 20, string::npos);
            //
            conditions.push_back( make_tuple(house2, house1, "", 1) );
            continue;
        }
        //
        // status = s.find(" is is on the left of ");
        if( vs[2] == "on" && vs[4] == "left" ) {
            string house1 = vs[0]; //s.substr(0, status);
            string house2 = vs[6]; //s.substr(status + 19, string::npos);
            //
            conditions.push_back( make_tuple(house1, house2, "", 1) );
            continue;
        }
        //
        // status = s.find(" is in the middle of ");
        if( vs[4] == "middle" ) {
            string house1 = vs[6];
            string house2 = vs[0];
            string house3 = vs[8];
            //
            conditions.push_back( make_tuple(house1, house2, house3, 2) );
            continue;
        }
        //
        // status = s.find(" is in beetween of ");
        if( vs[3] == "beetween" ) {
            string house1 = vs[5];
            string house2 = vs[0];
            string house3 = vs[7];
            //
            conditions.push_back( make_tuple(house2, house1, "", 1) );
            conditions.push_back( make_tuple(house3, house2, "", 1) );
        }
        //
    }
    // --------------------------------------------------------------------------
    // cerr << "Sorting..\n"; // Debug
    sort( houseColors.begin(), houseColors.end() );
    sort( conditions.begin(), conditions.end() );

    // cerr << "Going through each permutation..\n"; // Debug
    do {
        unordered_map<string, int> ID;
        int i = 0;
        for(auto &s : houseColors) ID[s] = i++;
        //
        int condi = 0;
        for(auto &t : conditions) {
            if( (lambdas[std::get<3>(t)]( condi, ID[std::get<0>(t)] )) == false ) break;
            //
            condi++;
        }
        if(condi == int(conditions.size()) ) return houseColors;
    } while( next_permutation(houseColors.begin(), houseColors.end()) );
    // -- sol not found.
    return std::vector<std::string>();
}

int main(){ 
    vector< string > s1 = {"blue is next to the right of red", "green is next to the right of blue"};
    vector< string > s2 = {"red", "blue", "green", "pink", "yellow", "black", "orange", "gray", "white"};
    vector< string > L = housesList(s2, s1);
    for(auto &s : L) cout << s << ' ';
}