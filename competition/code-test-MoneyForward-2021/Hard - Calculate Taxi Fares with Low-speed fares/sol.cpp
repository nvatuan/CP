#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

vector<string> timestamp_string, travelled_dist_string;

void read_input() {
    string ts, td;
    while (cin >> ts >> td) {
        timestamp_string.push_back(ts);
        travelled_dist_string.push_back(td);
    }
}

struct Timestamp {
    string st;
    int hh;
    int mm;
    float ss;

    Timestamp(string s) {
        st = s;
        // Extract hour as int
        int idx = s.find(':');
        hh = stoi(s.substr(0, idx));
        // Extract minute as int
        int idx2 = s.find(':', idx+1);
        mm = stoi(s.substr(idx+1, idx2));
        // Extract second as float
        ss = stof(s.substr(idx2+1));
    }

    void p() { // debug function
        cerr << "ST=" << st << endl;
        fprintf(stderr, "HH=%d; MM=%d; SS=%f\n", hh, mm, ss);
    }

    int is_night() { // check is current timestamp is night
        int new_hh = hh % 24;
        if (new_hh >= 22) return 1;
        if (new_hh < 5) return 1;
        return 0;
    }

    float diff_from (Timestamp ts) {
        int dh = hh-ts.hh;
        int dm = mm-ts.mm;
        float ds = ss-ts.ss;
        return (dh * 3600) + (dm * 60) + ds;
    }
};

// timestamp object
vector<Timestamp> timestamp;
vector<float> trav_dist;

int is_lowspeed(float speed) {
    return (speed <= (100.0/36.0));
}

llong calculate_fare(float fdist, float fls_time) {
    int dist = (int)(fdist + 0.9);
    int ls_time = (int)(fls_time);
    llong fee = 0;
    // Distance's 
    if (dist > 0) fee = 410;
    if (dist > 1052) {
        dist -= 1052;
        fee += ((dist + 236)/237 * 80);
    }
    // Lowspeed's
    fee += (ls_time / 90) * 80;
    return fee;
}

int main(int argc, char *argv[]) {
    read_input();
    for (string st : timestamp_string) {
        timestamp.push_back(Timestamp(st));
    }
    for (string st : travelled_dist_string) {
        trav_dist.push_back(stof(st));
    }

    float total_lowspeed_time = 0.0; // in seconds;
    float total_travel_dist = 0.0; // in kilometers

    assert (timestamp.size() == trav_dist.size());
    assert (timestamp.size() > 0);

    int n = (int) timestamp.size();

    // db;
    for (int i=0; i<n; i++) {
        cerr << "Timestamp #" << i << ": ";
        timestamp[i].p();
        cerr << endl;
        cerr << "Distance #" << i << ": " << trav_dist[i] << endl;
    }
    
    for (int i=1; i<n; i++) {
        float dt_s = timestamp[i].diff_from(timestamp[i-1]); // in seconds
        float dd = trav_dist[i]; // in meters
        cerr << "Diff#" << i << ": " << dt_s << endl;
        cerr << "Dist#" << i << ": " << dd << endl;

        // both timestamps are night
        int nighthours = (timestamp[i].is_night() && timestamp[i-1].is_night());

        float sp = dd / dt_s; // speed in m/s
        if (is_lowspeed(sp)) { // dt_s is lowspeed duration
            if (nighthours) total_lowspeed_time += (dt_s*1.25);
            else total_lowspeed_time += dt_s;
        }
        if (nighthours) total_travel_dist += (dd * 1.25);
        else total_travel_dist += dd;
    }

    cerr << total_travel_dist << ' ' << total_lowspeed_time << endl;
    cout << calculate_fare(total_travel_dist, total_lowspeed_time) << endl;
    return 0;
}
