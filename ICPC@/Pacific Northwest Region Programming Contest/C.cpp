#include <bits/stdc++.h>
using namespace std;

#define gcd(x,y) __gcd(x,y)

const int N = (int)(1e6) + 10;
int minPrime[N];
void sieve() {
    minPrime[0] = minPrime[1] = 0;
    for (int i=2; i<N; i++) minPrime[i] = i;
    for (int i=2; i<N; i++)
        if (minPrime[i] == i) {
            for (long long j=1LL*i*i; j<N; j += i) minPrime[j] = min(minPrime[j], i);
        }
}

long long mult(long long a, long long b, long long mod) {
    //return (__int128)a * b % mod;
    a %= mod;
    long long res = 0;
    while (b) {
        if (b & 1) res = (res +a) % mod;
        a = (a+a)%mod;
        b >>= 1;
    }
    return res;
}

long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

long long brent(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long g = 1;
    long long q = 1;
    long long xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}

void small_factorize(vector<long long>& fcs, long long k) {
    while (k > 1) {
        int mp = minPrime[k];
        fcs.push_back(mp);
        int cnt=0;
        while (mp == minPrime[k]) {
            cnt++;
            k /= mp;
        }
        fcs.push_back(cnt);
    }
}

void factorize(long long k, vector<long long>& factors) {
    if (k <= 1) return;
    queue<long long> q;
    q.push(k);
    while (not q.empty()) {
        auto fr = q.front(); q.pop();
        auto a = brent(fr);
        auto b = fr/a;
        if (a > b) swap(a, b);

        if (a==1 && b >= N) {
            factors.push_back(b);
            factors.push_back(1);
            continue;
        }

        //
        if (a < N) small_factorize(factors, a);
        else q.push(a);
        if (b < N) small_factorize(factors, b);
        else q.push(b);
    }
}

long long bin_expo(long long b, long long e) {
    long long res=1;
    while (e) {
        if (e&1) res *= b;
        b = b * b;
        e >>= 1;
    }
    return res;
}
long long sum_geometric_seq(long long b, long long n) {
    return (bin_expo(b, n+1) - 1)/(b-1);
}

long long calc(vector<long long>& f) {
    long long res=1;
    for (int i=0; i<(int)(f.size()); i+=2) {
        long long p=f[i];
        long long cnt=f[i+1];
        res = res * sum_geometric_seq(p, cnt);
    }
    return res;
}

long long a, b;
int main() {
    sieve();

    cin >> a >> b;
    long long sum=0;
    vector<long long> fac;
    while (a <= b) {
        fac.clear();
        factorize(a, fac);

        cerr << a << endl;
        for (auto ll : fac) cerr << ll << ' ';
        cerr << endl;

        sum += calc(fac);
        a++;
    }
    cout << sum << endl;
}