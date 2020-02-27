#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector> 
#define double long double
using namespace std;

const double PI = acos(-1.0);

/*
	 |
   2 | 1
-----|-----


*/

// Done, works! :D

typedef struct Vec2{
	double x, y;
	Vec2():x(0),y(0){}
} vec2;

vec2 vecs[100001];

double angle_sub[100001];


void normalize(vec2 &v){
	double m = sqrt(v.x*v.x + v.y*v.y);
	if (m==0) cout << "help" << endl;
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

double calc_angle_sub(vec2 &a){
	int q = quad( a );
	if(a.x==0){
		if(a.y>0) return PI/2.0;
		else return 3.0*PI/2.0;
	}else if(a.y==0){
		if(a.x>0) return 0;
		else return PI;
	}else if( q==1 ){
		return atan(a.y/a.x);
	}else if( q==2 ){
		return (PI) - atan(-a.y/a.x);
	}else if( q==3 ){
		return (PI) + atan(a.y/a.x);
	}else{
		return (2*PI) - atan(-a.y/a.x);
	}
}

bool ind_cmp(const int &a, const int &b){

	bool res = angle_sub[a] < angle_sub[b];
	
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
		angle_sub[i] = calc_angle_sub( vecs[i] );
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
	int best_j = 0;
	double best_angle_diff = 2*PI;
	double new_angle;
	for(int i=0; i<N; ++i){
		new_angle = (angle_sub[ index[ (i+1)%N ] ] - angle_sub[ index[i] ]);
		if(new_angle<0) new_angle+=2*PI;
		if(new_angle<best_angle_diff){
			best_angle_diff = new_angle;
			best_i = i;
		}
	}

	/*for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			new_dot = dot( vecs[i], vecs[j] );
			if ( new_dot > best_dot ){
				best_i = i;
				best_j = j;
				best_dot = new_dot;
			}
		}
	}*/

	//best_j = 
	cout << index[best_i]+1 << " " << index[ (best_i+1)%N ]+1 << endl;
	//cout << best_i+1 << " " << best_j+1 << endl;
}


