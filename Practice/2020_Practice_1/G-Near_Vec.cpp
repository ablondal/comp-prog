#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#define double long double
using namespace std;
/*
	 |
   2 | 1
-----|-----
*/

typedef struct Vec2{
	double x, y;
	Vec2():x(0),y(0){}
} vec2;

vec2 vecs[100001];

void normalize(vec2 &v){
	double m = sqrt(v.x*v.x + v.y*v.y);
	assert(m!=0);
	v.x /= m;
	v.y /= m;
}

int quad(const vec2 &v){
	if (v.x>=0 && v.y>=0){
		return 1;
	}else if (v.y >= 0){
		return 2;
	}else if (v.x < 0){
		return 3;
	}else{
		return 4;
	}
}

bool vec_cmp(const vec2 &v, const vec2 &w){
	int qv=quad(v);
	int qw=quad(w);
	if(qv<qw) return true;
	else if(qw<qv) return false;
	if (qv==1 || qv==2) return v.x > w.x;
	else return v.x < w.x;
}

bool ind_cmp(const int &a, const int &b){
	//cout << a << " " << b << endl;
	if( a < 0 || b < 0 || a > 100000 || b > 100000 ){
		cout << a << " " << b << endl;
		return false;
	}
	bool res = vec_cmp(vecs[a],vecs[b]);
	
	return res;
}

double dot(vec2 &a, vec2 &b){
	return a.x*b.x + a.y*b.y;
}

int main(){
	int N;
	cin >> N;

	for(int i=0; i<N; ++i){
		cin >> vecs[i].x >> vecs[i].y;
		normalize( vecs[i] );
	}
	vector <int> index(N,0);
	for(int i=0; i<N; ++i){
		index[i]=i;
	}


	//cout << "Sorting" << endl;
	sort(index.begin(), index.end(), ind_cmp);
	
	/*for(int i=0; i<N; ++i){
		cout << vecs[index[i]].x << vecs[index[i]].y << endl;
	}*/
	/*
	for(int i=0; i<index.size(); ++i){
		cout << index[i] << endl;
	}*/

	//cout << "Testing" << endl;
	int best_i = 0;
	double best_dot = -2;
	double new_dot;
	for(int i=0; i<N; ++i){
		new_dot = dot( vecs[index[i]], vecs[index[ (i+1)%N ]] );
		if ( new_dot > best_dot ){
			best_i = i;
			best_dot = new_dot;
		}
	}

	cout << index[best_i]+1 << " " << index[ (best_i+1)%N ]+1 << endl;
}


