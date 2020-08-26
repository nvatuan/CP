#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    // --
public:
    int __N;
    vector<int> __treesize;
    vector<int> __treeroot;
    // --
public:
    DisjointSet () {}
    DisjointSet (int n) {
        __N = n;
        __treesize.resize(n, 1);
        __treeroot.resize(n);
        for(int i = 0; i < n; i++) __treeroot[i] = i;
    }
    //
    int getRoot(int node) {
        while(__treeroot[node] != node) {
            __treeroot[node] = __treeroot[__treeroot[node]];
            node = __treeroot[node];
        }
        return node;
    }

    void Union(int A, int B) {
        int rA = getRoot(A);
        int rB = getRoot(B);
        //
	if( rA == rB ) return;
	//
        if(__treesize[rA] < __treesize[rB]) {
            __treeroot[rA] = rB;
            __treesize[rB] += __treesize[rA];
        } else {
            __treeroot[rB] = rA;
            __treesize[rA] += __treesize[rB];
        }
    }
    
    bool Find(int A, int B) {
        int rA = getRoot(A);
        int rB = getRoot(B);
        return (rA == rB);
    }
};

int N, M;

int main() {
    cin >> N >> M;
    DisjointSet Ds (N);
    //
    for(int x, y; M; M--) {
        cin >> x >> y;
        x--, y--;
        //
        Ds.Union(x, y);
        //
        unordered_set<int> checked;
        multiset<int> cc_size;
        for(int i = 0; i < N; i++) {
            int R = Ds.getRoot(i);
            if(checked.find(R) == checked.end()) {
                checked.insert(R);
                cc_size.insert(Ds.__treesize[R]);
            }
        }
        for(int i : cc_size) printf("%d ", i);
        printf("\n");
    }
}
