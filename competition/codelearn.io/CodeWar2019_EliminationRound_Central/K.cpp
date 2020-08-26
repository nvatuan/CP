#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

pair<string, string> flipDate(string S) {
    string time = S.substr(0, 4);
    string date = S.substr(5, 2);
    string month = S.substr(7, 2);
    string year = S.substr(9);
    return { year + month + date, time };
}

int standardDate(string S) {
    string time1 = S.substr(0, 4);
    int date1 = stoi(S.substr(5, 2));
    int month1 = stoi(S.substr(7, 2));
    int year1 = stoi(S.substr(9));

    if(time1 != "0000") return 0;
    if(date1 == "01") date1
}

#define date first
#define time second

class task {
    public:
        int start;
        int finish;
        long long value;  
        task(int s, int t, long long v) {
            this->start     = s;
            this->finish    = t;
            this->value     = v;
        }
};

int minute(string hourMinute) {
    function< int(char) > num = [&](char c)->int{
        return c - '0';
    };
    return (num(hourMinute[0])*10 + num(hourMinute[1]))*60 + ((num(hourMinute[2])*10 + num(hourMinute[3])));
}

vector<task> TASKS;

void convert(auto taskList) {
    set<string> allDatePossible;
    for(auto &sss : taskList) {
        pair<string, string> T1, T2;
        T1 = flipDate(sss[0]);
        T2 = flipDate(sss[1]);

        //if(T1.time == "0000") T1.time = "2400";
        if(T2.time == "0000") T2.time = "2400";

        if(T1.date != T2.date) continue;
        if( not (
                (("0800" <= T1.time && T1.time <= "1200") and ("0800" <= T2.time && T2.time <= "1200"))
                    or
                (("1300" <= T1.time && T1.time < "2359") and ("1300" <= T2.time && T2.time <= "2400"))
         )      ) continue;
        //cout << T1.time << " " << T2.time << endl;
        // --
        allDatePossible.insert(T1.date);
    }
    // --
    int d = 0;
    //if(allDatePossible.size() == 0) return;
    for(string S : allDatePossible) {
        for(auto &sss : taskList) {
            pair<string, string> T1, T2;

            T1 = flipDate(sss[0]);
            T2 = flipDate(sss[1]);

            if(T1.date == S && T2.date == S) {
                auto t1 = T1;

                //if(T1.time == "0000") T1.time = "2400";
                if(T2.time == "0000") T2.time = "2400";
                auto t2 = T2;

                if( not (
                    (("0800" <= T1.time && T1.time <= "1200") and ("0800" <= T2.time && T2.time <= "1200"))
                        or
                    (("1300" <= T1.time && T1.time < "2359") and ("1300" <= T2.time && T2.time <= "2400"))
                )      ) continue;
                
                TASKS.push_back( task( d * 1440 + minute(t1.time), d * 1440 + minute(t2.time), stoll(sss[2]) ) );
            }
        }
        d++;
    }
}

int maximumEarning(vector<vector<string>> taskList) {
    convert(taskList);
    sort(TASKS.begin(), TASKS.end(), [&](task a, task b)->bool{ a.finish <= b.finish; } );
    // --
    for(task &t : TASKS) {
        t.value = int( (t.finish - t.start)*1.0 / 60 * t.value );
        cout << t.start << " -> " << t.finish << " = " << t.value << endl;
    }
    // --
    vector<long long> accProfit (TASKS.size(), 0);
    int i = 0;
    for(auto t : TASKS) {
        accProfit[i] = t.value;
        i++;
    }
    //
    for(int i = 1; i < TASKS.size(); i++) {
        for(int j = i-1; j >= 0; j--) {
            if( TASKS[j].finish <= TASKS[i].start ) {
                accProfit[i] = max(
                    accProfit[i], accProfit[j] + TASKS[i].value
                );
            } 
        }
    }
    //if(accProfit.size() == 0) return 0;
    return *max_element(accProfit.begin(), accProfit.end());
}


int main() {
    vector<vector<string>> vvs = {{"2300 24092018", "0000 24092018", "15"},  {"0800 25092018", "0900 25092018", "15"}, {"0800 26092018", "0900 26092018", "15"}};
    cout << "Max earn: " << maximumEarning(vvs);
}
