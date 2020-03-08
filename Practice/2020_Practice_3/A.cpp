#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define EPS 1e-8
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;

int X[11001];
int Y[11001];

int dist(int a,int b){
	int xd = X[b]-X[a];
	int yd = Y[b]-Y[a];

	if (xd <= 0 && yd <= 0){
		return - (min(xd,yd));
	}else if (xd > 0 && yd <=0){
		return xd-yd;
	}else if (yd > 0 && xd <=0){
		return yd-xd;
	}else{
		return max(yd,xd);
	}
}

int main(){
	X[1] = 0;
	Y[1] = 0;
	int i = 2;

	// vector <int> G[10005];

	int dx,dy;
	for(int layer=1; i<10001; ++layer){

		int x = -layer;
		int y = -layer;
		for(int side=0; side<6; ++side){
			switch(side){
				case 0:
					dx = 0;
					dy = 1;
					break;
				case 1:
					dx = 1;
					dy = 1;
					break;
				case 2:
					dx = 1;
					dy = 0;
					break;
				case 3:
					dx = 0;
					dy = -1;
					break;
				case 4:
					dx = -1;
					dy = -1;
					break;
				case 5:
					dx = -1;
					dy = 0;
					break;
			}
			for(int n=0; n<layer; ++n){
				x += dx;
				y += dy;
				if (y + x >= 0){
					X[i] = x;
					Y[i] = y;
					i++;
				}
				
			}
		}
	}
	

	// Make connections! :D

	int a, b;
	while(true){
		cin >> a >> b;
		if (a==0 && b==0){
			break;
		}
		printf("%d\r\n", dist(a,b));
	}

}











