#include <bits/stdc++.h>
using namespace std;

struct Point{
	long long x;
	long long y;
};

Point p[100002];
int n;

long long answer;

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &p[i].x, &p[i].y);
	}
}

void setAnchorPoint(){
	int imin = 0;
	for(int i = 1; i < n; i++){
		if(p[i].x == p[imin].x){
			if(p[i].y < p[imin].x){
				imin = i;
			}
		}
		if(p[i].x < p[imin].x){
			imin = i;
		}
	}
	//
	swap(p[0], p[imin]);
}

int ccw(Point anc, Point a, Point b){
	int d = (a.x - anc.x)*(b.y - anc.y) - (a.y - anc.y)*(b.x - anc.x);
	if(d > 0) return 0;
	else return 1;
}

int cmp(Point a, Point b){
	Point anc = p[0];
	int ba = 1, bb = 1;
	if(anc.x > a.x){
		ba = -1;
	}
	if(anc.x > b.x){
		bb = -1;
	}
	//
	if(a.x - anc.x == 0){
		return 0;
	}
	if(b.x - anc.x == 0){
		return 1;
	}
	double tan1 = 1.0*(a.y - anc.y)/(a.x - anc.x);
	double tan2 = 1.0*(b.y - anc.y)/(b.x - anc.x);
	//
	if(tan1 == 0) return 1;
	if(tan2 == 0) return 0;
	return ba*atan( tan1 ) < bb*atan( tan2 );
}

long long sqDistance(Point a, Point b){
	int xx = abs(a.x - b.x);
	int yy = abs(a.y - b.y);
	return xx*xx + yy*yy;
}

long long getLength(vector<Point> cv){
	int i = 0;
	int j = 0;
	int maxj = 0;
	long long maxd;
	long long d;
	//
	while(i < cv.size()){
		j = maxj;
		while(j < cv.size()){
			d = sqDistance(cv[i], cv[j]);
			if(answer < d){
				answer = d;
				maxj = j;
			}
			j++;
		}
		i++;
	}
}

void graham(){
	vector<Point> cvhull;
	cvhull.push_back(p[0]);
	cvhull.push_back(p[1]);
	p[n] = p[0];
	//
	int i = 2;
	while(i < n){
		Point top  = cvhull[ cvhull.size() - 1 ];
		Point ptop = cvhull[ cvhull.size() - 2 ];
		//
		if(!ccw(ptop, top, p[i])){
			cvhull.push_back( p[i] );
			i++;
		}
		else{
			cvhull.erase(cvhull.end()-1);
		}
	}
	cout << getLength(cvhull);
}

int main(){
	input();
	setAnchorPoint();
	sort(p+1, p + n, cmp);
	// for(int i = 0; i < n; i++){
	// 	cout << p[i].x << ' ' << p[i].y << endl;
	// }
	//
	graham();
}