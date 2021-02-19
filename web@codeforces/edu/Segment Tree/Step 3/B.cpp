#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> arr;

    void init(int n) {
        n++;
        for (size=1; size<n;size<<=1);
        arr.resize(size*2, 0);
    }
    
    void build(int& n, int x, int Lx, int Rx){
        if (Lx + 1 == Rx) {
            if (Lx <= n) arr[x] = 1;
            return;
        }
        int mid = (Lx + Rx)/2;
        build (n, x*2+1, Lx, mid);
        build (n, x*2+2, mid, Rx);
        arr[x] = arr[x*2+1] + arr[x*2+2];
    }
    void build(int n) {
        build(n, 0, 0, size);
    }
    
    int first_smaller_than(int v, int x, int Lx, int Rx){
        if (arr[x] < v) return -1;
        if (Lx + 1 == Rx) {
            return Lx;
        }
        int mid = (Lx + Rx) / 2;
        if (arr[x*2+2] > v) return first_smaller_than(v, x*2+2, mid, Rx);
        else return first_smaller_than(v - arr[x*2+2], x*2+1, Lx, mid);
    }
    int first_smaller_than(int v){
        return first_smaller_than(v, 0, 0, size);
    }

    void unset(int i, int x, int Lx, int Rx) {
        if (Lx + 1 == Rx) {arr[x] = 0; return;}
        int mid = (Lx + Rx)/2;
        if (i < mid) unset(i, x*2+1, Lx, mid);
        else unset(i, x*2+2, mid, Rx);
        arr[x] = arr[x*2+1] + arr[x*2+2];
    }
    void unset(int i) {
        unset(i, 0, 0, size);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    SegmentTree st;
    st.init(n);
    st.build(n);

    reverse(a.begin(), a.end());
    stack<int> answer;
    for (int i : a) {
        int elem = st.first_smaller_than(i);
        answer.push(elem);
        st.unset(elem);
    }

    while (! answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }
    cout << endl;
}
