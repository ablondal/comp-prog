#include <iostream>
#include <cmath>
using namespace std;

void printmaxdivs(int x1, int x2, int divs[], int siz){
	int msiz = 0;
	int mi = 0;
	for(int i=0; i<siz; ++i){
		if (divs[i] > msiz)
		{
			msiz = divs[i];
			mi = i;
		}
	}
	cout << "Between " << x1 << " and " << x2 << ", " << mi+x1 << " has a maximum of " << msiz << " divisors." << endl;
}

int main(){
	int N, x1, x2, siz;
	int sTX, sT;
	for(cin >> N; N>0; --N){
		cin >> x1 >> x2;
		siz = x2 - x1 + 1;
		int divs[siz];
		for(int i=0; i < siz ; ++i){
			divs[i]=2;
			if(x1 == 1 && i==0) divs[i]--;
		}
		//printmaxdivs(x1, x2, divs, siz);
		for(int n = 2; n <= sqrt(x2)+1; ++n){
			//sTX = n*n;
			//if(sTX < x1){ sT = 0; sTX = x1; }
			//else {sT = sTX - x1; } // If is a sqrt
			sT = 0;
			sTX = x1;
			for ( int i = sT + (n - (sTX%n))%n; i<siz; i += n){
				divs[i]+=2;
				if (n*n == x1+i) divs[i] -=1;
				else if (n*n > x1+i) divs[i] -=2;
				//cout << i+x1 << " is divisible by " << n << endl;
			}
		}
		printmaxdivs(x1, x2, divs, siz);
	}
}