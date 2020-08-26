#include <bits/stdc++.h>
using namespace std;

const int MAXN = int(1e6 + 1);
vector<int> prime (MAXN + 1, 1);

void sieve() {
    prime[0] = prime[1] = 0;
    for(long long i = 2; i <= MAXN; i++) 
        if(prime[i])
            for(long long j = i*i; j <= MAXN; j+=i)
                prime[j] = 0;
}

long long mergeSort(vector<int>::iterator L, vector<int>::iterator Rend) {
   
    // -- conform to [L, Rend) rule
    int size = (Rend - L);
    if(size <= 1) return 0;
    vector<int>::iterator Lend = L + (size/2);
    
    // -- [L, Lend) and [R, Rend)
    auto R = Lend;
    long long inversions = mergeSort(L, Lend) + mergeSort(R, Rend);

    // -- merging..
    vector<int> temp;
    auto Lorig = L;
    //
    while(L != Lend && R != Rend)
        if( *L > *R ) {
            temp.push_back(*R);
            inversions += (Lend - L);
            R++;
        } else {
            temp.push_back(*L);
            L++;
        }
    while(L != Lend) temp.push_back(*(L++));
    while(R != Rend) temp.push_back(*(R++));

    // -- transfer
    for(auto &i : temp) (*(Lorig++)) = i;

    // --
    return inversions;
}

vector<int> A;

int main () {
    sieve();
    // --
    long long N;
    cin >> N;
    A = vector<int> (N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        if(prime[A[i]]) A[i] = 1;
        else A[i] = -1;
    }
    for(int i = 1; i <= N; i++) A[i] += A[i-1];
    // --
    long long inv = mergeSort(A.begin(), A.end()); 
    //cout << "invers = " << inv << endl;
    cout << (N * (N+1))/2 - inv;
}