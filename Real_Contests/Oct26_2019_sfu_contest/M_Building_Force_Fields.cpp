#include <iostream>
#include <cmath>
#include <stack>
#include <cstdio>
using namespace std;

long double pre[1000][1000] = {0};
long double DP[1001] = {0};

typedef struct pt{
	int x;
	int y;
	pt(int xx, int yy):x(xx), y(yy){}
	pt():x(0), y(0){}
	pt operator=(pt a){
		x = a.x;
		y = a.y;
		return a;
	}
}pt;

pt operator-(pt a, pt b){
	//cout << "trying" << endl;
	return pt(a.x-b.x, a.y-b.y);
}

long long dot(pt a, pt b)
{
	return a.x*b.x + a.y*b.y;
}

int cross(pt &a, pt &b, pt &c)
{
	pt ba = b - a;
	pt ca = c - a;
	double cro = (ca.x*ba.y) - (ca.y*ba.x);
	if(cro<0) return -1;
	else if(cro>0) return 1;
	return 0;
}

long double dist(pt &a, pt &b)
{
	return sqrt( dot(b-a, b-a) );
}

pt pts[1000];
int N;

void calcpre()
{
	int HULL[1000];
	int top = -1;
	pt I, J;
	for(int i=0; i<N-1; ++i){
		pre[i][i] = 0;
		I = pts[i];
		top = -1;
		HULL[++top] = i;
		for(int j=i+1; j<N; ++j){
			J = pts[j];
			while(top > 0 && cross( pts[HULL[top-1]], pts[HULL[top]], J) == -1)
			{
				top--;
			}
			pre[i][j] = pre[i][HULL[top]] + dist( pts[HULL[top]], J );
			HULL[++top] = j;
		}
	}
}

long double getDP()
{
	DP[N] = 0;
	for(int i = N-2; i>=0; --i){
		for(int j = i+1; j<N; ++j){
			if(DP[i] > pre[i][j] + DP[j+1])
			{
				DP[i] = pre[i][j] + DP[j+1];
			}
		}
	}
	return DP[0];
}

int main(){
	int T;
	for(cin >> T; T>0; --T){
		cin >> N;
		for(int i=0; i<N; ++i){
			cin >> pts[i].x >> pts[i].y;
		}
		calcpre();
		/*for(int i=0; i<N-1; ++i){
			for(int j=i; j<N; ++j){
				cout << pre[i][j] << " ";
			}
			cout << endl;
		}*/
		for(int i=0; i<N; ++i){
			DP[i] = 10e12;
		}

		printf("%.6Lf\n",getDP());
		/*for(int i=0; i<N; ++i){
			cout << DP[i] << endl;
		}*/
	}
}


























