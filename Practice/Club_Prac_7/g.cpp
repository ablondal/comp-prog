#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define max(a, b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fori(i, n) for(int i=0; i<n; ++i)
typedef long long ll;

int T;
int main(){
	scanf("%d", &T);
	while(T--){
		double w, g, h, r;
		scanf("%lf%lf%lf%lf", &w, &g, &h, &r);
		g -= r;
		h -= r;
		if (h==0 || g==0){
			double l = sqrt((h+g)*(h+g) + w*w);
			printf("%0.8lf %0.8lf\n", l, l);
			continue;
		}
		double gh = g / h;
		double x1 = gh * (w / (1+gh));
		double x2 = w-x1;
		double l = sqrt((h-g)*(h-g) + w*w);
		double L = sqrt(h*h+x2*x2) + sqrt(g*g+x1*x1);
		printf("%0.8lf %0.8lf\n", l, L);
	}
}















