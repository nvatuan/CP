#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> good;
map<string, int> cnt;

int main()
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string input; 
        getline(cin, input);

        string token[3];
        token[0] = "";
        token[1] = "";
        token[2] = "";

        int idx=0;
        for (int i=0; i<input.length(); i++) {
            if (input[i] == ' ') {
                idx++;
            } else {
                token[idx] += input[i];
            }
        }

        string H, T, M;
        H = token[0];
        T = token[1];
        M = token[2];

        string hsh = H + ',' + T + ',' + M;
        if (good.find(hsh) == good.end())
        {
            good.insert(hsh);
            cnt[M]++;
        }
    }

    for (auto p : cnt)
    {
        cout << p.first << ' ' << p.second << ' ';
        if (p.second >= 10)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
